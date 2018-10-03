/***********************************************
#      Filename: test.c
#        Author: Tim 15291418231@163.com
#   Description: ---
#        Create: 2018-10-02 22:15:04
# Last Modified: 2018-10-02 22:15:04
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	pid_t pid = fork();
	if(pid < 0){
		printf("fork error");
		exit(1);
	}else if(pid == 0){
		sleep(20);
		exit(10);
	}else{
		int st = 0;
		int ret = wait(&st);
		
		if(ret>0 && (st & 0X7F)==0){//正常退出
			printf("child exit code: %d\n",(st>>8&0XFF));
		}else if(ret > 0){//异常退出
			printf("sig code: %d\n",st&0X7F);
		}
	}

	return 0;
}
