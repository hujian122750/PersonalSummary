//
//  main.cpp
//  STL
//
//  Created by 胡健 on 15/10/6.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int stringInit()
{
//    四种初始化字符串的方法
    string str1 = "STL string1";
    string str2("STL string2");
    string str3 = str1;
    string str4(10,'s');
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;
    
    return 0;
}
//字符串的遍历
int stringErgodic()
{
    string str = "stl string ergodic";
//    数组方式遍历
    for(int i = 0; i < str.length(); i++)
    {
        cout<<str[i];
    }
    cout<<endl;
//    at遍历
//    与数组遍历的区别：在数组越界的时候会抛出异常，可通过catch捕捉到，但是
//    数组越界直接导致程序崩溃，try，catch捕捉不到
    for(int i = 0; i< str.length(); i++)
    {
        cout<<str.at(i);
    }
    cout<<endl;
//    迭代器遍历
    for(string::iterator it = str.begin(); it != str.end(); it++)
    {
        cout<<*it;
    }
    cout<<endl;
    return 0;
}
int main(int argc, const char * argv[])
{
    int rv = 0;
//    rv = stringInit();
    rv = stringErgodic();

    cout<<"*****STL String*****"<<endl;
    return 0;
}
