#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//定义readLine的缓冲区大小
#define MAX 1024

static void usage(const char *proc)
{
	printf("Usage :%s port\n", proc);
}

int startup(int port){
	//创建Socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		perror("socket");
		exit(2);
	}
	
	int opt = 1;
	setsockopt(sock, SOL_SOCKET,SO_REUSEADDR, &opt,sizeof(opt));

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	local.sin_port = htons(port);

	//绑定
	if(bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0){
		perror("bind");
		exit(3);
	}

	if(listen(sock, 5) < 0){
		perror("listen");
		exit(4);
	}
	return sock;
}

int getLine(int sock, char line[], int len){
	char c = 'a';
	int i = 0;
	while(c != '\n' && i<len-1){
		ssize_t s = recv(sock, &c, 1, 0);		
		if(s > 0 && c =='\r'){// \r \r\n \n ----> \n
			recv(sock, &c, 1, MSG_PEEK);
			if(c == '\n'){
				recv(sock, &c, 1, 0);
			}else{
				c = '\n';
			}
		}else{
			break;
		}

		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

void *handlerRequest(void  *arg){
	printf("get a new client, thread create success...\n");
	int sock = (int)arg;
	//处理请求
	char line[MAX];	
	getLine(sock, line, sizeof(line));
	printf("%s",line);

	close(sock);
	return NULL;
}

//./httpd 8080
int main(int argc, char *argv[]){
	if(argc != 2){
		usage(argv[0]);
		return 1;
	}
	int listen_sock  = startup(atoi(argv[1]));
	for( ; ; ){
		struct sockaddr_in client;
		socklen_t len = sizeof(client);
		int sock = accept(listen_sock,(struct sockaddr*)&client, &len);
		if(sock < 0){
			perror("accept");
			continue;
		}

		//创建线程
		pthread_t tid;
		pthread_create(&tid, NULL, handlerRequest, (void *)tid);

		//分离线程
		pthread_detach(tid);
		
	}
	return 0;
}
