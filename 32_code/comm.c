#include "comm.h"

static int CommGetMsgQueue(int flag){
    key_t k = ftok(PATHNAME, PROJID);//失败返回-1
    if(k < 0){
        perror("ftok error");
        return -1;
    }

    int msgid = msgget(k, flag);

    if(msgid < 0){
        perror("msgget error");
    }
    return msgid;
}

//创建消息队列
int CreateMsgQueue(){
    return CommGetMsgQueue(IPC_CREAT|IPC_EXCL|0666);//附加权限
}

//打开消息队列
int OpenMsgQueue(){
    return CommGetMsgQueue(IPC_CREAT);
}

//发送消息
void SendMsg(int msgid, char msg[], int type){
    //准备要发出的数据
    struct msgbuf s_msg;
    s_msg.mtype = type;
    strcpy(s_msg.mtext, msg);

    if(msgsnd(msgid, (void*)&s_msg, sizeof(s_msg.mtext), 0) < 0){
        printf("msgsend error");
    }
}

//接受消息
void RecvMsg(int msgid, char msg[], int type){
    struct msgbuf _msg;
    //读取消息到_msg中
    if(msgrcv(msgid, (void*)&_msg, sizeof(_msg.mtext),type, 0) > 0){
        //把数据传出去
        strcpy(msg, _msg.mtext);
    }
}


//删除消息队列
void DestroyMsgQueue(int msgid){
    msgctl(msgid, IPC_RMID, NULL);
}