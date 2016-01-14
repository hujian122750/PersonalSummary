#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
//理解函数指针
enum DIFF_FUNC_FLAG
{
    SIGNAL_PAUSE = 1,
    FUNC_POINT,
    SELF_SIGNAL_INT
};
int addTwoNums(int num1, int num2)
{
    return num1+num2;
}
int addTwoNumsAdv(int (*pFunc)(int,int),int a,int b)
{
    return pFunc(a,b);
}

void catch_signal(int sign)
{
    switch (sign)
    {
    case SIGINT:
        printf("The signal is SIGINT\n");
        break;
    default:
        break;
    }
}

int mainSignal(int arg, char *args[])
{
    int flag = -1;
    printf("Please enter flag:");
    scanf("%d",&flag);
    switch(flag)
    {
        case SIGNAL_PAUSE:
            printf("process start\n");
            pause();
            printf("process end\n");
            break;
        case FUNC_POINT:
//            int (*func)(int,int) = addTwoNums;
//            func = addTwoNums;
            printf("add two nums = %d\n",addTwoNumsAdv(addTwoNums,100,23));
            break;
        case SELF_SIGNAL_INT:
            signal(SIGINT,catch_signal);
//            pause();
            static int num = 0;
            while(1)
            {
                printf("%d\n",num++);
                sleep(1);
            }
            break;
    }
    return 0;
}
//由于signal自身缺陷，比如在发送信号的过程中再发送，有可能会有问题，所以最好用sigaction函数，参见signalaction.cpp


//kill函数将信号发送给进程，而raise函数允许进程向自身发送信号
//raise(signo) 等价于kill(getpid(),signo)
