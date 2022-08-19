#include<stdio.h>
int main()
{
    int arr[10];
    int i;
    printf("Enter elements: ");
    for (i=0;i<10;i++) scanf("%d",&arr[i]);
    printf("Elements are: ");
    for (i=0;i<10;i++) printf("%d ",arr[i]);
    return 0;
}