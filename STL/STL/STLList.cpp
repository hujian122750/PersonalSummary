//
//  STLList.cpp
//  STL
//
//  Created by 胡健 on 15/10/9.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;
//特点：1、双向链表，可以高效的进行插入和删除；
//     2、不可随机的存储元素，所以不支持at()函数和［］操作符；迭代器it可以＋＋，但是不可以＋5等
void printList(list<int> &listTmp)
{
    list<int>::iterator it = listTmp.begin();
    while(it != listTmp.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    
}
int listDeal()
{
    list<int> listTmp;
    for(int i = 0; i < 10; i++)
    {
        listTmp.push_back(i+1);
    }
    cout<<"list size = "<<listTmp.size()<<endl;
    list<int>::iterator it = listTmp.begin();
    while(it != listTmp.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    
    
    it = listTmp.begin();
    it++;
    it++;
    it++;
//    1  2  3  4  5  6  7  8  9  10
//    it = it + 5;   此处有问题，迭代器不可跳跃式前进，即不支持随机访问
//    思考：100插入的位置
    listTmp.insert(it, 100);
//    结论：1、链表的节点index是从0开始；
//         2、从链表的3号为止插入元素，是说原来的3号位置的元素变为4号位置。。。依次类推
//            即3号及其后面的元素整体后移一个元素位置
    printList(listTmp);
    
    
//    list的删除操作，遵循［start，end）左闭右开  erase（0，3）会删除0／1/2号位置，3号位置不会删除
    it = listTmp.begin();
    it++;
    list<int>::const_iterator itTmp = listTmp.begin();
    itTmp++;
    itTmp++;
    itTmp++;
//    listTmp.erase(itTmp, itTmp+3); 此迭代器不支持＋3
    listTmp.erase(it, itTmp);
    printList(listTmp);
    
    
    listTmp.remove(100);//删除等于值为100的元素
    printList(listTmp);
    
    
    
    
    return 0;
}
int mainList()
{
    int rv = 0;
    rv = listDeal();
    cout<<"*****STL List*****"<<endl;
    return 0;
}
