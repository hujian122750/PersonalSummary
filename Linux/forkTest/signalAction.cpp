#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void catch_Signal(int signo)
{
    switch (signo)
    {
    case SIGINT:
        printf("SIGINT signal\n");
        break;
    default:
        break;
    }
}

//改进的信号捕捉方式
int signal1(int signo,void (*func)(int))
{
    struct sigaction act,oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    return sigaction(signo,&act,&oact);
}

int mainsigaction(int arg,char *args[])
{
    signal1(SIGINT,catch_Signal);
    pause();
    return 0;
}
