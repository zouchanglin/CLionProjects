#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFONAME "mypipe"

int main() {
    //创建一个命名管道
    mkfifo(FIFONAME, 0664);

    //打开这个命名管道
    int fd = open(FIFONAME, O_RDONLY);

    if(fd < 0){
        return 1;
    }

    char buf[1024];
    while(1){
        ssize_t s = read(fd, buf, sizeof(buf)-1);
        if(s > 0){
            //读取成功
            buf[s] = 0;
            printf("client# %s\n", buf);
        }else if(s == 0){
            //写端把文件描述符关闭
            printf("client quit！server quit too!\n");
            break;
        }else{
            break;
        }

    }
    return 0;
}


