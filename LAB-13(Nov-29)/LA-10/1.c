#include<stdio.h>
#include<stdlib.h>
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
    printf("\n-----ADJECENT MATRIX-----\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    printf("-------------------------\n");
    printf("\nVertex \t Degree ");
    for(i=0;i<n;i++)
    {
        deg=0;
        for(j=0;j<n;j++)
            if(arr[i][j]==1)
                deg++;
        printf("\n%d \t %d",i,deg);
    }
    printf("\n\n");
}
int main()
{
    int n;
    printf("\nEnter Number of Vertices: ");
    scanf("%d",&n);
    int **arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        arr[i]=(int*)malloc(n*sizeof(int));
    undirected(arr,n);
    return 0;
}
