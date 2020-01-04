#include<cstdio>
int lower_bound(int A[],int right,int left,int x)
{
	int mid;
	while(left<=right)
	{
		mid=left+(right-left)/2;
		if(A[mid]>=x)
		{
			right=mid;
		}
		else
		{
			left=mid+1;
		}
	}
	return left;
}

int main()
{
	return 0;
}

