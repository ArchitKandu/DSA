#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j;
    int max;
    printf("Enter Number of elements: ");
    scanf("%d",&n);
    printf("Enter elements of array: ");
    for (i=0;i<n;i++) scanf("%d",&a[i]);

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if((a[i]<a[j])&&(max<a[j]))
            {
                if (a[j]%2==0) max=a[j];
            }
        }
    }
    printf("Max even number is: %d",max);
    return 0;
}