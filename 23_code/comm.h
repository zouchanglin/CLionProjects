#ifndef _COMM_H__
#define _COMM_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <error.h>
#include <string.h>
#include <unistd.h>


#define PATHNAME "/tmp"
#define PROJID 0x6666
#define SERVER_TYPE 1
#define CLIENT_TYPE 2

struct msgbuf{
  long mtype;
  char mtext[64];
};

int CreateMsgQueue();
int OpenMsgQueue();
void DestoryMsgQueue(int msgid);

void SendMsg(int msgid,char msg[],int type);
void RecvMsg(int msgid, char msg[], int type);


#endif //!_COMM_H__
