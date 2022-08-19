#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=NULL;
    int i,j,n=0,temp;
    printf("Enter size of array: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(i=0;i<n;i++) scanf("%d",&ptr[i]);
    for(i=0,j=n-1;i<j;i++,j--)
    {
        temp=ptr[i];
        ptr[i]=ptr[j];
        ptr[j]=temp;
    }
    printf("In reverse order: ");
    for(i=0;i<n;i++) printf("%d ",ptr[i]);
    return 0;
}