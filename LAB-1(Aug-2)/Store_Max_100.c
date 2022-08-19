#include<stdio.h>
int main()
{
    int arr[100];
    int i,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter the values of Array: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("3-digits Even numbers in array are: ");
    for(i=0;i<n;i++)
    {
        if((arr[i]>=100)&&(arr[i]<1000))
        {
            if (arr[i]%2==0) printf("%d ",arr[i]);
        }
        else continue;
    }
    return 0;
}