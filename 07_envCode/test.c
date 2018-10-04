#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main01()
{
	extern char **environ;
	int i = 0;
	for(; environ[i]; i++)
	{
		
		printf("%s\n",environ[i]);
	}

	while(1);

	return 0;
}
