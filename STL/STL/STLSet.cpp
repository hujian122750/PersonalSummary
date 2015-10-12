//
//  STLSet.cpp
//  STL
//
//  Created by 胡健 on 15/10/10.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;
//1、set是一个集合容器，其中所包含的元素师唯一的，集合中的元素按照一定的
//顺序排列；元素插入过程是按顺序规则插入的，所以不能指定插入位置；
//2、set采用红黑树变体的数据结构，红黑树属于平衡二叉树。在插入和删除操作
//上比vector快；
//3、set不可直接存取元素（不支持at（）和［］操作符）；
//4、multiset与set的区别：set支持唯一键值对，每个元素值只能出线一次；而
//multiset中同一值可以出现多次；
//5、不可以直接修改set或者multiset容器中的元素值，因为该容器是自动排序的。
//如果希望修改一个元素值，必须先删除原来的元素，在插入新的元素
void printSet(set<int> & setTmp)
{
    for(set<int>::iterator it = setTmp.begin(); it != setTmp.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void printSet2(set<int,greater<int>> & setTmp)
{
    for(set<int,greater<int>>::iterator it = setTmp.begin(); it != setTmp.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int setDeal()
{
    set<int> set1;  // <==>  set<int,less<int>> set1;
//    此处涉及谓词的概念
//    谓词是一个返回bool类型的值的函数，因为函数对象是一种类型的对象，实现operator()()成员函数并返回bool类型的值，所以函数对象也是谓词。
    for(int i = 0; i < 10; i++)
    {
        set1.insert(rand());
    }
    set1.insert(100);
    set1.insert(100);
    set1.insert(100);//元素唯一，所以即使插入多次，也只有一个，且自动排序（默认从小到大）
    printSet(set1);
    
    while(!set1.empty())
    {
        set1.erase(set1.begin());
    }
    cout<<"======"<<set1.size()<<endl;
    
//    从大到小
    set<int,greater<int>> set2;
    for(int i = 0; i < 10; i++)
    {
        set2.insert(rand());
    }
    set2.insert(100);
    set2.insert(100);
    printSet2(set2);
    
    return 0;
}
//自定义数据类型=====>仿函数
//仿函数(functor)，就是使一个类的使用看上去象一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了。

class person
{
public:
    person(int age,const char *name)
    {
        this->age = age;
        strcpy(this->name, name);
    }
public:
    int age;
    char name[28];
protected:
private:
};
class func_person
{
public:
    bool operator() (const person & person1,const person & person2)
    {
        return person1.age > person2.age;
    }
};
int setDeal2()
{
    set<person,func_person> setTmp;
    
    setTmp.insert(person(23, "hujian"));
    setTmp.insert(person(12, "songhuan"));
    setTmp.insert(person(32, "liuhaitao"));
    setTmp.insert(person(65, "litianyu"));
    setTmp.insert(person(24, "gaohang"));
    setTmp.insert(person(24, "lisan"));   //根据set的特性，此条数据插入不进去
//    问题：怎么判断这个insert插入成功了呢＝＝＝＝＝》函数返回值判断
    pair<set<person, func_person>::iterator,bool> pairTmp;
    pairTmp = setTmp.insert(person(33, "zhangsan"));
    if(pairTmp.second)
    {
        cout<<"插入成功！"<<endl;
    }
    pairTmp = setTmp.insert(person(33, "zhaowu"));
    if(! pairTmp.second)
    {
        cout<<"插入失败！"<<endl;
    }
    
    
    
    for(set<person,func_person>::iterator it = setTmp.begin(); it != setTmp.end(); it++)
    {
        cout<<"name:"<<(*it).name<<"  age:"<<(*it).age<<endl;
    }
    
    return 0;
}
int main()
{
    int rv = 0;
//    rv = setDeal();
    rv = setDeal2();
    cout<<"*****STL Set*****"<<endl;
    return 0;
}

