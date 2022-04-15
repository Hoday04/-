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
    cout<<"Желаете начать?(Да/Нет)"<<endl;
    cin>>work;
    if(work=="НЕТ" || work=="Нет" || work=="НЕт"|| work=="НеТ" || work=="нет" || work=="нЕт" || work=="неТ" || work=="нЕТ")
    return 0;
    START:
	if(work=="ДА" || work=="Да" || work=="да"|| work=="дА")
	{
    int l1,h1,l2,h2;
    int a,b,p,c;
    cout<<"Введите число матриц(не больше 2):"<<endl;
    cin>>p;
    if(p<=0 || p>2)
    {
    cout<<"Ошибка";
	return 0;	
	}
	if(p==1)
	{
		cout<<"Введите количество строк матрицы"<<endl;
		cin>>l1;
		cout<<"Введите количество столбцов матрицы"<<endl;
		cin>>h1;
	}
	else if(p==2)
	{
		cout<<"Введите количество строк 1 матрицы"<<endl;
		cin>>l1;
		cout<<"Введите количество столбцов 1 матрицы"<<endl;
		cin>>h1;
		cout<<"Введите количество строк 2 матрицы"<<endl;
		cin>>l2;
		cout<<"Введите количество столбцов 2 матрицы"<<endl;
		cin>>h2;
	}
	int m[2][2],n[2][2];
    cout<<"Если вы хотите вводить матрицу с консоли,то введите 1,если"<<endl<<"же вы хотите, чтобы программа взяла данные из файлов, то введите 2"<<endl;
    cin>>a;
    if(a==1)
    {
    //Ввод матриц с консоли
    cout<<"1 матрица:"<<endl;
	for(int i=0;i<l1;i++)
	    {
		for (int j=0;j<h1;j++)
		cin>>m[i][j];
		}
	if (p>1)
	{	
	cout<<"2 матрица:"<<endl;
	for(int i=0;i<l2;i++)
	    {
		for (int j=0;j<h2;j++)
		cin>>n[i][j];
		}
	}
    }
	//Ввод матриц с файлов
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
    cout<<"Ошибка";
	return  0;	
	}	
    //Вывод матриц
	cout<<"1 матрица:"<<endl;
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
	cout<<"2 матрица:"<<endl;
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
	//Действия над матрицами
	if (p>1)
	{
	cout<<"Какое действие вы хотите произвести над матрицами?"<<endl;
	cout<<"Выберите из ниже перечисленных:"<<endl;
	cout<<"1)Сложение матриц"<<endl;
	cout<<"2)Вычитание матрицы из матрицы"<<endl;
	cout<<"3)Умножение матрицы на число"<<endl;
	cout<<"4)Умножение матрицы на матрицу"<<endl;
	cout<<"5)Возведение матрицы в сетпень"<<endl;
	cout<<"6)Транспонирование матрицы"<<endl;
    }
    else if (p==1)
    {
    cout<<"Какое действие вы хотите произвести над матрицами?"<<endl;
	cout<<"Выберите из ниже перечисленных:"<<endl;
	cout<<"3)Умножение матрицы на число"<<endl;
	cout<<"5)Возведение матрицы в сетпень"<<endl;
	cout<<"6)Транспонирование матрицы"<<endl;	
	}
	else
    {
    cout<<"Ошибка";
	return 0;	
	}
	cin>>b;
	//Сложение
	if(b==1)
	{
	int sum[l1][h1];
	if(l1==l2 && h1==h2)
	{
	cout<<"Итоговая матрица:"<<endl;
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
    cout<<"Ошибка.Нельзя сложить данные матрицы.";
    goto ret;	
	}
	}
	//Разница
	if(b==2)
	{
	int raz[l1][h1];
	cout<<"От какой матрицы хотите отнимать другую:"<<endl;
	cin>>c;
	if(l1==l2 && h1==h2)
	if(c==1)
	{
	cout<<"Итоговая матрица:"<<endl;
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
	cout<<"Итоговая матрица:"<<endl;
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
    cout<<"Ошибка.Нельзя отнять.";
    goto ret;
	}
	}
	//Умножение на число 
	if(b==3)
	{
	int ch[l1][h1],x;
	if(p>1)
	{
	cout<<"Какую матрицу нужно умножить на число:"<<endl;
	cin>>c;
	if(c==1)
	Round:
	{
	cout<<"Введите число:"<<endl;
	cin>>x;
	cout<<"Итоговая матрица:"<<endl;
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
	cout<<"Введите число:"<<endl;
	cin>>x;
	cout<<"Итоговая матрица:"<<endl;
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
	cout<<"Ошибка.Введите 1,если 1 матрицу, иначе введите 2:"<<endl;
	cin>>c;	
	goto round;
	}
	else
	goto Round;	
	}
	}
	else if(p==1)
	{
	cout<<"Введите число:"<<endl;
	cin>>x;
	cout<<"Итоговая матрица:"<<endl;
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
    //Умножение
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
	cout<<"Итоговая матрица:"<<endl;
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
	 cout<<"Ошибка";	
	 return 0;
	}
	ret:
	cout<<"Хотите продолжить?"<<endl;
	cin>>work;
	if(work=="НЕТ" || work=="Нет" || work=="НЕт"|| work=="НеТ" || work=="нет" || work=="нЕт" || work=="неТ" || work=="нЕТ")
	return 0;
	if(work=="ДА" || work=="Да" || work=="да"|| work=="дА")
	goto START;
	else if(work!="ДА" || work!="Да" || work!="да"|| work!="дА" || work!="НЕТ" || work!="Нет" || work!="НЕт"|| work!="НеТ" || work!="нет" || work!="нЕт" || work!="неТ" || work!="нЕТ")
	{
	 while (work!="ДА" || work!="Да" || work!="да"|| work!="дА" || work!="НЕТ" || work!="Нет" || work!="НЕт"|| work!="НеТ" || work!="нет" || work!="нЕт" || work!="неТ" || work!="нЕТ")
	{
	 cout<<"Ошибка.Введите 'Да',если хотите начать,иначе введите 'Нет'"<<endl;
	 cin>>work;
	}
	}
	}
		else if(work!="ДА" || work!="Да" || work!="да"|| work!="дА" || work!="НЕТ" || work!="Нет" || work!="НЕт"|| work!="НеТ" || work!="нет" || work!="нЕт" || work!="неТ" || work!="нЕТ")
	{	
	 while (work!="ДА" || work!="Да" || work!="да"|| work!="дА" || work!="НЕТ" || work!="Нет" || work!="НЕт"|| work!="НеТ" || work!="нет" || work!="нЕт" || work!="неТ" || work!="нЕТ")
	{
	 cout<<"Ошибка.Введите 'Да',если хотите начать,иначе введите 'Нет'"<<endl;
	 cin>>work;
	 if(work=="НЕТ" || work=="Нет" || work=="НЕт"|| work=="НеТ" || work=="нет" || work=="нЕт" || work=="неТ" || work=="нЕТ" || work=="ДА" || work=="Да" || work=="да"|| work=="дА")
	 break;
	}
	}
	if(work=="НЕТ" || work=="Нет" || work=="НЕт"|| work=="НеТ" || work=="нет" || work=="нЕт" || work=="неТ" || work=="нЕТ")
	return 0;
	if(work=="ДА" || work=="Да" || work=="да"|| work=="дА")
	goto START;
    return 0;
}
