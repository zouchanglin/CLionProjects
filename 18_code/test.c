#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int fun(){
  int fd = open("myfile", O_RDONLY);
  if(fd < 0){
    perror("open");
    return 1;
  }

  printf("fd = %d\n", fd);
  close(fd);
  return 0;
}


int fun2(){
  close(0);
  int fd = open("myfile", O_RDONLY);
  if(fd < 0){
    perror("open");
    return 1;
  }

  printf("fd = %d\n", fd);
  close(fd);
  return 0;
}

int fun3(){
  close(1);
  int fd = open("myfile", O_WRONLY|O_CREAT, 00644);
  if(fd < 0){
    perror("open");
    return 1;
  }

  printf("fd = %d\n", fd);
  fflush(stdout);

  close(fd);
  exit(0);
}

int fun4(){
  close(0);
  int fd = open("myfile2", O_RDONLY);
  if(fd < 0){
    perror("open");
    return 1;
  }
  char buf[1024] = {0};
  scanf("%s", buf);
  printf("buf = %s\n", buf);
  return 0;
}

int main(){
  //fun(); 
  //fun2();
  //fun3();
  fun4();
  return 0;
}
