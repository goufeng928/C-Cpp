#include <stdio.h>
int a[1000];
void swap(int *pa,int *pb)
{
    int t = *pa;
        *pa=*pb;
        *pb = t;
}
void selectSort(int left,int right)
{
    int i, j;
    for(i=left; i<right; i++)
    {
        int min=i;
        for(j=i+1; j<=right; j++)
        {
            if(a[min]>a[j])  min=j; 
        }
        swap(&a[i],&a[min]);
    }
}
int main()
{
    int i;
    for(i=0; i<6; i++)  scanf("%d", &a[i]);
    selectSort(0,5);
    for(i=0; i<6; i++)  printf("%d ", a[i]);
    return 0;
}

