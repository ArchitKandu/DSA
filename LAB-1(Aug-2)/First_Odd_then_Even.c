#include<stdio.h>
int main()
{
    int arr[100];
    int n,i;
    printf("Enter Number of elements: ");
    scanf("%d",&n);
    printf("Enter Elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Required results are: ");
    for(i=0;i<n;i++) if(arr[i]%2!=0) printf("%d ",arr[i]);
    
    for(i=0;i<n;i++) if(arr[i]%2==0) printf("%d ",arr[i]);
    return 0;
}