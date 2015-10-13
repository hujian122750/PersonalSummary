//
//  STLMap.cpp
//  STL
//
//  Created by 胡健 on 15/10/13.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

//1、map是关联式容器，key值是唯一的，集合中的元素按照一定的顺序排列。元素插入过程
//是按照顺序规则插入，所以不能指定位置插入；
//2、map的具体实现采用红黑树变体的平衡二叉树的数据结构。在插入和删除上比vector快；
//3、map可以直接存取可以所对应的value，支持［］操作符，如map［key］＝value；
//4、multimap与map的区别：map支持唯一键值，每个键只出现一次；而multimap中相同键
//可以出现多次。multimap不支持［］操作；
void printMap(const map<int,string> & mapTmp)
{
    for(map<int,string>::const_iterator it = mapTmp.begin(); it != mapTmp.end();it++)
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }
}
int mapDeal()
{
    map<int,string> map1;

    map1.insert(pair<int,string>(1,"hujian"));//方法一
    map1.insert(pair<int,string>(2,"songhuan"));
    
    map1.insert(make_pair(3, "gaohang"));//方法二
    map1.insert(make_pair(4, "litianyu"));
    
    map1.insert(map<int,string>::value_type(5,"xiaoguan"));//方法三
    map1.insert(map<int,string>::value_type(6,"liuhaitao"));
    
    map1[7] = "zhangsan";//方法四
    map1[8] = "lisi";
    printMap(map1);
    return 0;
}
int main()
{
    int rv = 0;
    rv = mapDeal();
    cout<<"*****STL Map*****"<<endl;
    return 0;
}
