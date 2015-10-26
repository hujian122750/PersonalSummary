//
//  STL_Algorithm02.cpp
//  STL算法
//
//  Created by 胡健 on 15/10/26.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include "STL_Algorithm02.hpp"

int algorithm02_01()
{
    plus<int> intType;
    int tmp = intType(100,30);
    cout<<"tmp:"<<tmp<<endl;
    plus<string> strType;
    string sTmp = strType("aaa","bbb");
    cout<<"sTmp:"<<sTmp<<endl;
    
    vector<string> vec;
    vec.push_back("aaa");
    vec.push_back("bbb");
    vec.push_back("ccc");
    vec.push_back("ddd");
    vec.push_back("ccc");
    vec.push_back("ccc");
    
    sort(vec.begin(),vec.end(),greater<string>());
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
    
    
    //函数适配器   bind2nd将预定义函数对象和第二个参数绑定
    long strCount = count_if(vec.begin(), vec.end(), bind2nd(equal_to<string>(), "ccc"));
    cout<<"出现ccc的次数:"<<strCount<<endl;
    return 0;
}
class isGreater
{
public:
    isGreater(int _num)
    {
        num = _num;
    }
    bool operator()(int numTmp)
    {
        return numTmp > num;
    }
private:
    int num;
};
int algorithm02_02()
{
//    函数适配器
    vector<int> vec;
    for(int i = 0; i < 10; i++)
    {
        vec.push_back(i+1);
    }
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
    long num1 = count(vec.begin(), vec.end(), 3);
    cout<<"num1="<<num1<<endl;
//    用谓词实现统计大于2的个数
    isGreater is_greater(2);
    long num2 = count_if(vec.begin(), vec.end(), is_greater);
    cout<<"num2="<<num2<<endl;
//    用预定义函数对象统计大于2的个数
//    greater<int>有两个参数，左参数来自容器，右参数绑定
    long num3 = count_if(vec.begin(),vec.end(),bind2nd(greater<int>(),2));
    cout<<"num3="<<num3<<endl;
//    求奇数的个数
    long num4 = count_if(vec.begin(),vec.end(),bind2nd(modulus<int>(),2));
    cout<<"num4="<<num4<<endl;
//    求偶数的个数
    long num5 = count_if(vec.begin(),vec.end(),not1(bind2nd(modulus<int>(),2)));
    cout<<"num5="<<num5<<endl;
    return 0;
}

int main()
{
    int rv = 0;
//    rv = algorithm02_01();
    rv = algorithm02_02();
    cout<<"*****STL Algorithm*****"<<endl;
    return 0;
}