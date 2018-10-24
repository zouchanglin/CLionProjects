#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define FIFONAME "mypipe"


int main(){
  mkfifo(FIFONAME, 0644);
  int fd = open(FIFONAME, O_WRONLY);
  if(fd < 0){
    return 1;
  }

  char buf[1024];
  while(1){
    printf("Please Enter Your Message To Server# ");
    fflush(stdout);
    ssize_t s = read(0, buf,sizeof(buf)-1);
    buf[s-1] = 0;
    write(fd, buf, strlen(buf));
  }
  return 0;
}
