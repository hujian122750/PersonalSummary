//
//  STLDeque.cpp
//  STL
//
//  Created by 胡健 on 15/10/7.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void printDeque(deque<int> &deq)
{
//    for(int i = 0; i < deq.size(); i++)
//    {
//        cout<<deq[i]<<" ";
//    }
    for(deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int dequeDeal()
{
    deque<int> deq;
    for(int i = 0; i < 5; i++)
    {
        deq.push_back(i+1);
    }
    for(int i = 0; i < 5; i++)
    {
        deq.push_front(-1-i);
    }
    printDeque(deq);
//    查找－1所在队列中的下标
    deque<int>::iterator it = find(deq.begin(),deq.end(),-1);
    if(it != deq.end())
    {
        cout<<"-1所在队列的下标为"<<distance(deq.begin(),it)<<endl;
    }
    
    return 0;
}
int mainDeque()
{
//    双端队列
    int rv = 0;
    rv = dequeDeal();
    cout<<"*****STL Deque*****"<<endl;
    return 0;
}

//
//deque是一种优化了的、对序列两端元素进行添加和删除操作的基本序列容器。它允许较为快速地随机访问，但它不像vector 把所有的对象保存在一块连续的内存块，而是采用多个连续的存储块，并且在一个映射结构中保存对这些块及其顺序的跟踪。向deque 两端添加或删除元素的开销很小。它不需要重新分配空间，所以向末端增加元素比vector 更有效。
//
//实际上，deque 是对vector 和list 优缺点的结合，它是处于两者之间的一种容器。
//Deque 的特点：
//(1) 随机访问方便，即支持[ ] 操作符和vector.at() ，但性能没有vector 好；
//(2) 可以在内部进行插入和删除操作，但性能不及list ；
//(3) 可以在两端进行push 、pop ；
//(4) 相对于verctor 占用更多的内存。
//双向队列和向量很相似，但是它允许在容器头部快速插入和删除（就像在尾部一样）。
//1.Constructors 创建一个新双向队列
//语法:
//deque();//创建一个空双向队列
//deque( size_type size );// 创建一个大小为size的双向队列
//deque( size_type num, const TYPE &val ); //放置num个val的拷贝到队列中
//deque( const deque &from );// 从from创建一个内容一样的双向队列
//deque( input_iterator start, input_iterator end );
//// start 和 end - 创建一个队列，保存从start到end的元素。
//2.Operators 比较和赋值双向队列
////可以使用[]操作符访问双向队列中单个的元素
//3.assign() 设置双向队列的值
//语法:
//void assign( input_iterator start, input_iterator end);
////start和end指示的范围为双向队列赋值
//void assign( Size num, const TYPE &val );//设置成num个val。
//4.at() 返回指定的元素
//语法:
//reference at( size_type pos ); 返回一个引用，指向双向队列中位置pos上的元素
//5.back() 返回最后一个元素
//语法:
//reference back();//返回一个引用，指向双向队列中最后一个元素
//6.begin() 返回指向第一个元素的迭代器
//语法:
//iterator begin();//返回一个迭代器，指向双向队列的第一个元素
//7.clear() 删除所有元素
//8.empty() 返回真如果双向队列为空
//9.end() 返回指向尾部的迭代器
//10.erase() 删除一个元素
//语法:
//iterator erase( iterator pos ); //删除pos位置上的元素
//iterator erase( iterator start, iterator end ); //删除start和end之间的所有元素
////返回指向被删除元素的后一个元素
//11.front() 返回第一个元素的引用
//12.get_allocator() 返回双向队列的配置器
//13.insert() 插入一个元素到双向队列中
//
//语法:
//iterator insert( iterator pos, size_type num, const TYPE &val ); //pos前插入num个val值
//void insert( iterator pos, input_iterator start, input_iterator end );
////插入从start到end范围内的元素到pos前面
//14.max_size() 返回双向队列能容纳的最大元素个数
//15.pop_back() 删除尾部的元素
//16.pop_front() 删除头部的元素
//17.push_back() 在尾部加入一个元素
//18.push_front() 在头部加入一个元素
//19.rbegin() 返回指向尾部的逆向迭代器
//20.rend() 返回指向头部的逆向迭代器
//21.resize() 改变双向队列的大小
//22.size() 返回双向队列中元素的个数
//23.swap() 和另一个双向队列交换元素
//语法：
//void swap( deque &target );// 交换target和现双向队列中元素


