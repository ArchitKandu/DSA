#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for (i=0;i<=n-1;i++) scanf("%d",&a[i]);
    printf("Reverse is: ");
    for(j=n-1;j>=0;j--) printf("%d ",a[j]);
    return 0;
}