//
//  main.cpp
//  顺序表右移
//
//  Created by 张碧晨的男朋友 on 2018/9/20.
//  Copyright © 2018年 Jasper. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
class V
{
private:
    int size;
    int* data;
public:
    V(int input_size)
    {
        size=input_size;
        data=new int [size];
    }
    ~V()
    {
        delete []data;
        data=NULL;
    }
    void insert (int index,int value)
    {
        data[index]=value;
    }
    void remove(int time)
    {
        for (int t=0;t<time;t++)
        {
            int temp;
            temp=data[size-1];
            for (int i=size-2;i>=0;i--)
            {
                data[i+1]=data[i];
            }
            data[0]=temp;
        }
    }
    void printInfo()
    {
        for (int i=0;i<size;i++)
        {
            printf(i>0?" %d":"%d",data[i]);
        }
    }
};
int main()
{
    int n,k;//元素个数,右移的位移量
    scanf("%d%d",&n,&k);
    V p(n);
    for (int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        p.insert(i,temp);
    }
    p.remove(k);
    p.printInfo();
    cout<<endl;
}
