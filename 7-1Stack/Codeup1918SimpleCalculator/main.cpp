#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

struct node{
	double num;//������ 
	char op;//������ 
	bool flag;
};
string str;
stack<node>s;//������ջ 
queue<node>q;//��׺���ʽ���� 
map<char,int>op;

//����׺���ʽת���ɺ�׺���ʽ 
void Change()
{
	double num;
	node temp;
	for(int i=0;i<str.length();)
	{
		if(str[i]>='0'&&str[i]<='9')//���� 
		{
			temp.flag=true;
			temp.num=str[i++]-'0';
			while(i<str.length()&&str[i]>='0'&&str[i]<='9')//>=10���������뷽ʽ                                                 
			{
				temp.num=temp.num*10+(str[i]-'0');
				i++;
			}
			q.push(temp);
		}
		else//+-*/���ֲ����� 
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
	op['+']=op['-']=1;//�趨���ȼ� 
    op['*']=op['/']=2;
    while(getline(cin,str),str!="0")
    {
    	for(string::iterator it = str.end();it!=str.begin();it--)//�ַ����ı��� 
    	{
    		if(*it==' ')
				str.erase(it);//ȥ�ո� 
		}
		while(!s.empty())
			s.pop();
		Change();//����׺���ʽת���ɺ�׺���ʽ 
		printf("%.2f\n",Cal());//�������� 
	}
} 
