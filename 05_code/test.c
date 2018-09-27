/* ***********************************************
Author :Tim
Email :15291418231@163.com
Created Time :2018年09月27日 星期四 18时47分36秒
File Name :test.c
************************************************ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	int pid = fork();
	if(pid < 0){
		perror("fork failed...");
		return -1;
	}else if(pid == 0){
		printf("child[%d], my parentid[%d]..\n", getpid(), getppid());
		sleep(5);
		printf("child[%d], my parentid[%d]..\n", getpid(), getppid());
	}
	else{
		printf("parent[%d]...\n", getpid());
		sleep(2);
		exit(0);	
	}
    return 0;
}
