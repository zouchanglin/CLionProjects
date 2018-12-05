#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFONAME "mypipe"

int main(){
  
  mkfifo(FIFONAME, 0664);
  int fd = open(FIFONAME, O_RDONLY);

  return 0;
}
