/*
    ����һ��˳���
    ��������һ���ձ�
    ��������
    ����
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 100
typedef struct
{
    int *elem;  //�洢�ռ�Ļ���ַ
    int length;  //��
}SqList;
void InitList(SqList &L)
{
    L.elem=new int[MAXSIZE];//��˳������һ����СΪmaxsize������ռ�
    if(!L.elem)
        exit(0);//�ж��Ƿ�Ϸ�
    L.length=0;
}
void Input(SqList &L)
{
    int n;
    cout<<"����������������ݸ���:"<<endl;
    cin>>n;
    cout<<"����������:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i];
        L.length++;
    }
}
void Insert(SqList &L)
{
	int i=0,n;
	cout<<"�������������ݣ�"<<endl;
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
    cout<<"������������:";
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
    cout<<"�ñ�����������:"<<endl;
    for(int i=0;i<L.length;i++)
		cout<<L.elem[i]<<",";
    cout<<endl;
}
int main()
{
    cout<<"----------------�˵�----------------"<<endl;
    cout<<"-------------1.����-----------------"<<endl;
    cout<<"-------------2.����-----------------"<<endl;
    cout<<"-------------3.����-----------------"<<endl;
    cout<<"-------------4.�˳�-----------------"<<endl;
    int a;
    while(1)
    {
        cout<<"�����빦��:"<<endl;
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
