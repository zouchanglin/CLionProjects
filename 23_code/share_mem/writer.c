#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>


int main(){
  key_t k = ftok(".", 0x7777);
  if(k < 0){
    printf("ftok error\n");
      return 1;
  }

  int shmid = shmget(k, 4096, IPC_CREAT | IPC_EXCL | 0666);
  if(shmid < 0){
    printf("shmget error\n");
  }

  //删除共享内存
  //shmctl(shmid, IPC_RMID, NULL);
  return 0;
}
