/*************************************************************************
	> File Name: main.c
	> Author: Tim
	> Mail: 15291418231@163.com
	> Created Time: 2018年09月21日 星期五 03时23分51秒
 ************************************************************************/

#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    char buf[102] = {0};
    int i = 0;
    //注意这里需要使用转义字符
    char arr[4] = "/-|\\";
    for(i= 0;i<=100;i++)
    {
        buf[i] = '#';
        if(i<40)
            printf("[\033[0;31m%-100s\033[0;39m] [%d%%][%c]\r", buf,i,arr[i%4]);//进度条颜色修饰
        else if(i>=40 && i< 80)
            printf("[\033[0;33m%-100s\033[0;39m] [%d%%][%c]\r",buf,i,arr[i%4]);
        else
            printf("[\033[0;32m%-100s\033[0;39m] [%d%%][%c]\r",buf,i,arr[i%4]);

        //printf("[%-100s] [%d%%][%c]\r",buf,i,arr[i%4]);

        //printf是按行缓冲的，所以需要刷新缓冲区
        fflush(stdout);
        //usleep的单位是微秒
        usleep(50000);
    }
    //最后需要换行
    printf("\n");
    return 0;
}