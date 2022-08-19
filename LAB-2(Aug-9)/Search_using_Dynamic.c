#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=NULL;
    int i,n=0,s,m;
    printf("Enter size of array: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(i=0;i<n;i++) scanf("%d",&ptr[i]);
    printf("Enter the value you want to search: ");
    scanf("%d",&s);
    for(i=0;i<n;i++)
    {
        if(s==ptr[i]) printf("%d is the %d term.",s,i+1);
    }
    return 0;
}