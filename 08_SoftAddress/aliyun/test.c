/***********************************************
#      Filename: test.c
#        Author: Tim 15291418231@163.com
#   Description: ---
#        Create: 2018-10-02 22:27:15
# Last Modified: 2018-10-02 22:27:15
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	pid_t pid = fork();
	if(pid == 0){
		printf("child is run, pid is %d\n", getpid());
		sleep(5);
		exit(27);
	}else{
		int status = 0;
		pid_t ret = waitpid(-1,&status,0);//阻塞式等待5s
		printf("this is test forwait\n");
		if(WIFEXITED(status) && ret == pid){
			printf("wait child 5s success,child return code is %d\n",WEXITSTATUS(status));
		}else{
			printf("wait child failed,return .\n");
			return 1;
		}
	}

	return 0;
}

