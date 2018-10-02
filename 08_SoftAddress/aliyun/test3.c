/***********************************************
#      Filename: test.c
#        Author: Tim 15291418231@163.com
#   Description: ---
#        Create: 2018-10-02 21:19:24
# Last Modified: 2018-10-02 21:19:24
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int g_val = 100;

int main(int argc, char *argv[]){
	pid_t pid = vfork();
	if(pid == 0){
		sleep(5);
		g_val = 200;
		printf("%d\n",g_val);
		exit(0);
	}else{
		printf("%d\n",g_val);
	}

	return 0;
}

