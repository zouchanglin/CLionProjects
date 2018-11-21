#include "comm.h"

int main(){
    int msgid = CreateMsgQueue();
    printf("msgid = %d\n",msgid);

    while(1){
        //发送消息到消息队列
        SendMsg(msgid, "hello,xpu", SERVER_TYPE);
        sleep(1);
    }

    SendMsg(msgid, "hello,xpu", SERVER_TYPE);
    sleep(1);
    SendMsg(msgid, "hello,xpu", SERVER_TYPE);
    sleep(1);
    SendMsg(msgid, "hello,xpu", SERVER_TYPE);
    sleep(1);
    SendMsg(msgid, "hello,xpu", SERVER_TYPE);
    sleep(1);
#if 0

    //自己接收自己发的消息
    char msg[256];
    RecvMsg(msgid,msg,SERVER_TYPE);
    printf("RECV = %s\n", msg);
    sleep(1);
    RecvMsg(msgid,msg,SERVER_TYPE);
    printf("RECV = %s\n", msg);
    sleep(1);
    RecvMsg(msgid,msg,SERVER_TYPE);
    printf("RECV = %s\n", msg);
    sleep(1);
    RecvMsg(msgid,msg,SERVER_TYPE);
    printf("RECV = %s\n", msg);
    sleep(1);
    RecvMsg(msgid,msg,SERVER_TYPE);
    printf("RECV = %s\n", msg);
    sleep(1);
#endif
    DestroyMsgQueue(msgid);
    return 0;
}