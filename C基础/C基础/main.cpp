//
//  main.cpp
//  C基础
//
//  Created by 胡健 on 16/5/4.
//  Copyright © 2016年 胡健. All rights reserved.
//
#include <stdio.h>
#include <iostream>
using namespace std;
#define printPoint3(pP) \
    printf("%d %d %d",pP->x,pP->y, pP->z); \
    printf("========\n");
typedef int(MYINT)[10];
const char* func1()
{
    const char *p = "hujian";
    return p;
}

const char* func2()
{
    const char *p = "hujian";
    return p;
}

void changeArray(int (*pArray)[10])
{
    (*pArray)[1] = 100;
}

int main01(int argc, const char * argv[])
{
    // insert code here...
//    int a[10] = {0};
//    printf("%d\n",func1());
//    printf("%d\n",func2());
//    changeArray(&a);
//    printf("%d\n",a[1]);
    
    MYINT mArray;
    for (int i = 0; i < 10; i++)
    {
        mArray[i] = i+1;
    }
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

int main02()
{
    register int num = 0;
    cout<<num<<endl;
    
    int a = 40;
    int b = 30;
    a < b ? a : b = 11;
    cout<<a<<endl;
    cout<<b<<endl;
    
    return 0;
}

int& getNum()
{
    int num = 100;
    return num;
}

int main03()
{
    int num = 99;
    num = getNum();
    
    int& tmp = getNum();
    cout<< num<<endl;
    cout<< tmp<<endl;
    return 0;
}

int main04()
{
    const int& num = 10;
    int* p = (int*)&num;
    *p = 100;
    cout<<num<<endl;
    return 0;
}

void func1(int a, int b)
{
    
}

class GameInfo
{
};

int main05()
{
    func1();
    cout<<sizeof(GameInfo)<<endl;
    return 0;
}


class Obj
{
public:
    int i;
};

class Parent1 : public Obj
{
public:
    int j;
};

class Parent2 : public Obj
{
public:
    int k;
};

class Child : public Parent1, public Parent2
{
public:
    int m;
    Child (int i, int j, int k)
    {
        //this->i = i;
        this->j = j;
        this->k = k;
    }
};

int main06()
{
    Child child(1,2,3);
    cout << sizeof(Child) <<endl;
    return 0;
}

class MyClass
{
public:
    MyClass(int _a):a(_a)
    {
        
    }
public:
    const int a;
};

int main07()
{
    MyClass obj = MyClass(100);
    return 0;
}

int mymax(int a, int b)
{
    return a > b ? a : b;
}

template<typename T>
T mymax(T a, T b)
{
    return a > b ? a : b;
}

int main08()
{
    mymax(3,4);
    mymax<>(4,5);
    return 0;
}

class Point3
{
public:
    Point3(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
public:
    int x;
    int y;
    int z;
};

int main09()
{
    Point3 point(1,2,3);
    Point3 *pPoint = &point;
    printPoint3(pPoint);
    return 0;
}

class Point
{
public:
    Point(float x) : mX(x){}
    static int getCount();
private:
    float mX;
    static int mCount;
    
};

int main10()
{
    Point point(10.0f);
    cout<<sizeof(point)<<endl;
    return 0;
}

template<typename T>
class Complex
{
public:
    Complex(T real, T image);
    void printComplex();
    template<typename T2>
    friend Complex<T2> operator+(const Complex<T2> &c1, const Complex<T2> &c2);
private:
    T mReal;
    T mImage;
};

template<typename T>
Complex<T>::Complex(T real, T image)
{
    mReal = real;
    mImage = image;
}

template<typename T>
void Complex<T>::printComplex()
{
    cout<<mReal<<"+"<<mImage<<"i"<<endl;
}

template<typename T2>
Complex<T2> operator+(const Complex<T2> &c1, const Complex<T2> &c2)
{
    Complex<T2> c3(c1.mReal + c2.mReal,c1.mImage + c2.mImage);
    return c3;
}

int main()
{
    Complex<int> c1(1,2);
    Complex<int> c2(3,4);
    Complex<int> c3 = c1 + c2;
    c3.printComplex();
    return 0;
}




