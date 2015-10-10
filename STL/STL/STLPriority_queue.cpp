//
//  STLPriority_queue.cpp
//  STL
//
//  Created by 胡健 on 15/10/10.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
//优先级队列：最大优先级队列、最小优先级队列
//priority_queue 对于基本类型的使用方法相对简单。他的模板声明带有三个参数，priority_queue<Type, Container, Functional>
//Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
//Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list.
int priority_queueDeal()
{
    priority_queue<int> que1;//默认为最大优先级队列，与下面的等价
    priority_queue<int,vector<int>,less<int>> que2;
    priority_queue<int,vector<int>,greater<int>> que3;  //最小优先级队列
    int arr[10] = {1,4,99,67,32,9,100,76,22,200};
    for(int i = 0; i < 10; i++)
    {
        que1.push(arr[i]);//按照依次递减的方式存放
    }
    cout<<"que1对首元素为:"<<que1.top()<<endl;
    while(!que1.empty())
    {
        cout<<que1.top()<<" ";
        que1.pop();
    }
    cout<<endl;
    
    
    
    return 0;
}
int mainPriority_queue()
{
    int rv = 0;
    rv = priority_queueDeal();
    cout<<"*****STL Priority_queue*****"<<endl;
    return 0;
}

