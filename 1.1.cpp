/*
    建立一个顺序表
    函数建立一个空表
    输入数据
    插入
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 100
typedef struct
{
    int *elem;  //存储空间的基地址
    int length;  //表长
}SqList;
void InitList(SqList &L)
{
    L.elem=new int[MAXSIZE];//给顺序表分配一个大小为maxsize的数组空间
    if(!L.elem)
        exit(0);//判断是否合法
    L.length=0;
}
void Input(SqList &L)
{
    int n;
    cout<<"请输入想输入的数据个数:"<<endl;
    cin>>n;
    cout<<"请输入数据:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i];
        L.length++;
    }
}
void Insert(SqList &L)
{
	int i=0,n;
	cout<<"请输入插入的数据："<<endl;
	cin>>n;
	while(n>L.elem[i])
	{
		i++;
		if(i==L.length)
            break;
	}
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
	if(i==L.length)
        L.elem[L.length]=n;
    else
        L.elem[i]=n;
	L.length++;
}
void Change(SqList &L)
{
    int temp,n;
    cout<<"请输入右移数:";
    cin>>n;
    for(int j=0;j<n;j++)
    {
        temp=L.elem[L.length-1];
        for(int i=L.length-1;i>0;i--)
        {
            L.elem[i]=L.elem[i-1];
        }
        L.elem[0]=temp;
    }
}
void Reversal(SqList &L)
{
    int temp;
    for(int i=0,j=L.length-1;i<=j;i++,j--)
    {
        temp=L.elem[i];
        L.elem[i]=L.elem[j];
        L.elem[j]=temp;
    }
}
void Output(SqList &L)
{
    cout<<"该表内数据如下:"<<endl;
    for(int i=0;i<L.length;i++)
		cout<<L.elem[i]<<",";
    cout<<endl;
}
int main()
{
    cout<<"----------------菜单----------------"<<endl;
    cout<<"-------------1.插入-----------------"<<endl;
    cout<<"-------------2.右移-----------------"<<endl;
    cout<<"-------------3.倒序-----------------"<<endl;
    cout<<"-------------4.退出-----------------"<<endl;
    int a;
    while(1)
    {
        cout<<"请输入功能:"<<endl;
        cin>>a;
        switch(a)
        {
            case 1:
                {
                    SqList L;
                    InitList(L);
                    Input(L);
                    Insert(L);
                    Output(L);
                    cout<<endl<<endl;
                    break;
                }
            case 2:
                {
                    SqList L;
                    InitList(L);
                    Input(L);
                    Change(L);
                    Output(L);
                    cout<<endl<<endl;
                    break;
                }
            case 3:
                {
                    SqList L;
                    InitList(L);
                    Input(L);
                    Reversal(L);
                    Output(L);
                    cout<<endl<<endl;
                    break;
                }
            case 4:
                exit(0);
        }
    }
}
