#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int MOD=1000000007;
char A[MAXN];
int LeftPNumber[MAXN]={0};
int main()
{
	cin.getline(A,MAXN);
	int len=strlen(A);
	for(int i=0;i<len;i++)
	{
		if(i!=0)
		{
			LeftPNumber[i]=LeftPNumber[i-1];
		}
		if(A[i]=='P')
		{
			LeftPNumber[i]++;
		}
	}
	int ans=0;
	int RightTNumber=0;
	for(int j=len-1;j>=0;j--)
	{
		if(A[j]=='T')
		{
			RightTNumber++;
		}
		else if(A[j]=='A')
		{
			ans=(ans+RightTNumber*LeftPNumber[j])%MOD;
		}
	}
	printf("%d",ans);
	return 0;
}
