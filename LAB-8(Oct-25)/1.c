#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
}*head=NULL;
struct node *getNode(int data,int priority)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->priority=priority;
    newNode->next = NULL;
    return newNode;
}
void push(int d, int p)
{
    struct node *temp=getNode(d,p);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        if(head->priority>p)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            while (head->next!=NULL && head->next->priority<p)
            {
                head=head->next;
            }
            temp->next=head->next;
            head->next=temp;
        }
    }
}
void pop()
{
    struct node *temp=head;
    head=head->next;
    free(temp);
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int ch,d,p;
    push(4,5);
    push(5,2);
    push(6,4);
    push(8,3);
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\n\nEnter data and priority: ");
                scanf("%d%d",&d,&p);
                push(d,p);
            }
            case 2:
            {
                pop();
            }
            case 3:
            {
                display();
            }
            case 0:
            {
                exit(0);
            }
            default:
            {
                printf("Invalid Choice!!!");
            }
        }
    }
    return 0;
}
