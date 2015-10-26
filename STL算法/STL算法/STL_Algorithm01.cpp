//
//  STL_Algorithm01.cpp
//  STL算法
//
//  Created by 胡健 on 15/10/21.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include "STL_Algorithm01.hpp"
void printElement(const int & _t)
{
    cout<<_t<<endl;
}
int showElement()
{
    Element<int> et;
    et(100);         //函数对象    一元函数对象
    
    
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    
//    for_each(vec.begin(),vec.end(),Element<int>());//匿名对象，匿名仿函数对象
    
//    函数对象做函数参数
//    template <class _InputIterator, class _Function>
//    inline _LIBCPP_INLINE_VISIBILITY
//    _Function
//    for_each(_InputIterator __first, _InputIterator __last, _Function __f)
//    {
//        for (; __first != __last; ++__first)
//            __f(*__first);
//        return _VSTD::move(__f);  // explicitly moved for (emulated) C++03
//    }
//    此处形参不是引用传递for_each是值传递
    for_each(vec.begin(),vec.end(),et);
    et.printNum();
    
    et = for_each(vec.begin(),vec.end(),et);  //函数对象可以保存状态 
    et.printNum();
    cout<<"***********************"<<endl;
    for_each(vec.begin(), vec.end(), printElement);//回调函数的入口地址
    return 0;
}


//一元谓词
int showElement2()
{
    vector<int> vec;
    for(int i = 10; i < 33; i++)
    {
        vec.push_back(i);
    }
    Element2<int> ele(4);
//    template <class _InputIterator, class _Predicate>
//    inline _LIBCPP_INLINE_VISIBILITY
//    _InputIterator
//    find_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
//    {
//        for (; __first != __last; ++__first)
//            if (__pred(*__first))
//                break;
//        return __first;
//    }
    vector<int>::iterator it = find_if(vec.begin(), vec.end(), ele);
    if(it == vec.end())
    {
        cout<<"不存在被4整除的数"<<endl;
    }
    else
    {
        cout<<"第一个被4整除的数为:"<<*it<<endl;
    }
    return 0;
}
int main01()
{
    int rv = 0;
//    rv = showElement();
    rv = showElement2();
    cout<<"*****STL Algorithm*****"<<endl;
    return 0;
}