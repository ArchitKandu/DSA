#include<stdio.h>
#include<stdlib.h>
void directed(int **arr,int n)
{
    int i,j;
    int indeg,outdeg;
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
    printf("\nVertex\t  In-Degree\tOut-Degree\tTotal Degree");
    for(i=0;i<n;i++)
    {
        indeg=outdeg=0;
	    for(j=0;j<n;j++)
            if(arr[j][i]==1)
                indeg++;

        for(j=0;j<n;j++ )
            if(arr[i][j]==1)
                outdeg++;
        printf("\n  %d\t\t%d\t\t%d\t\t%d",i,indeg,outdeg,indeg+outdeg);
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
    directed(arr,n);
    return 0;
}
