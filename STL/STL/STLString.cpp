//
//  main.cpp
//  STL
//
//  Created by 胡健 on 15/10/6.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
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
int stringExchange()
{
    string str = "stl string";
//    将string字符串转化为指针
    const char *pStr = str.c_str();
    printf("str = %s\n",pStr);
//    将string字符串拷贝到字符数组中
    char buf[64];
    memset(buf, 0, sizeof(buf));
    str.copy(buf, str.length()-4,4);
    printf("buf = %s\n",buf);
    return 0;
}
//字符串的连接
int stringLink()
{
    string str1 = "STL ";
    string str2 = "String1";
    str1 = str1 + str2;
    cout<<"str1 = "<<str1<<endl;
    string str3 = "stl";
    string str4 = "string3";
    str3.append(str4);
    cout<<"str3 ="<<str3<<endl;
    return 0;
}
//字符串的查找及替换
int stringFindAndReplace()
{
    string str = "what is stl? stl is standard template library!";
//    查找what第一次出现的下标
    long index1 = str.find("what",0);
    cout<<"index1 = "<<index1<<endl;
//    查找 is 出现的次数以及每次出现的下标
    long index = str.find("is",0);
    int nums = 0;
    while(index != string::npos)
    {
        cout<<"index = "<<index<<endl;
        nums = nums + 1;
        index = index + 1;
        index = str.find("is",index);
    }
    cout<<"nums = "<<nums<<endl;
//    将字符串中stl替换成STL
    long indexAdv = str.find("stl",0);
    while(indexAdv != string::npos)
    {
        str.replace(indexAdv,3,"STL");
        indexAdv = indexAdv + 1;
        indexAdv = str.find("stl",indexAdv);
    }
    cout<<"str = "<<str<<endl;

    return 0;
}
//字符串的删除及插入
int stringDeleteAndInsert()
{
    string str = "stl string,string delete and string insert";
    long indexAdv = str.find("string",0);
    while(indexAdv != string::npos)
    {
        str.erase(indexAdv,6);    //字符串的删除
        indexAdv = indexAdv + 1;
        indexAdv = str.find("string",indexAdv);
    }
    cout<<"str = "<<str<<endl;
    str.insert(0,"hello ");
    cout<<"str = "<<str<<endl;
    return 0;
}
int to_upper(int c)
{
    if (islower(c))
    {
        return (c-32);
    }
    
    return c;
}
/*////////////////////////////////
 template < class InputIterator, class OutputIterator, class UnaryOperator >
 OutputIterator transform ( InputIterator first1,  // 源容器的起始地址
 InputIterator last1,    // 源容器的终止地址
 OutputIterator result,  // 目标容器的起始地址
 UnaryOperator op );     // 函数指针
 // typedef 目标容器元素类型 (*UnaryOperator)(源容器元素类型);
 
 template < class InputIterator1, class InputIterator2,
 class OutputIterator, class BinaryOperator >
 OutputIterator transform ( InputIterator1 first1,     // 源容器1的起始地址
 InputIterator1 last1,       // 源容器1的终止地址
 InputIterator2 first2,      // 源容器2的起始地址，元素个数与1相同
 OutputIterator result,      // 目标容器的起始地址，元素个数与1相同
 BinaryOperator binary_op ); // 函数指针
 // typedef 目标容器元素类型 (*BinaryOperator)(源容器1元素类型，源容器2元素类型);*/
int stringAlgorithm()
{
    string str = "STL Standard Template Libray";
//    函数的入口地址
    transform(str.begin(), str.end(), str.begin(), to_upper);
    cout<<"str = "<<str<<endl;
    return 0;
}
int mainString(int argc, const char * argv[])
{
    int rv = 0;
//    rv = stringInit();
//    rv = stringErgodic();
//    rv = stringExchange();
//    rv = stringLink();
//    rv = stringFindAndReplace();
//    rv = stringDeleteAndInsert();
    rv = stringAlgorithm();

    cout<<"*****STL String*****"<<endl;
    return 0;
}
