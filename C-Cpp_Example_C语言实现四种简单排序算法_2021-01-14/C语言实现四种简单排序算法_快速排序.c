#include <stdio.h>
int a[1000];
void swap(int *pa,int *pb)
{
	int t = *pa;
		*pa=*pb;
		*pb = t;
}
void quickSort(int left,int right)
{
	int i=left, j=right;
	int mid = a[(left+right)/2];
	do
	{
		while(a[i]<mid)	i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(&a[i],&a[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(left<j)	quickSort(left,j);
	if(i<right)	quickSort(i,right);
}
int main()
{
	int i;
	for(i=0; i<6; i++)	scanf("%d", &a[i]);
	quickSort(0,5);
	for(i=0; i<6; i++)	printf("%d ", a[i]);
	return 0;
}
