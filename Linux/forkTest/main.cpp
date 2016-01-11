//
//  多进程
//  Created by 胡健 on 16/01/11.
//  Copyright © 2016年 胡健. All rights reserved.
//
#include <iostream>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int forkTest()
{
    cout<<"process begin"<<endl;//只执行一次
    pid_t pchild = fork();
    //fork后父进程和子进程都会执行
    cout<<"process begin======"<<endl;
    if(pchild == -1)
    {
        cout<<"fork errors"<<endl;
        return -1;
    }
    if(pchild == 0)
    {
        cout<<"I am child"<<endl;
        for(int i = 0; i < 10; i++)
        {
           cout<<"child==="<<i<<endl;
           sleep(1);
           if(i == 9)
           {
//              _exit(0);
               return 0;
           }
        }
    }
    else
    {
        cout<<"I am parent,my child is"<<pchild<<endl;
        for(int i = 0; i < 10; i++)
        {
            cout<<"parent===-"<<i<<endl;
            sleep(1);
            if(i == 9)
            {
//               _exit(0);
                return 0;
            }
        }
    }
    sleep(100);
    cout<<"*******fork*********"<<endl;
    return 0;
}

int execTest()
{
    char * const args[] = {"/bin/ls","-l",NULL};
    execve("/bin/ls",args,NULL);
    //以下就不会执行了，因为内存都被ls进程占用
    cout<<"******exec*********"<<endl;
    return 0;
}
//僵死进程:父进程还未调用wait收集子进程的退出状态，子进程就退出了，虽然资源会被释放，但是进程表中依然存在此子进程
//孤儿进程:父进程还未调用wait收集子进程的退出状态，父进程就退出了，此时子进程就会称为孤儿进程，但同时init进程会成为
//        此子进程的父进程;

int waitTest()
{
    pid_t pchild = fork();
    int status = -1;
    if(pchild == -1)
    {
        cout<<"chreate errors"<<endl;
        return -1;
    }
    if(pchild == 0)
    {
        cout<<"child start"<<endl;
        for(int i = 0; i < 5; i++)
        {
           cout<<i<<endl;
           sleep(1);
        }
        cout<<"child end"<<endl;
        return 1000;
    }
    else
    {
        //_exit(0);如果父进程退出，子进程成为孤儿进程
        cout<<"parent start"<<endl;
        //wait(&status);//等待子进程结束父进程才继续往下执行
        waitpid(pchild,&status,0);//当父进程有多个子进程的时候可以指定等待哪个子进程
        //status就是子进程的退出码
        cout<<"child exit code is "<<WEXITSTATUS(status)<<endl;
        cout<<"parent end"<<endl;
        return 0;
    }

}


int main()
{
    int flag = -1;
    cin>>flag;
    switch(flag)
    {
        case 1:
            forkTest();
            //以下的父进程和子进程也都会执行
            cout<<"=========process=========="<<endl;
            break;
        case 2:
            execTest();
            break;
        case 3:
            waitTest();
            break;
    }

    return 0;
}
