#include <stdio.h>
int a[1000], r[1000];
void mergeSort(int left,int right)
{
    if(left==right)     return;
    int mid = (left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    int i=left, j=mid+1, k=left;
    while(i<=mid&&j<=right)
    {
        if(a[i]<=a[j])
        {
            r[k] = a[i];
            i ++;
            k ++;
        }else
        {
            r[k] = a[j];
            j ++;
            k ++;
        }
    }
    while(i<=mid)
    {
        r[k]=a[i];
        i++;
        k++;
    }
    while(j<=right)
    {
        r[k]=a[j];
        j ++;
        k ++;
    }
    for(i=left; i<=right; i++)  a[i]=r[i];
}
int main()
{
    int i;
    for(i=0; i<6; i++)  scanf("%d", &a[i]);
    mergeSort(0,5);
    for(i=0; i<6; i++)  printf("%d ", a[i]);
    return 0;
}

