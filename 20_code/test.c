#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
  mkfifo("p2", 0664); 
  return 0;
}
