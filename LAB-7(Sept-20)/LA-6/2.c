#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *next;
}*front=NULL,*rear=NULL;
void isEmpty()
{
    int e= front!=NULL?1:-1;
    if(e==1) printf("\nNot Empty!\n");
    else printf("\nEmpty!\n");
}
void enqueue(int data)
{
    struct queue *newNode=(struct queue*)malloc(sizeof(struct queue));
    newNode->data=data;
    newNode->next=NULL;
    if(front==NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}
int dequeue()
{
    if(front==NULL) printf("\nUnderflow\n");
    else
    {
        struct queue *temp=front;
        int tmp=temp->data;
        front=front->next;
        free(temp);
        return tmp;
    }
    return 0;
}
int peek()
{
    if(front==NULL) printf("\nUnderflow\n");
    else
    {
        struct queue *temp=front;
        int tmp=temp->data;
        return tmp;
    }
    return 0;
}
void display()
{
    struct queue *temp=front;
    printf("Queue is:\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    isEmpty();
    printf("\nInitial:\n");
    display();
    printf("\nAdding 60:\n");
    enqueue(60);
    display();
    printf("\nDequeued element %d\n",dequeue());
    display();
    printf("\nPeeked element is %d\n\n",peek());
    return 0;
}
