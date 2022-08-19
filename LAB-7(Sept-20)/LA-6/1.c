#include<stdio.h>
int queue[20],front=-1,rear=-1;
void enqueue(int data)
{
    if(rear==19) printf("\nOverflow\n");
    if(front==-1) front=0;
    rear=rear+1;
    queue[rear]=data;
}
int dequeue()
{
    if(front==-1) printf("\nUnderflow\n");
    int temp=queue[front];
    if(front==rear)
    {
        front=0;
        rear=0;
    }
    else front=front+1;
    return temp;
}
void display()
{
    printf("Queue is:-\n");
    for(int i=front;i<=rear;i++) printf("%d\n",queue[i]);
}
int peek()
{
    if(front==-1) printf("\nUnderflow\n");
    int temp=queue[front];
    return temp;
}
int isEmpty()
{
    int e = front!=-1?1:-1;
    return e;
}
int isFull()
{
    int f = rear!=19?1:-1;
    return f;
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    int e=isEmpty();
    if(e==1) printf("\nNot Empty!\n");
    else printf("\nEmpty!\n");
    int f=isFull();
    if(f==1) printf("\nNot Full!\n");
    else printf("\nFull!\n");
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
