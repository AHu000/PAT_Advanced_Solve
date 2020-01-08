#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

struct node{
	double num;//操作数 
	char op;//操作符 
	bool flag;
};
string str;
stack<node>s;//操作符栈 
queue<node>q;//后缀表达式序列 
map<char,int>op;

//将中缀表达式转换成后缀表达式 
void Change()
{
	double num;
	node temp;
	for(int i=0;i<str.length();)
	{
		if(str[i]>='0'&&str[i]<='9')//数字 
		{
			temp.flag=true;
			temp.num=str[i++]-'0';
			while(i<str.length()&&str[i]>='0'&&str[i]<='9')//>=10的数字输入方式                                                 
			{
				temp.num=temp.num*10+(str[i]-'0');
				i++;
			}
			q.push(temp);
		}
		else//+-*/四种操作符 
		{
			temp.flag=false;
			while(!s.empty()&&op[str[i]]<=op[s.top().op])
			{
				q.push(s.top());
				s.pop();
			}
			temp.op=str[i];
			s.push(temp);
			i++;
		}
	}	
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}

double Cal()
{
	double temp1,temp2;
	node cur,temp;
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(cur.flag==true)
		{
			s.push(cur);
		}
		else
		{
			temp2=s.top().num;
			s.pop();
			temp1=s.top().num;
			s.pop();
			temp.flag=true;
			if(cur.op=='+')temp.num=temp1+temp2;
			else if(cur.op=='-')temp.num=temp1-temp2;
			else if(cur.op=='/')temp.num=temp1/temp2;
			else temp.num=temp1*temp2;
			s.push(temp);
		}
	}
	return s.top().num;
}
 /*
 test
 input
 1+3*5/4*8/9*6*2/3/7+3*8/2
 output 
 14.90
 */
int main()
{
	op['+']=op['-']=1;//设定优先级 
    op['*']=op['/']=2;
    while(getline(cin,str),str!="0")
    {
    	for(string::iterator it = str.end();it!=str.begin();it--)//字符串的遍历 
    	{
    		if(*it==' ')
				str.erase(it);//去空格 
		}
		while(!s.empty())
			s.pop();
		Change();//将中缀表达式转换成后缀表达式 
		printf("%.2f\n",Cal());//计算出结果 
	}
} 
