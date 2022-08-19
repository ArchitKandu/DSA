#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j,temp;
    printf("Enter Number of elements: ");
    scanf("%d",&n);
    printf("Enter elements of array: ");
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    printf("\nValues are: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    for(j=0;j<n-1;j++)
    {
        for (i=0;i<(n-1);i++)
    {
        if(a[i]>a[i+1])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    }
    printf("\n\nElements in Ascending order are: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}