#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
  while(1){
    sleep(1);
    printf("I am a proc...pid: %d\n", getpid());
  }
}
