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
//前三种的返回值都是pair<itetatir,bool>
    pair<map<int,string>::iterator,bool> pair1 = map1.insert(pair<int,string>(1,"hujian"));//方法一
    if(pair1.second == false)
    {
        cout<<"插入失败"<<endl;
    }
    else
    {
        cout<<"==="<<pair1.first->first<<"\t"<<pair1.first->second<<endl;
    }
    map1.insert(pair<int,string>(2,"songhuan"));
    
    map1.insert(make_pair(3, "gaohang"));//方法二
    map1.insert(make_pair(4, "litianyu"));
    
    map1.insert(map<int,string>::value_type(5,"xiaoguan"));//方法三
    map1.insert(map<int,string>::value_type(6,"liuhaitao"));
    
    map1[7] = "zhangsan";//方法四
    map1[8] = "lisi";
    map1[9] = "chenba";
//    结论：方法四若key已经存在，则覆盖，前三种若key存在则报错；
    printMap(map1);
    
    map<int,string>::iterator it = map1.find(999);
    if(it == map1.end())
    {
        cout<<"999 not exist!"<<endl;
    }
    else
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }
    
    
    pair<map<int,string>::iterator,map<int,string>::iterator> mypair =
    map1.equal_range(5);
//    返回两个迭代器，一个迭代器大于等于5，一个迭代器大于5
    if(mypair.second != map1.end())
    {
        cout<<mypair.first->first<<"\t"<<mypair.first->second<<endl;
    }
    
    cout<<mypair.second->first<<"\t"<<mypair.second->second<<endl;
    cout<<"============================="<<endl;
//    map的删除
    while(!map1.empty())
    {
        map<int,string>::iterator it = map1.begin();
        map1.erase(it);
    }
    cout<<"map size:"<<map1.size()<<endl;
    return 0;
}


//multimap实例
class staff
{
public:
    string name;
    int age;
    string tel;
    double salary;
    staff(string _name,int _age)
    {
        this->name = _name;
        this->age = _age;
    }
//    staff(const staff & stf)
//    {
//    }
protected:
private:
};
int multimapPro()
{
    multimap<string,staff> map;
    for(int i = 0; i < 5; i++)
    {
        staff stf("name"+to_string(i),i+20);
        map.insert(multimap<string,staff>::value_type(to_string(i+1),stf));
    }
//    map.insert(multimap<string,staff>::value_type());
    for(multimap<string,staff>::iterator it = map.begin(); it != map.end(); it++)
    {
        cout<<it->first<<"\t"<<it->second.name<<endl;
    }
    cout<<"map count = "<<map.count(to_string(1))<<endl;
    
    
//    查找key为3的所有对象
    long nums = map.count(to_string(3));
    int tag = 0;
    multimap<string,staff>::iterator it = map.find(to_string(3));
    while(it != map.end() && tag < nums)
    {
        cout<<it->first<<"\t"<<it->second.name<<endl;   //也可以直接修改multimap的值
        it++;
        tag++;
    }
    
    return 0;
}



int mainMap()
{
    int rv = 0;
//    rv = mapDeal();
    rv = multimapPro();
    cout<<"*****STL Map*****"<<endl;
    return 0;
}






