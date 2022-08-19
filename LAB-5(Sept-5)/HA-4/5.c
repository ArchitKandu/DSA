#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head=NULL,*tail=NULL;
struct node *getNode(int data)
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
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void move(struct node *head)
{
    struct node *p, *q;
    p=q=head;
    printf("\nPointer at %d\n", head->data);
    printf("\nMoving Front:\n ");
    if(q->next!=NULL)
    {
        q = q->next;
        printf("Pointer at %d\n", q->data);
    } 
    else
    printf("Pointer at last node %d. Cannot move ahead.\n", q->data);
    printf("\nMoving Back:\n ");
    while (p->next!=q) 
        p=p->next;
    if (p==q) printf("Pointer at first node %d. Cannot move behind.\n", q->data);
    else
    {
        q=p;
        p=head;
        printf("Pointer at %d\n\n", q->data);
    }
}
int main()
{
    getNode(1);
    getNode(2);
    getNode(3);
    getNode(4);
    getNode(5);
    printf("\nDisplaying Node: ");
    display(head);
    move(head);
    return 0;
}
