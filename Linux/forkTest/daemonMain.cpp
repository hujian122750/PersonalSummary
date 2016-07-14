#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<time.h>

//创建守护进程总结:
/*
 * 父进程中执行fork后，执行exit退出；
 * 在子进程中调用setsid；
 * 让根目录“／”成为子进程的工作目录；
 * 把子进程的umask变为0；
 * 关闭从父进程继承出来不需要的文件描述符
 */

void writelog(const char* log)
{
    time_t tDate;
    struct tm *eventTime;
    time(&tDate);
    eventTime = localtime(&tDate);
    int iYear = eventTime->tm_year + 1900;
    int iMon = eventTime->tm_mon + 1;
    int iDay = eventTime->tm_mday;
    int iHour = eventTime->tm_hour;
    int iMin = eventTime->tm_min;
    int iSec = eventTime->tm_sec;
    char sDate[16] = {0};
    sprintf(sDate,"%04d-%02d-%02d",iYear,iMon,iDay);
    char sTime[16] = {0};
    sprintf(sTime,"%04d-%02d-%02d",iHour,iMin,iSec);
    char s[1024] = {0};
    sprintf(s,"%s %s %s\n",sDate,sTime,log);
    FILE *fd = fopen("my.log","a+");
    fputs(s,fd);
    fclose(fd);


}

void setdaemon()
{
    pid_t pid,sid;
    pid = fork();
    if(pid < 0)
    {
        printf("fork failed\n");
        exit(EXIT_FAILURE);
    }
    if(pid > 0)
    {
        exit(EXIT_SUCCESS);
    }
    writelog("begin");
    if((sid = setsid()) < 0)
    {
        printf("setsid failed\n");
        exit(EXIT_FAILURE);
    }
//    if(chdir("/") < 0)
//    {
//        printf("chdir failed\n");
//        exit(EXIT_FAILURE);
//    }
    umask(0);
    //关闭不必要的输入输出
    close(STDOUT_FILENO);
    close(STDIN_FILENO);
    close(STDERR_FILENO);
    const char *str = "daemon process";
    while(1)
    {
        writelog(str);
        sleep(1);
    }
}


int main()
{
    setdaemon();
    printf("*********daemon process************\n");
    return 0;
}

//如何linux启动时自动启动一个守护进程
//把启动命令放到/etc/rc.d/rc.local文件就可以每次启动时候自动启动服务
