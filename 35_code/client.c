#include "comm.h"

int main(){

    int msgid = OpenMsgQueue();

    //接收其他进程（server）发的消息
    char msg[256];
    while(1){
        RecvMsg(msgid,msg,SERVER_TYPE);
        printf("RECV = %s\n", msg);
        sleep(1);
    }
    return 0;
}