#include<stdio.h>
int main()
{
    int arr[100];
    int n,i,temp;
    printf("Enter Number of elements: ");
    scanf("%d",&n);
    printf("Enter Elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("\nOriginal values: ");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    for(i=0;i<n;i+=2)
    {
        temp=0;
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    printf("\n\nSwapped values: ");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}