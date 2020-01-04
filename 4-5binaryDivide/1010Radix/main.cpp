#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;
char Map[256];
LL inf = (1LL << 63)-1;//2^63-1

void Init()
{
	for(char c='0';c<='9';c++)
	{
		Map[c]=c-'0';
	}
	for(char c='a';c<='z';c++)
	{
		Map[c]=c-'a'+10;
	}
}

  -++/////////////**++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                                          
struct Num{
	int radix;
	char number[15];
}num[1];

int main()
{
	int radix,tag;
	scanf("%s %s %d %d",num[0].number,num[1].number,&tag,&radix);
	if(tag==1){
		num[0].radix=radix;
	}
	else{
		num[1].radix=radix;
	}

	return 0;
} 
