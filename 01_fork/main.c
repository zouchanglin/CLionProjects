#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    pid_t ret = fork();
    if(ret<0) {
        printf("error\n");
    } else if(ret == 0){
        while (1){
            printf("child: pid=%d ppid=%d\n",getpid(),getppid());
            sleep(1);
        }
    } else{
        while(1){
            printf("parent: pid=%d ppid=%d\n",getpid(),getppid());
            sleep(4);
        }
    }

    return 0;
}