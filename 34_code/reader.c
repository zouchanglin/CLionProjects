#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    key_t k = ftok(".", 0x7777);//.表示当前目录

    if(k < 0){
        printf("ftok error\n");
        return 1;
    }

    //申请共享内存
    int shmid = shmget(k, 4096,IPC_CREAT);

    if(shmid < 0){
        printf("shmget error\n");
    }

    //绑定共享内存
    char *buf = shmat(shmid, NULL, 0);
    if(buf == NULL){
        printf("shmar error\n");
    }

    while(1){
        sleep(1);
        printf("%s\n", buf);
    }


    //取消绑定共享内存
    shmdt(shmid);
    return 0;
}