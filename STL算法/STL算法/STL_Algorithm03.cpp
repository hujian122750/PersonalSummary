//
//  STL_Algorithm03.cpp
//  STL算法
//
//  Created by 胡健 on 15/10/27.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include "STL_Algorithm03.hpp"
class ShowElement
{
public:
    ShowElement()
    {
        num = 0;
    }
    void operator()(const int& _n)
    {
        num++;
        cout<<_n<<"\t";
    }
    void printElement()
    {
        cout<<num<<endl;
    }
protected:
private:
    int num;
};
void printAlgotithm(const int& tmp)
{
    cout<<tmp<<"\t";
}
int algorithm03_01()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(100);
    vec.push_back(45);
    for_each(vec.begin(), vec.end(), printAlgotithm);
    cout<<endl;
    ShowElement se = for_each(vec.begin(), vec.end(), ShowElement());//可以保留函数对象调用的状态
    cout<<endl;
    se.printElement();
    return 0;
}
int increase(int num)
{
    return num + 100;
}
int algorithm03_02()
{
//    如果目标容器与原容器相同，则transform与for_each相同
//    如果想以某元素替换符合规则的元素，则应使用replace
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    for_each(vec.begin(), vec.end(), printAlgotithm);
    cout<<endl;
    transform(vec.begin(),vec.end(),vec.begin(),increase);  //回调函数
    for_each(vec.begin(), vec.end(), printAlgotithm);
    cout<<endl;
    
    transform(vec.begin(),vec.end(),vec.begin(),negate<int>());  //预定义函数对象
    for_each(vec.begin(), vec.end(), printAlgotithm);
    cout<<endl;
    
    transform(vec.begin(),vec.end(),vec.begin(),bind2nd(multiplies<int>(), 10));  //函数适配器
    for_each(vec.begin(), vec.end(), printAlgotithm);
    cout<<endl;
    
//    可以把运算结果直接输出到屏幕   利用输出流迭代器
    transform(vec.begin(),vec.end(),ostream_iterator<int>(cout,"\t"),negate<int>());
    
    
//    总结：transform对函数对象的要求：函数要有返回值，参数一般是值，不是引用
//    for_each函数对象可以无返回值，参数一般是引用
    return 0;
}

int main03()
{
    int rv = 0;
    rv = algorithm03_02();
    cout<<endl;
    cout<<"********STL Algorithm******"<<endl;
    return 0;
}