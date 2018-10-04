#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <stdlib.h>

int main()
{
	int pid = fork();
	if(pid<0)
	{
		perror("fork failed..");
		return 0;
	}
	else if(pid == 0)
	{
		printf("child is begin pid = %d\n",getpid());
		sleep(5);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("parent is sleeping pid = %d",getpid());
		sleep(30);
	}

	return 0;
}

