//
//  STLVector.cpp
//  STL
//
//  Created by 胡健 on 15/10/7.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <vector>    
using namespace std;
//vector的特点：在尾部插入和删除方便，且效率高，在首部操作会导致后面所有元素的移动
int vectorInit()
{
    vector<int> vec1;
    for(int i = 1; i < 5; i++)
    {
        vec1.push_back(i+1);
    }
    vector<int> vec2 = vec1;
    vector<int> vec3(vec1.begin(),vec1.begin()+2);
    vector<int> vec4(5,100);//初始化五个元素，每个元素的值为100；
    return 0;
}
int vectorErgodic()
{
    vector<int> vec;
    for(int i = 0; i < 10; i++)
    {
//        push_back 是在vector的尾部插入数据
        vec.push_back(i+1);
//        vec[i] = i + 1;
//        如果想这么初始化，必须在声明的时候写出最大容量  vector<int> vec(10)
    }
    cout<<"size = "<<vec.size()<<endl;
    for(int i = 0; i < 10; i++)
    {
//        cout<<vec[i]<<" ";
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;
//    修改首元素的值，front可以当左值，即该函数的返回值一定是引用
    vec.front() = 100;
    cout<<"front = "<<vec.front()<<endl;
    
//    迭代器遍历
    cout<<"iteraotr: ";
//    end()的位置为最后一个元素的后面，而不是指向最后一个元素
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout<<*it<<" ";
        *it = *it*2;
    }
    cout<<endl;
    cout<<"reverse iteraotr: ";
//    只读迭代器   vector<int>::const_iterator
//    逆向迭代器
    for(vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
    {
        cout<<*rit<<" ";
    }
    cout<<endl;
    
    while(vec.size() > 0)
    {
        vec.back() = vec.back() + 100;
//        cout<<vec.back()<<" ";
        vec.pop_back();
    }
    cout<<endl;
    return 0;
}
void printVector(vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int vectorDeleteAndInsert()
{
    vector<int> vec;
//    vec.clear();清除所有数据
//    vec.erase(vec.begin()+2, vec.end()-2);删除此区间内的数据，返回下一个数据的位置
//    vec.erase(vec.begin());删除指定位置的数据，返回下一个数据的位置
    for(int i = 0; i < 10; i++)
    {
        vec.push_back(i+1);
    }
    vec.erase(vec.begin());
    vec.erase(vec.begin(), vec.begin()+3);
    printVector(vec);
    
//    把值为5的元素删除
    for(vector<int>::iterator it = vec.begin(); it != vec.end();)
    {
        if(*it == 5)
        {
            it = vec.erase(it);//删除一个元素后迭代器会改变，此时迭代器已加1；
        }
        else
        {
            it++;
        }
    }
    printVector(vec);
    
    vec.insert(vec.begin(),1000);//在指定位置插入元素,返回新元素的位置
    vec.insert(vec.begin(),5,999);//在指定位置插入5个999，无返回值
    vec.insert(vec.end(),vec.begin(),vec.end());//在指定位置插入区间的数据，无返回值
//    此处代表在末尾在插入一遍数据
    printVector(vec);
    return 0;
}
int mainVector()
{
    int rv = 0;
//    rv = vectorInit();
//    rv = vectorErgodic();
    rv = vectorDeleteAndInsert();
    cout<<"*****STL Vector*****"<<endl;
    return 0;
}
