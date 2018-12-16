#ifndef __COMM_H__
#define __COMM_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <wait.h>

#define PATHNAME "."
#define PROJ_ID 0x6666

union semun {
  int val; /* Value for SETVAL */
  struct semid_ds *buf; /* Buffer for IPC_STAT, IPC_SET */
  unsigned short *array; /* Array for GETALL, SETALL */
  struct seminfo *__buf; /* Buffer for IPC_INFO */
};

int createSemSet(int nums);

int initSem(int semid, int nums, int initVal);

int getSemSet(int nums);

int P(int semid, int who);

int V(int semid, int who);

int destorySemSet(int semid);

#endif //!__COMM_H__
