#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head=NULL,*tail=NULL;
void getNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
    if(head==NULL)
    {   
        head=newNode;  
        tail=newNode;  
    }  
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}
int mthlast(int n)
{
    struct node *p, *q;
    int i;
    q=p=head;
    for (i=1;i<n && q!=NULL;i++) q=q->next;
    if (i<n) printf("Invalid Input. Please try again.\n");
    else
    {
        while (q->next != NULL)
        {
            q=q->next;
            p=p->next;
        }
    }
    return p->data;
}
int main()
{
    int m,n;
    printf("\nEnter total: ");
    scanf("%d",&n);
    while(n--)
    {
        int num;
        printf("Enter a number: ");
        scanf("%d",&num);
        getNode(num);
    }
    printf("\nEnter m: ");
    scanf("%d",&m);
    printf("The %dth term from last is: %d\n\n",m,mthlast(m));
    return 0;
}
