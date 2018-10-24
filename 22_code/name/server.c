#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define FIFONAME "mypipe"


int main(){
  mkfifo(FIFONAME, 0644);
  int fd = open(FIFONAME, O_RDONLY);
  if(fd < 0){
    return 1;
  }

  char buf[1024];
  while(1){
    ssize_t s = read(fd, buf, sizeof(buf)-1);
    if(s > 0){
      buf[s] = 0;
      printf("client# %s\n", buf);
    }else if(s == 0){
      printf("client quit, server quit too!\n"); 
      break;
    }else{
      break;
    }
  }
  return 0;
}
