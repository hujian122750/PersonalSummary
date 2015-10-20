//
//  STLSummary.cpp
//  STL
//
//  Created by 胡健 on 15/10/20.
//  Copyright © 2015年 胡健. All rights reserved.
//



//总结：所有容器提供的都是值语意，而不是引用语意。容器执行元素插入时，内部实施拷贝动作。所以STL内的元素
//必须能够拷贝(即元素中有指针类型，就会出现内存问题)，即必须提供拷贝构造函数
//除了queue和stack外，其他的STL都提供迭代器访问元素；
//通常STL容器不会抛出异常，所以开发者必须传入正确的参数
#include <iostream>
#include <vector>
using namespace std;
class People
{
public:
    People(const char *_name,const int _age)
    {
        m_pname = new char[strlen(_name) + 1];
        strcpy(m_pname, _name);
        m_age = _age;
    }
    People(const People & obj)
    {
        m_pname = new char[strlen(obj.m_pname) + 1];
        strcpy(m_pname,obj.m_pname);
        m_age = obj.m_age;
    }
    ~People()
    {
        if(m_pname != NULL)
        {
            delete [] m_pname;
            m_pname = NULL;
        }
    }
//    people1 = people2 = people3;
    People & operator=(const People & obj)
    {
//        先释放people1的内存
         if(m_pname != NULL)
         {
             delete [] m_pname;
             m_pname = NULL;
         }
//        然后利用people2初始化people1
        m_pname = new char[strlen(obj.m_pname) + 1];
        strcpy(m_pname, obj.m_pname);
        m_age = obj.m_age;
        return *this;
    }
    void printPeople()
    {
        cout<<this->m_pname<<"\t"<<this->m_age<<endl;
    }
protected:
private:
    char *m_pname;
    int  m_age;

};
int STLDeal()
{
    People people1("hujian",24);
    People people2 = people1;
    people2.printPeople();
    vector<People> vec;
    vec.push_back(people2);//插入元素会自动调用拷贝构造函数；
    return 0;
}

int main()
{
    int rv = 0;
    rv = STLDeal();
    cout<<"*****STL SUMMARY*****"<<endl;
    return 0;
}


