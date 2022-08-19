#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head=NULL,*tail=NULL;

void getNode(int data)
{
    if (head==NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=newnode->prev=newnode;
        head=newnode;
        return;
    }
    tail=head->prev;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=tail;
    tail->next=newnode;
}

void display(struct node *head)
{
    struct node *temp=head;
    printf("\n\n");
    while (temp->next!=head)
    {
        printf("%d <-> ", temp->data);
        temp=temp->next;
    }
    printf("%d ", temp->data);
    printf("\n\n");
}

int main(){
    struct node *start=NULL;
    getNode(1);
    getNode(2);
    getNode(3);
    getNode(4);
    getNode(5);
    display(head);
    return 0;
}
