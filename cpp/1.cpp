#include<string.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
using namespace std;
int count,a[64],flag2;
int bat(char *str,const char *c)
{
	int i,flag=0,j;
	for(i=0,j=0;i<strlen(str);i++)
	{
		if(str[i]=='/'&&str[i+1]=='*')flag2=1;
		if(str[i+1]=='/'&&str[i]=='*')flag2=0;
		if(!flag2)
		{
			if(str[i]!='/'||str[i+1]!='/')	
		{
			if(j==strlen(c)){
			j=0;
			flag=1;
			count++;
		}
		if(c[j]==str[i])j++;
		else j=0;
		}
		else break;
		}	
	}
	if(flag)return 1;
	return -1;
}
int main(void)
{
	FILE *fp;
	int i=-1,flag1=0,j;
	char c[1024],str[64];
	cout<<"请输入将进行关键字统计的文件名：\n";
	cin>>str;
	fp=fopen(str,"r");
	if(fp==NULL)
	{
		cout<<"文件"<<str<<"打开失败！\n\a";
		return 0;
	}
	cout<<"正在读取文件 "<<str<<" ...\n";
	while(!feof(fp))
	{
		fgets(c,1024,fp);
		bat(c,"asm");
		bat(c,"auto");
		bat(c,"bool");
		bat(c,"break");
		bat(c,"catch");
		bat(c,"char");
		bat(c,"class");
		bat(c,"const");
		bat(c,"const_cast");
		bat(c,"continue");
		bat(c,"default");
		bat(c,"delete");
		bat(c,"do");
		bat(c,"double");
		bat(c,"dynamic_cast");
		bat(c,"else");
		bat(c,"enum");
		bat(c,"explicit");
		bat(c,"export");
		bat(c,"extern");
		bat(c,"false");
		bat(c,"do");
		bat(c,"float");
		bat(c,"for");
		bat(c,"friend");
		bat(c,"do");
		bat(c,"goto");
		bat(c,"if");
		bat(c,"inline");
		bat(c,"int");
		bat(c,"long");
		bat(c,"mutable");
		bat(c,"namespace");
		bat(c,"new");
		bat(c,"operator");
		bat(c,"private");
		bat(c,"protected");
		bat(c,"public");
		bat(c,"register");
		bat(c,"reinterpret_cast");
		bat(c,"return");
		bat(c,"short");
		bat(c,"signed");
		bat(c,"sizeof");
		bat(c,"static");
		bat(c,"static_cast");
		bat(c,"struct");
		if(1==bat(c,"switch"))
		i++;
		flag1=count;
		if(bat(c,"case")==1)
			a[i]+=count-flag1;
		bat(c,"template");
		bat(c,"this");
		bat(c,"throw");
		bat(c,"true");
		bat(c,"try");
		bat(c,"typedef");
		bat(c,"typeid");
		bat(c,"typename");
		bat(c,"union");
		bat(c,"unsigned");
		bat(c,"using");
		bat(c,"virtual");
		bat(c,"void");
		bat(c,"volatile");
		bat(c,"wchar_t");
	}
	cout<<"total num:"<<count<<endl;
	cout<<"\nswitch num:"<<i+1<<endl<<"case num:";
	for(j=0;j<=i;j++)
	cout<<a[j]<<"\t";
	cout<<endl;
	return 0;
 } 
