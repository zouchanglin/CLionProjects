/***********************************************
#      Filename: test.c
#        Author: Tim 15291418231@163.com
#   Description: ---
#        Create: 2018-10-02 18:44:47
# Last Modified: 2018-10-02 18:44:47
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int g_val = 0;

int main(int argc, char *argv[]){
	pid_t id = fork();
	if(id < 0){
		perror("fork failed");
		return 0;
	}	
	else if(id == 0){
		g_val = 100;
		printf("child[%d],val[%d],address[%p]\n", getpid(), g_val, &g_val);
	}else{
		sleep(3);
		printf("parent[%d],val[%d],address[%p]\n", getpid(), g_val, &g_val);
	}
	
	sleep(1);

	return 0;
}

