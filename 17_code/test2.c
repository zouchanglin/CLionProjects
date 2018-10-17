#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  umask(0);
  int fd = open("myfile", O_WRONLY|O_CREAT, 0664);
  if(fd < 0){
    perror("open");
    return 1;
  }

  int count = 5;
  const char *msg = "hello bit!\n";
  int len = strlen(msg);

  while(count--){
   int ret =  write(fd, msg, len);
   printf("实际写入数据%d字节\n", ret);
  }

  close(fd);
  return 0;
}
