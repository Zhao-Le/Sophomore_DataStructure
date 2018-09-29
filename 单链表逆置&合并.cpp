//
//  main.cpp
//  dc
//
//  Created by 张碧晨的男朋友 on 2018/9/28.
//  Copyright © 2018年 Jasper. All rights reserved.
//


#include<iostream>
using namespace std;
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*Linklist;
void Initlist(Linklist &L)
{
    L=new LNode;
    L->next=NULL;
}
void Creatlist_B(Linklist &L)
{
    int n;
    cout<<"请输入所需个数:"<<endl;
    cin>>n;
    Linklist p=NULL,pr=NULL;
    pr=L;
    cout<<"请输入数据:"<<endl;
    for(int i=0;i<n;i++)
    {
        p=new LNode;
        cin>>p->data;
        p->next=NULL;
        pr->next=p;
        pr=p;
    }
}
void ListInsert(Linklist &L)
{
    int m;
    Linklist p=NULL,pr=NULL;
    p=L;
    cout<<"请输入你想插入的数字:"<<endl;
    cin>>m;
    while(p->next&&p->next->data<m)
    {
        p=p->next;
    }
    pr=new LNode;
    pr->data=m;
    pr->next=p->next;
    p->next=pr;
}
void Back(Linklist &L)
{
    Linklist p,pr,ps;
    p=L->next;
    ps=p->next;
    while(p->next)
    {
        p->next=ps->next;
        pr=ps;
        pr->next=L->next;
        L->next=pr;
        ps=p->next;
    }
}
void MergeList(Linklist &A,Linklist &B)
{
    Linklist pa=A->next,pb=B->next,pr=NULL;
    A->next=NULL;
    while(pa&&pb)
    {
        if(pa->data<pb->data)
        {
            pr=pa->next;
            pa->next=A->next;
            A->next=pa;
            pa=pr;
        }
        else if(pa->data>pb->data)
        {
            pr=pb->next;
            pb->next=A->next;
            A->next=pb;
            pb=pr;
        }
        else
        {
            pa=pa->next;
        }
    }
    while(pa)
    {
        pr=pa->next;
        pa->next=A->next;
        A->next=pa;
        pa=pr;
    }
    while(pb)
    {
        pr=pb->next;
        pb->next=A->next;
        A->next=pb;
        pb=pr;
    }
}
void ListOutput(Linklist &L)
{
    Linklist p;
    p=L->next;
    cout<<"操作后的数据如下:"<<endl;
    while(p)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
}
int main()
{
    
    cout<<"---------------菜单----------------"<<endl;
    cout<<"-------------1.插入-----------------"<<endl;
    cout<<"-------------2.逆置-----------------"<<endl;
    cout<<"-------------3.合并-----------------"<<endl;
    cout<<"-------------4.退出-----------------"<<endl;
    int a;
    Linklist L;
    Initlist(L);
    Creatlist_B(L);
    while(1)
    {
        cout<<"请输入功能:"<<endl;
        cin>>a;
        switch(a)
        {
            case 1:
            {
                ListInsert(L);
                ListOutput(L);
                cout<<endl<<endl;
                break;
            }
            case 2:
            {
                Back(L);
                ListOutput(L);
                cout<<endl<<endl;
                break;
            }
            case 3:
            {
                Linklist A,B;
                Initlist(A);
                Initlist(B);
                Creatlist_B(A);
                Creatlist_B(B);
                MergeList(A,B);
                ListOutput(A);
                cout<<endl<<endl;
                break;
            }
            case 4:
                exit(0);
        }
    }
}

