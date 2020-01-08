#include<cstdio>

int binaryReserch(int A[],int left,int right,int x)
{
	int mid;
	while(left<=right)
	{
		mid=(right+left)/2;
		if(A[mid]==x)
		{
			return mid;
		}
		else if(A[mid]>x)
		{
			right= mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
 } 
 
 int main()
 {
 	const int maxn=10;
 	int A[maxn]={1,5,7,9,11,13,17,19,23,27};
 	printf("%d %d",binaryReserch(A,0,maxn-1,11),binaryReserch(A,0,maxn-1,23));
 	return 0;
 }
