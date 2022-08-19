#include<stdio.h>
int main()
{
    int arr[100];
    int sum=0,i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter the values of Array: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    for (i=0;i<n;i++) sum=sum+arr[i];
    printf("Sum of array is: %d",sum);
    return 0;
}