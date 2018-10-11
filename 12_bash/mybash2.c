#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX 1024
#define NUM 16

int main(){
  while(1){
    char cmd[MAX] = {0};
    char *ret = NULL;
    char *myargv[8] = {NULL};
    int i = 0;
    printf("[tim@localhost mybash]#\n");
    fgets(cmd, MAX, stdin);
    for(ret = strtok(cmd, " "); ret != NULL; ret=strtok(NULL, " ")){
      //printf("%s\n", ret);
      myargv[i] = (char*)malloc(strlen(ret)+1);
      strcpy(myargv[i], ret);
     //printf("%s\n",myargv[i]);
      i++;
    }

    pid_t id = fork();
    if(id < 0){
      perror("fork error...");
      exit(EXIT_FAILURE);
    }else if(id == 0){
      int i = 0;
      while(myargv[i++] != NULL){
        printf("%s\n", myargv[i]);
      }
      myargv[i-1] = NULL;
      execvp(myargv[0], myargv);
    }else{
      int status = 0;
      while(wait(&status) != id);
    }
  }
  return 0;
}
