#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
	printf("%s\n", getenv("PATH"));
	return 0;
}
int main()
{
	extern char **environ;
	int i = 0;
	for(; environ[i]; i++)
	{
		printf("%s\n",environ[i]);
	}
	return 0;
}

int main(int argc, char *argv[], char *env[])
{
	int i = 0;
	for(i = 0; env[i]; i++)
	{
		printf("%s\n",env[i]);	
	}
	return 0;
}
