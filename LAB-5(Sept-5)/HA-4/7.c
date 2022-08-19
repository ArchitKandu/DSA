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
            printf("%d<->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n\n");
    }
}
void rotateByK(int k)
{
    while(k--)
    {
        struct node *temp=head;
        int t=temp->data;
        while(temp->next)
        {
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp->data = t;
    }
}
int main()
{
    getNode(10);
    getNode(20);
    getNode(30);
    getNode(40);
    getNode(50);
    getNode(60);
    printf("\nOrignal List: ");
    printList(head);
    rotateByK(4);
    printf("List rotated by 4: ");
    printList(head);
    return 0;
}
