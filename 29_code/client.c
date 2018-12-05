#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>

#define FIFONAME "mypipe"

int main() {
      //创建一个命名管道
      //    mkfifo(FIFONAME, 0664);
      //
      //        //打开这个命名管道
      //            int fd = open(FIFONAME, O_WRONLY);
      //
      //                if(fd < 0){
      //                        return 1;
      //                            }
      //
      //                                char buf[1024];
      //                                    while(1){
      //                                            printf("Please Enter Your Message To Server# ");
      //                                                    fflush(stdout);
      //                                                            //从标准输入读取信息
      //                                                                    ssize_t s = read(0,buf,sizeof(buf));
      //                                                                            buf[s-1] = 0;//覆盖掉之前的回车换行
      //
      //                                                                                    //向管道写
      //                                                                                            write(fd,buf,strlen(buf));
      //                                                                                                }
      //                                                                                                    close(fd);
      //                                                                                                        return 0;
      //                                                                                                        }
      //                                    }
      //                }
}
