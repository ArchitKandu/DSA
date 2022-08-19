#include<stdio.h>
int main()
{
    int arr[50];
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter the values of Array: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Values are: ");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}