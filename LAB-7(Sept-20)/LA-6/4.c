#include<stdio.h>
int deque[5],front=-1,rear=-1;
int isFull()
{
    int f=((front==0)&&(rear==4)||(front==rear+1))?-1:1;
    return f;
}
int isEmpty()
{
    int e=(front==-1)?-1:1;
    return e;
}
void insertfront(int data)
{
    if((front==0)&&(rear==4)||(front==rear+1))
    {
        printf("\nDeQue Full\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(front==0) front=4;
    else front=front-1;
    deque[front]=data;
}
void insertrear(int data)
{
    if ((front==0)&&(rear==4)||(front==rear+1))
    {
        printf("\nDeQueue Full\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if (rear==4) rear=0;
    else rear=rear+1;
    deque[rear]=data;
}
void deletefront()
{
    if(front==-1)
    {
        printf("\nDeQue Empty\n");
        return;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==4) front=0;
    else front=front+1;
}
void deleterear()
{
    if(front==-1)
    {
        printf("\nDeQue Empty\n");
        return;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0) rear=4;
    else rear=rear-1;;
}
void peekFront()
{
    if(front!=-1) printf("\nPeek front: %d\n",deque[front]);
    else printf("\nDeQue Empty\n");
}
void peekRear()
{
    if(front==-1||rear==-1) printf("\nDeQue Empty\n");
    else printf("\nPeek rear = %d\n",deque[rear]);
}
void display()
{
    if(front!=-1)
    {
        printf("\nElements in DeQue are:\n");
        if(rear>=front)
            for(int i=front;i<=rear;i++)
                printf("%d\n",deque[i]);
        else
        {
            for(int i=0;i<5;i++)
                printf("%d\n",deque[i]);
        }
    }
    else printf("\nDeQue Empty\n");
}
int main()
{
    printf("\nInserting 2 item at front");
    insertfront(10);
    insertfront(20);
    display();
    printf("\nInserting 3 item at rear");
    insertrear(30);
    insertrear(40);
    insertrear(50);
    display();
    int e=isEmpty();
    if(e==1) printf("\nNot Empty!\n");
    else printf("\nEmpty!\n");
    int f=isFull();
    if(f==1) printf("\nNot Full!");
    else printf("\nFull!\n");
    printf("\nDeleting front");
    deletefront();
    display();
    printf("\nDeleting rear");
    deleterear();
    display();
    peekFront();
    peekRear();
    printf("\n\n");
    return 0;
}
