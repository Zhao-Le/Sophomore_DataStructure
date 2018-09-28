//
//  main.cpp
//  2.1
//
//  Created by 张碧晨的男朋友 on 2018/9/28.
//  Copyright © 2018年 Jasper. All rights reserved.
//

#include <iostream>
using namespace std;
#define M 5
struct Link{
    int x;
    struct Link *next;
};
int main(){
    struct Link *head=new Link,*r=head;
    head->next=NULL;
    cout<<"输入"<<M<<"个有序的数字:";
    for(int i=0;i<M;i++){
        struct Link *p=new Link;//Creating a new node;
        cin>>p->x;
        p->next=NULL;
        r->next=p;
        r=p;
    }
    struct Link *p=new Link;
    cout<<"插入你想插入的数据:";
    cin>>p->x;
    p->next=NULL;
    struct Link *pr=head;
    r=head->next;
    while(r){
        if(r->x>=p->x) break;
        pr=r;
        r=r->next;
    }
    if(r){
        pr->next=p;
        p->next=r;
    }
    else{
        pr->next=p;
    }
    r=head->next;
    while(r){
        cout<<r->x<<" ";
        r=r->next;
    }
    cout<<endl;
}
