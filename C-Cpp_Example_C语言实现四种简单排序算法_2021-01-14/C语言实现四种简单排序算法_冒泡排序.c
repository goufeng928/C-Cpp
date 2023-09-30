#include <stdio.h>
int a[100];
void swap(int *pa,int *pb)
{
    int  t = *pa;
        *pa=*pb;
        *pb=t;
}
void bubbleSort(int left,int right)
{
    int i, sign;
    do
    {
        sign = 0;
        for(i=left; i<=right-1; i++)
        {
            if(a[i]>a[i+1]) 
            {
                swap(&a[i],&a[i+1]);
                sign = 1;
            }
        }
    }while(sign==1);
}
int main()
{
    int i;
    for(i=0; i<6; i++)  scanf("%d", &a[i]);
    bubbleSort(0,5);
    for(i=0; i<6; i++)  printf("%d ", a[i]);
    return 0;
}

