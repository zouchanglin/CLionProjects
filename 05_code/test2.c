#include <unistd.h>
#include <stdio.h>
#include <error.h>

int main()
{
	int id = 0;

	//获取当前进程的进程ID和父进程
	printf("pid:%d ppid=%d\n",getpid(),getppid());

	//开辟子进程
	id = fork();
	if(id < 0){
		perror("fork failed\n");
		return -1;
	}
	else if( id == 0){
		printf("Child,id = %d, ppid = %d\n", getpid(), getppid());
	}
	else{
		printf("Parent,id = %d, ppid = %d\n",getpid(), getppid());
	}
	return 0;
}
