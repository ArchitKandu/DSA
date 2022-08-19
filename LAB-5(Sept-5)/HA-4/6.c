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
int countNodes()
{
    int count=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void printMiddle()
{
    int count=countNodes();
    struct node* temp=head;
    count/=2;
    while(count--)
    {
        temp = temp->next;
    }
    printf("\nThe middle element = %d\n\n",temp->data);
}
int main()
{
    getNode(1);
    getNode(2);
    getNode(3);
    getNode(4);
    getNode(5);
    printMiddle();
    return 0;
}
