/*
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int N,p,A[maxn];

int main()
{
	scanf("%d %d",&N,&p);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	sort(A,A+N);//AΪ�����׵�ַ��A+NΪ�������һ��Ԫ�ض�Ӧ��ַ 
	int minN=A[0];
	int maxN=A[N-1];
	long long Bound=minN*p;
	long long count=0;
	for(int i=0;i<N;i++)
	{
		if(A[i]<=Bound)
		{
			count++;
		}
	}
	printf("%d",count);
	int ans=1;//��¼ans 
	for(int i=0;i<N;i++)
	{
		//upper_bound��¼�ľ��Ǹôζ��ֲ���������Ӧ���Ǹ����� 
		int j=upper_bound(A+i+1,A+N,(long long)A[i]*p)-A;
		ans=max(ans,j-i);
	} 
	printf("%d",ans);
	return 0;
}
*/ 

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int A[maxn],N,p;
int main()
{
	scanf("%d %d",&N,&p);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	int ans=1,j;
	for(int i=0;i<N;i++)
	{
		j=upper_bound(A+i+1,A+N,(long long)A[i]*p)-A;
		ans=max(ans,j-i);//��û��� 
	}
	printf("%d",ans);
	return 0;
}

