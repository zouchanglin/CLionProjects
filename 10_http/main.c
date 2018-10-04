#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <string.h>


//定义readLine的缓冲区大小
#define MAX 1024
#define MAIN_PAGE "index.html"

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

void echoError(int status_code){

}

int getLine(int sock, char line[], int len){
	char c = 'a';
	int i = 0;
	while(c != '\n' && i<len-1){
		ssize_t s = recv(sock, &c, 1, 0);	
        if(s > 0){
            if(c =='\r'){// \r \r\n \n ----> \n
                recv(sock, &c, 1, MSG_PEEK);
                if(c == '\n'){
                    recv(sock, &c, 1, 0);
                }else{
                    c = '\n';
                }
            }
            //printf("%c ",c);
	    	line[i++] = c;
        }else{
            break;
        }   
	}
	line[i] = '\0';
	return i;
}


//清理报头
void clearHeader(int sock){
    char line[MAX];
    do{
        getLine(sock,line,sizeof(line));
    }while(strcmp(line,"\n"));
}

//判断str1是否以str2结尾,如果是返回1, 不是返回0, 出错返回-1
int is_end_with(const char *str1, char *str2)
{
    if(str1 == NULL || str2 == NULL)
        return -1;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if((len1 < len2) ||  (len1 == 0 || len2 == 0))
        return -1;
    while(len2 >= 1){
        if(str2[len2 - 1] != str1[len1 - 1])
            return 0;
        len2--;
        len1--;    
    }
    return 1;
}

int echo_resource(int sock, char *path, int size){
    char line[MAX];
    clearHeader(sock);
    int fd = open(path, O_RDONLY);
    if(fd < 0){
        return 404;
    }
    sprintf(line, "HTTP/1.0 200 OK\r\n");
    send(sock, line, strlen(line), 0);


    //其他类型给出Content—Type即可
    if(is_end_with(path, ".css") == 1){
        sprintf(line, "Content-Type:text/css\r\n");
    }else if(is_end_with(path, ".js") == 1){
        sprintf(line, "Content-Type:application/x-javascript\r\n");
    }else if(is_end_with(path, ".png") == 1){
        sprintf(line, "Content-Type:image/png\r\n");
    }else{
        sprintf(line, "Content-Type:text/html;charset=utf-8\r\n");
    }

    send(sock, line, strlen(line), 0);

    sprintf(line, "Content-Length:%d\r\n",size);
    send(sock, line, strlen(line), 0);
    sprintf(line, "\r\n");
    send(sock, line, strlen(line), 0);

    sendfile(sock, fd, NULL, size);
    close(fd);
}


void *handlerRequest(void  *arg){
	printf("get a new client, thread create success...\n");
	int sock = (int)arg;
	//处理请求
	char line[MAX];
    char method[MAX/16];
    char url[MAX];
    char *query_string = NULL;
    char path[MAX];

    //定义状态码
    int status_code = 200;
    int cgi = 0;
    
    getLine(sock,line,MAX);

    int i = 0;
    int j = 0;
    while(i < sizeof(method)-1 && j<sizeof(line) && !isspace(line[j])){
        method[i] = line[j];
        i++;
        j++;
    }

    //printf("method:%s, url:%s\n", method, url);
    if(strcasecmp(method, "GET") == 0){
        
    }else if(strcasecmp(method, "POST") == 0){
        cgi = 1;
    }else{
        clearHeader(sock);
        status_code = 404;
        goto end;
    }

    i = 0;
    while(j< sizeof(line) && isspace(line[j])){
        j++;
    }

    while(i<sizeof(url)-1 && j< sizeof(line) && !isspace(line[j])){
        url[i] = line[j];
        i++;
        j++;
    }

    url[j] = '\0';

    //处理请求方法
    //GET POST Post post Get get 使用strcasecmp()忽略大小写
    method[i] = '\0';
    if(strcasecmp(method, "GET") == 0){
        //GET方法处理
        query_string = url;
        while(*query_string){
            if(*query_string == '?'){
                *query_string = '\0';
                query_string++;
                cgi = 1;
                break;
            }
            query_string++;
        }
        printf("method:%s, rul:%s, query_string:%s\n", method, url, query_string);
    
    }
    //medthod, url[path, query_string(GET)]
    sprintf(path, "wwwroot%s",url);
    //printf("method:%s, path:%s, query_string:%s\n", method, path, query_string);
    if(path[strlen(path)-1] == '/'){
        strcat(path, MAIN_PAGE);
    }
    printf("medthod :%s, url:%s, query_string:%s\n", method, path,  query_string);

    struct stat st;
    if(stat(path, &st) < 0){
        clearHeader(sock);
        status_code = 404;
        goto end;
    }else{
        if(S_ISDIR(st.st_mode)){
            strcat(path, "/");
            strcat(path, MAIN_PAGE);
        }else if((st.st_mode & S_IXUSR) || \
                (st.st_mode & S_IXGRP) || \
                (st.st_mode & S_IXOTH)){
                     cgi = 1;
                }else{
                //do something
        }
    }

    if(cgi){
        //exe_cgi();
    }else{
        status_code = echo_resource(sock, path, st.st_size);
    }
    

end:
    if(status_code != 200){
        //说明出错了
        //完善函数echError
        echoError(status_code);
    }
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
		pthread_create(&tid, NULL, handlerRequest, (void *)sock);

		//分离线程
		pthread_detach(tid);
		
	}
	return 0;
}
