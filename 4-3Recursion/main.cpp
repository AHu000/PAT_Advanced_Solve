#include<cstdio>
const int maxn=11;
int n,P[maxn],HashTable[maxn]={false};

void Pgenerate(int index)
{
	if(index==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d",P[i]);
		}
		printf("\n");
		return ;
	}
	for(int x=0;x<=n;x++)
	{
		if(HashTable[x]==false)
		{
			P[index]=x;
			HashTable[x]=true;
			Pgenerate(index+1);
			HashTable[x]=false;
		}
	}
}
int F(int N)
{
	if (N!=0)
	{
		return F(N-1)*N;
	}
	else
	{
		return 1;
	}
 } 
 int Fibonacci(int N)
 {
 	if(N==0||N==1)
 	{
 		return 1;
	 }
	 else
	 {
	 	return Fibonacci(N-1)+Fibonacci(N-2);
	 }
 }
 
 int main()
 {
	scanf("%d",&n);
	Pgenerate(1);
	return 0;
 }
