#include "comm.h"

static int CommGetMsgQueue(int flag){

  key_t k = ftok(PATHNAME, PROJID);
  if(k < 0){
   printf("ftok error\n"); 
   return -1;
  }
  
  int msgid = msgget(k, flag);
  if(msgid<0){
    printf("msgget error\n");
  }
  return msgid;
}

//创建消息队列
int CreateMsgQueue()
{
  return CommGetMsgQueue(IPC_CREAT | IPC_EXCL | 0666);
}


//打开消息队列
int OpenMsgQueue(){

  return CommGetMsgQueue(IPC_CREAT);
}

//删除消息队列
void DestoryMsgQueue(int msgid)
{
 msgctl(msgid, IPC_RMID, NULL);
}

void SendMsg(int msgid, char msg[], int type)
{
  //准备数据
  struct msgbuf _msg;
  _msg.mtype = type;
  strcpy(_msg.mtext, msg);
  
  //发送数据
  if(msgsnd(msgid, (void*)&_msg, sizeof(_msg.mtext), 0) < 0){
    printf("SendMsg  error!\n");
  }


}

//取出数据
void RecvMsg(int msgid, char msg[], int type){
  struct msgbuf _msg;
  if(msgrcv(msgid, &_msg, sizeof(_msg.mtext), type,0) > 0){
    strcpy(msg, _msg.mtext);
  }
  
}

