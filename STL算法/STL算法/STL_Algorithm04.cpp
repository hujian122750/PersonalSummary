//
//  STL_Algorithm04.cpp
//  STL算法
//
//  Created by 胡健 on 15/10/27.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include "STL_Algorithm04.hpp"

void func_adjacent_find()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(5);
    
    vector<int>::iterator it = adjacent_find(vec.begin(), vec.end());//默认查找相邻重复元素
    if(it == vec.end())
    {
        cout<<"not exist"<<endl;
    }
    else
    {
        cout<<"====="<<*it<<endl;
    }
    long index = distance(vec.begin(), it);
    cout<<"迭代器的位置:"<<index<<endl;
}
void func_binary_search()
{
    set<int> setTmp;
    setTmp.insert(1);
    setTmp.insert(3);
    setTmp.insert(5);
    setTmp.insert(7);
    bool flag = binary_search(setTmp.begin(), setTmp.end(), 5);//必须在有序序列中使用
    if(flag)
    {
        cout<<"已找到"<<endl;
    }
//    count/count_if/find/find_if类似
    
}
void func_merge()
{
    //merge合并两个有序序列到另一序列
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    
    vector<int> vec2;
    vec2.push_back(2);
    vec2.push_back(4);
    vec2.push_back(6);
    
    vector<int> vec3;
    vec3.resize(vec1.size()+vec2.size());
    vector<int>::iterator it = merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
    if(it == vec3.end())
    {
        cout<<"bottom"<<endl;
    }
    for(vector<int>::iterator it1 = vec3.begin();it1 != vec3.end(); it1++)
    {
        cout<<*it1<<"\t";
    }
    cout<<endl;
    
    //sort排序类似
    
}
void func_random_shuffle()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(9);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(4);
    
    random_shuffle(vec.begin(), vec.end());//对指定范围内的元素随机排序
    srand(time_t(1000));// 设置随机种子
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
    
//    copy：将容器中的元素拷贝到另一个容器中
//    replace(vec.begin(),vec.end(),3,8)  将容器中所有元素值为3替换改为8(也可以为谓词，将大于3的)
//    swap:交换两个容器中的元素
//    accumulate(vec.begin(),vec.end(),value)  对指定容器范围求和并加上value的值
//    fill(vec.begin(),vec.end(),8)   将此容器区间的元素全部改为8
    
//    set_union  构造一个有序序列，包含两个有序序列的并集
//    set_intersection  构造一个有序序列，包含两个有序序列的交集
//    set_difference  构造一个有序序列，该序列保存第一个有序序列存在而第二个有序序列不存在的元素
}
int main()
{
//    func_adjacent_find();
//    func_binary_search();
//    func_merge();
    func_random_shuffle();
    
    cout<<"*****STL Algorithm*****"<<endl;
    return 0;
}