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

int main(int arg, char *args[])
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
