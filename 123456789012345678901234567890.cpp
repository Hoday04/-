#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    string work;
    cout<<"������� ������?(��/���)"<<endl;
    cin>>work;
    if(work=="���" || work=="���" || work=="���"|| work=="���" || work=="���" || work=="���" || work=="���" || work=="���")
    return 0;
    START:
	if(work=="��" || work=="��" || work=="��"|| work=="��")
	{
    int l1,h1,l2,h2;
    int a,b,p,c;
    cout<<"������� ����� ������(�� ������ 2):"<<endl;
    cin>>p;
    if(p<=0 || p>2)
    {
    cout<<"������";
	return 0;	
	}
	if(p==1)
	{
		cout<<"������� ���������� ����� �������"<<endl;
		cin>>l1;
		cout<<"������� ���������� �������� �������"<<endl;
		cin>>h1;
	}
	else if(p==2)
	{
		cout<<"������� ���������� ����� 1 �������"<<endl;
		cin>>l1;
		cout<<"������� ���������� �������� 1 �������"<<endl;
		cin>>h1;
		cout<<"������� ���������� ����� 2 �������"<<endl;
		cin>>l2;
		cout<<"������� ���������� �������� 2 �������"<<endl;
		cin>>h2;
	}
	int m[2][2],n[2][2];
    cout<<"���� �� ������ ������� ������� � �������,�� ������� 1,����"<<endl<<"�� �� ������, ����� ��������� ����� ������ �� ������, �� ������� 2"<<endl;
    cin>>a;
    if(a==1)
    {
    //���� ������ � �������
    cout<<"1 �������:"<<endl;
	for(int i=0;i<l1;i++)
	    {
		for (int j=0;j<h1;j++)
		cin>>m[i][j];
		}
	if (p>1)
	{	
	cout<<"2 �������:"<<endl;
	for(int i=0;i<l2;i++)
	    {
		for (int j=0;j<h2;j++)
		cin>>n[i][j];
		}
	}
    }
	//���� ������ � ������
	else if(a==2)
    {
    ifstream fin;
    fin.open("matrix1.txt");
    for (int i=0 ;i<l1;i++)
        {
        for (int j=0;j<h1;j++)
        fin>>m[i][j];
        }
    fin.close();
    if (p>1)
	{
    fin.open("matrix2.txt");
    for (int i=0 ;i<l2;i++)
        {
        for (int j=0;j<h2;j++)
        fin>>n[i][j];
        }
    fin.close();
	}
	}
    else 
    {
    cout<<"������";
	return  0;	
	}	
    //����� ������
	cout<<"1 �������:"<<endl;
	for(int i=0;i<l1;i++)
	    {
		for (int j=0;j<h1;j++)
	    {
		cout<<m[i][j];	
		cout<<" ";
		}
		cout<<endl;
		}
	if (p>1)
	{
	cout<<"2 �������:"<<endl;
	for(int i=0;i<l2;i++)
	    {
		for(int j=0;j<h2;j++)
		{
		cout<<n[i][j];	
		cout<<" ";
		}
		cout<<endl;
		}
	}
	//�������� ��� ���������
	if (p>1)
	{
	cout<<"����� �������� �� ������ ���������� ��� ���������?"<<endl;
	cout<<"�������� �� ���� �������������:"<<endl;
	cout<<"1)�������� ������"<<endl;
	cout<<"2)��������� ������� �� �������"<<endl;
	cout<<"3)��������� ������� �� �����"<<endl;
	cout<<"4)��������� ������� �� �������"<<endl;
	cout<<"5)���������� ������� � �������"<<endl;
	cout<<"6)���������������� �������"<<endl;
    }
    else if (p==1)
    {
    cout<<"����� �������� �� ������ ���������� ��� ���������?"<<endl;
	cout<<"�������� �� ���� �������������:"<<endl;
	cout<<"3)��������� ������� �� �����"<<endl;
	cout<<"5)���������� ������� � �������"<<endl;
	cout<<"6)���������������� �������"<<endl;	
	}
	else
    {
    cout<<"������";
	return 0;	
	}
	cin>>b;
	//��������
	if(b==1)
	{
	int sum[l1][h1];
	if(l1==l2 && h1==h2)
	{
	cout<<"�������� �������:"<<endl;
    for(int i=0;i<l1;i++)
    {
    	for(int j=0;j<h1;j++)
    	{
    	sum[i][j]= m[i][j]+n[i][j];
		cout<<sum[i][j]<<" ";	
		}
		cout<<endl;
	}
    }
    else
    {
    cout<<"������.������ ������� ������ �������.";
    goto ret;	
	}
	}
	//�������
	if(b==2)
	{
	int raz[l1][h1];
	cout<<"�� ����� ������� ������ �������� ������:"<<endl;
	cin>>c;
	if(l1==l2 && h1==h2)
	if(c==1)
	{
	cout<<"�������� �������:"<<endl;
    for(int i=0;i<l1;i++)
    {
    	for(int j=0;j<h1;j++)
    	{
    	raz[i][j]= m[i][j]-n[i][j];
		cout<<raz[i][j]<<" ";	
		}
		cout<<endl;
	}
    }
   	if(c==2)
	{
	cout<<"�������� �������:"<<endl;
    for(int i=0;i<l1;i++)
    {
    	for(int j=0;j<h1;j++)
    	{
    	raz[i][j]= n[i][j]-m[i][j];
		cout<<raz[i][j]<<" ";	
		}
		cout<<endl;
	}
    }
    else
    {
    cout<<"������.������ ������.";
    goto ret;
	}
	}
	//��������� �� ����� 
	if(b==3)
	{
	int ch[l1][h1],x;
	if(p>1)
	{
	cout<<"����� ������� ����� �������� �� �����:"<<endl;
	cin>>c;
	if(c==1)
	Round:
	{
	cout<<"������� �����:"<<endl;
	cin>>x;
	cout<<"�������� �������:"<<endl;
    for(int i=0;i<l1;i++)
    {
    	for(int j=0;j<h1;j++)
    	{
    	ch[i][j]= m[i][j]*x;
		cout<<ch[i][j]<<" ";	
		}
		cout<<endl;
	}	
	}
	else if(c==2)
	{
	cout<<"������� �����:"<<endl;
	cin>>x;
	cout<<"�������� �������:"<<endl;
    for(int i=0;i<l2;i++)
    {
    	for(int j=0;j<h2;j++)
    	{
    	ch[i][j]= n[i][j]*x;
		cout<<ch[i][j]<<" ";	
		}
		cout<<endl;
	}	
	}
	else
	{
	round:
    if (c!=1 || c!=2)
	{
	cout<<"������.������� 1,���� 1 �������, ����� ������� 2:"<<endl;
	cin>>c;	
	goto round;
	}
	else
	goto Round;	
	}
	}
	else if(p==1)
	{
	cout<<"������� �����:"<<endl;
	cin>>x;
	cout<<"�������� �������:"<<endl;
    for(int i=0;i<l1;i++)
    {
    	for(int j=0;j<h1;j++)
    	{
    	ch[i][j]= m[i][j]*x;
		cout<<ch[i][j]<<" ";	
		}
		cout<<endl;
	}	
	}
    }
    //���������
	if(b==4)
	{
	int	proiz[l2*h1],mm[l1*h1],nn[l2*h2];
	for(int i=0;i<l1;i++)
		for (int j=0;j<h1;j++)
		mm[j]=m[i][j];
	for(int i=0;i<l1;i++)
		for (int j=0;j<h1;j++)
		nn[j]=n[i][j];
	if(h1==l2)
	{	
	cout<<"�������� �������:"<<endl;
	for (int i=0;i< l2;++i)
    {
    for (int j=0;j<h1;++j)
        {
        proiz[i*h1+j]=0;
        for(int k=0;k<l1;++k)
        proiz[i*h1+j]+=m[i*l1+k]*n[k*h1+j];
        }
    }
    }
	}
	else if (b>6 || b<1)
	{
	 cout<<"������";	
	 return 0;
	}
	ret:
	cout<<"������ ����������?"<<endl;
	cin>>work;
	if(work=="���" || work=="���" || work=="���"|| work=="���" || work=="���" || work=="���" || work=="���" || work=="���")
	return 0;
	if(work=="��" || work=="��" || work=="��"|| work=="��")
	goto START;
	else if(work!="��" || work!="��" || work!="��"|| work!="��" || work!="���" || work!="���" || work!="���"|| work!="���" || work!="���" || work!="���" || work!="���" || work!="���")
	{
	 while (work!="��" || work!="��" || work!="��"|| work!="��" || work!="���" || work!="���" || work!="���"|| work!="���" || work!="���" || work!="���" || work!="���" || work!="���")
	{
	 cout<<"������.������� '��',���� ������ ������,����� ������� '���'"<<endl;
	 cin>>work;
	}
	}
	}
		else if(work!="��" || work!="��" || work!="��"|| work!="��" || work!="���" || work!="���" || work!="���"|| work!="���" || work!="���" || work!="���" || work!="���" || work!="���")
	{	
	 while (work!="��" || work!="��" || work!="��"|| work!="��" || work!="���" || work!="���" || work!="���"|| work!="���" || work!="���" || work!="���" || work!="���" || work!="���")
	{
	 cout<<"������.������� '��',���� ������ ������,����� ������� '���'"<<endl;
	 cin>>work;
	 if(work=="���" || work=="���" || work=="���"|| work=="���" || work=="���" || work=="���" || work=="���" || work=="���" || work=="��" || work=="��" || work=="��"|| work=="��")
	 break;
	}
	}
	if(work=="���" || work=="���" || work=="���"|| work=="���" || work=="���" || work=="���" || work=="���" || work=="���")
	return 0;
	if(work=="��" || work=="��" || work=="��"|| work=="��")
	goto START;
    return 0;
}
