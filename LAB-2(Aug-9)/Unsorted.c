#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=NULL;
    int i,n=0,a,b;
    printf("Enter size of array: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(i=0;i<n;i++) scanf("%d",&ptr[i]);
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);
    printf("Values between %d and %d are: ",a,b);
    for(i=0;i<n;i++)
    {
        if(ptr[i]==a){a=i;break;}
    }
    for(i=0;i<n;i++)
    {
        if(ptr[i]==b){b=i;break;}
    }
    for(i=a;i<=b;i++) printf("%d ",ptr[i]);
    printf("\nNumber of elements are: %d",abs(b-a)+1);
    return 0;
}