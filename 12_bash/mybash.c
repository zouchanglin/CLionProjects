#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX 1024
#define NUM 16

int main(){
  char cmd[MAX];
  char *myargv[NUM];
  int i = 0;
  char *ret = NULL;
  printf("[tim@localhost mybash]# ");
  //scanf("%s", cmd);
  fgets(cmd, sizeof(cmd), stdin);
  myargv[i++] = strtok(cmd, " ");

  while(ret = strtok(NULL, " ")){
    myargv[i++] = ret;
  }

  myargv[i] = NULL;
  
  

  return 0;
}
