#include <iostream>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[])
{
	pid_t id = fork();
	if (id == 0)
	{
		cout << "ZZZZ" << endl;	
	}
	else if (id < 0)
	{
		cout << "Error" << endl;
	}
	else
	{
		cout << "FFFF" << endl;
	}
	
	for (int i = 0; i < 10; i++)
	{
		cout << "helloworld: " << i  << endl;
	}
	return 0;
}