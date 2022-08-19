#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int t= *a;
    *a = *b;
    *b = t;
}
int partition(int *arr,int left,int right)
{
    int pivot=arr[right];
    int i=(left-1);
    for (int j=left;j<right;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
  swap(&arr[i+1],&arr[right]);
  return (i+1);
}
void quickSort(int *arr,int left,int right)
{
    if(left<right)
    {
        int p=partition(arr,left,right);
        quickSort(arr,left,p-1);
        quickSort(arr,p+1,right);
    }
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
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter Elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("\nUnsorted Array: ");
    printArray(arr,n);
    quickSort(arr,0,n-1);
    printf("Sorted Array: ");
    printArray(arr,n);
    printf("\n");
    return 0;
}
