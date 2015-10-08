//
//  STLStack.cpp
//  STL
//
//  Created by 胡健 on 15/10/8.
//  Copyright © 2015年 胡健. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
void printStack(stack<int> & stackTmp)
{
    while(!stackTmp.empty())
    {
        cout<<stackTmp.top()<<" ";
        stackTmp.pop();
    }
    cout<<endl;
}
int stackDeal()
{
    stack<int> stackTmp;
    for(int i = 0; i < 10; i++)
    {
        stackTmp.push(i+1);
    }
    printStack(stackTmp);
    return 0;
}
int main()
{
    int rv = 0;
    rv = stackDeal();
    cout<<"*****STL Stack*****"<<endl;
    return 0;
}

