#include<stdio.h>
#include<stdlib.h>
int stack[20],top=-1;
void undirected(int **arr,int n)
{
    int i,j,deg;
    int ans;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                arr[i][j]=0;
                continue;
            }
            printf("\nVertices %d & %d are Adjacent Nodes?(Yes=1/No=0): ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}
void DFT(int start,int **arr,int n,int *visited)
{
    int i,k;
    stack[++top]=start;
    visited[start]=1;
    k=stack[top--];
    printf("%d ",k);
    while(top!=-1)
    {
        for(i=0;i<n;i++)
            if((arr[k][i]!=0) && (visited[i]==0))
            {
                stack[top++]=i;
                visited[i]=1;
            }
        k=stack[top--];
        if(k!=0)
            printf("%d ",k);
    }
    for(i=0;i<n;i++)
        if(visited[i]==0)
            DFT(i,arr,n,visited);
}
int main()
{
    int n;
    printf("\nEnter Number of Vertices: ");
    scanf("%d",&n);
    int **arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        arr[i]=(int*)malloc(n*sizeof(int));
    int *visited=(int*)malloc(n*sizeof(int)); 
    undirected(arr,n);
    for(int i=0;i<n;i++)
        visited[i]=0;
    return 0;
}
