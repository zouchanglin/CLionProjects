#include <stdio.h>
#include <signal.h>

int flag = 0;

//volatile int flag = 0;
void handler(int singo)
{
  flag = 1;
  printf("chage flag to 1\n");
}

int main()
{
  signal(2, handler);
  while(!flag);
  printf("proc done ...\n");
  return 0;
}
