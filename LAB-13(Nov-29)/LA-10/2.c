#include<stdio.h>
#include<stdlib.h>
int queue[20],front=-1,rear=-1;
int stack[20],top=-1;
void undirected(int **arr,int n)
{
    int i,j;
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                arr[i][j]=0;
                continue;
            }
            printf("Vertices %d & %d are Adjacent Nodes?(Yes=1/No=0): ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}
int isEmpty()
{
    if(front== -1 || front>rear)
        return 1;
    return 0;
}
void BFT(int start,int **arr,int n,int *visited)
{
    front=rear=0;
    queue[rear]=start;
    visited[start]=1;
    int temp;
    while (!isEmpty())
    {
        temp=queue[front];
        printf("%d ",temp);
        front++;
        for(int i=0;i<n;i++)
        {
            if(arr[temp][i]==1 && (!visited[i]))
            {
                queue[++rear]=i;
                visited[i]=1;
            }
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
    int n,start=0,ch;
    printf("\nEnter Number of Vertices: ");
    scanf("%d",&n);
    int **arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        arr[i]=(int*)malloc(n*sizeof(int));
    int *visited=(int*)malloc(n*sizeof(int));
    undirected(arr,n);
    while(1)
    {
        printf("\n0. Exit\n1. Show Matrix\n2. Breadth-First Traversal\n3. Depth-First Traversal");
        printf("\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                exit(0);
                break;
            case 1:
                printf("\n-----ADJECENT MATRIX-----\n");
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                        printf("%d ",arr[i][j]);
                    printf("\n");
                }
                printf("\n");
                break;
            case 2:
                for(int i=0;i<n;i++)
                    visited[i]=0;
                printf("\nEnter Starting Point: ");
                scanf("%d",&start);
                printf("\nBreadth-First Travaarsal: ");
                BFT(start,arr,n,visited);
                printf("\n");
                break;
            case 3:
                for(int i=0;i<n;i++)
                    visited[i]=0;
                printf("\nEnter Starting Point: ");
                scanf("%d",&start);
                printf("\nDepth-First Traversal: ");
                DFT(start,arr,n,visited);
                printf("\n");
                break;
            default:
                printf("Invalid Choice!!");
                break;
        }
    }
    return 0;
}
