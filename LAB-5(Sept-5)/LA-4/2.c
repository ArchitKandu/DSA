#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
} *head=NULL,*tail=NULL;
void getNode(int data)
{
    struct node *newnode;
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        tail=head;
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->prev=tail;
        newnode->next=NULL; 
        tail->next=newnode;
        tail=newnode;
    }
}
void printList(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void reverse()
{
    struct node *current, *temp;
    current=head;
    while(current!=NULL)
    {
        temp=current->next;
        current->next=current->prev;
        current->prev=temp;
        current = temp;
    }
    temp=head;
    head=tail;
    tail=temp;
}
int main()
{
    int n;
    printf("\nEnter total Elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num;
        printf("Enter Number: ");
        scanf("%d",&num);
        getNode(num);
    }
    printf("\n\nLL is: ");
    printList(head);
    printf("\n");
    reverse();
    printf("Reverse LL is: ");
    printList(head);
    printf("\n\n");
    return 0;
}
