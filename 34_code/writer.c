#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <memory.h>

int main() {
    key_t k = ftok(".", 0x7777);//.表示当前目录

    if(k < 0){
        printf("ftok error\n");
        return 1;
    }

    //申请共享内存
    int shmid = shmget(k, 4096,IPC_CREAT|IPC_EXCL|0666);

    if(shmid < 0){
        printf("shmget error\n");
    }

    //绑定共享内存
    char *buf = shmat(shmid, NULL, 0);
    if(buf == NULL){
        printf("shmar error\n");
    }

    int i =0;
    memset(buf, '\0', 4096);
    while(i < 26){
        sleep(1);
        buf[i] = 'A'+i;
        i++;
    }
    //取消绑定共享内存
    shmdt(shmid);

    //释放共享内存
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}