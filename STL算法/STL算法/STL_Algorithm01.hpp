//
//  STL_Algorithm01.hpp
//  STL算法
//
//  Created by 胡健 on 15/10/21.
//  Copyright © 2015年 胡健. All rights reserved.
//

#ifndef STL_Algorithm01_hpp
#define STL_Algorithm01_hpp

#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <set>

using namespace std;

template<typename T>
class Element
{
public:
    Element()
    {
        num = 0;
    }
    void operator()(const T & _t)
    {
        num++;
        cout<<_t<<endl;
    }
    void printNum()
    {
        cout<<"num = "<<num<<endl;
    }
public:
    T t;
protected:
private:
    int num;
};
template<typename T>
class Element2
{
public:
    Element2(const T & _t)
    {
        this->_t = _t;
    }
    bool operator()(const int & _a)
    {
        return (_a%_t == 0);
    }
protected:
private:
    T _t;
};

//函数对象：重载函数调用操作符的类，其对象常称为函数对象，即它们是行为类似函数的对象。
//一个类对象，表现出一个函数的特征，就是通过“对象名＋（参数列表）”方式使用
//一个类对象，即通过重载类的operator（）实现

//一元函数对象   函数参数1个
//二元函数对象   函数参数2个
//一元谓词      函数参数一个，函数返回值是bool类型  bool operator()(T & t)  find_if
//二元谓词      函数参数两个，函数返回值是bool类型

#endif /* STL_Algorithm01_hpp */
