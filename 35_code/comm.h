#ifndef INC_32_CODE_COMM_H
#define INC_32_CODE_COMM_H

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <memory.h>
#include <unistd.h>



#define PATHNAME "/tmp"
#define PROJID 0x6666

#define SERVER_TYPE 1
#define CLIENT_TYPE 2

struct msgbuf{
    long mtype;
    char mtext[256];
};

//创建消息队列
int CreateMsgQueue();

//打开消息队列
int OpenMsgQueue();

//删除消息队列
void DestroyMsgQueue(int msgid);

//发送消息
void SendMsg(int msgid, char msg[], int type);

//接受消息
void RecvMsg(int msgid, char msg[], int type);



#endif //INC_32_CODE_COMM_H
