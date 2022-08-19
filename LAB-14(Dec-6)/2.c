#include<stdio.h>
#include<stdlib.h>
void mergeSort(int left,int mid,int right,int *a,int *b)
{
    int s1,s2,i;
    for(s1=left,s2=mid+1,i=left;s1<=mid && s2<=right;i++) 
    { 
        if(a[s1]<=a[s2])
            b[i]=a[s1++]; 
        else 
            b[i] = a[s2++]; 
    }
    while(s1<=mid) 
        b[i++]=a[s1++]; 
    while(s2<=right)
        b[i++]=a[s2++]; 
    for(i=left;i<=right;i++) 
        a[i]=b[i];
}
void sort(int left,int right,int *a,int *b)
{ 
    int mid; 
    if(left<right) 
    { 
        mid=(left+right)/2; 
        sort(left,mid,a,b); 
        sort(mid+1,right,a,b); 
        mergeSort(left,mid,right,a,b); 
    } 
    else return;
}
void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int n;
    printf("\nEnter Size: ");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    int *b=(int*)malloc(n*sizeof(int));
    printf("Enter Elements: ");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) b[i]=0;
    printf("\nUnsorted Array: ");
    printArray(a,n);
    sort(0,n-1,a,b);
    printf("Sorted Array: ");
    printArray(b,n);
    printf("\n");
    return 0;
}
