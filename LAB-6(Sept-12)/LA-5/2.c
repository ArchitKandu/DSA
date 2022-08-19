#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
} *top=NULL;
int isEmpty()
{
    int x=top!=NULL?1:-1;
    return x;
}
void push(int data)
{
    if(top==NULL)
    {
        top=(struct stack*)malloc(sizeof(struct stack));
        top->data=data;
        top->next=NULL;
    }
    else
    {
        struct stack *newNode=(struct stack*)malloc(sizeof(struct stack));
        newNode->next=top;
        newNode->data=data;
        top=newNode;
    }
}
void pop()
{
    struct stack *tempTop=top;
    if(tempTop==NULL)
    {
        printf("Empty stack\n\n");
        return;
    }
    else
    {
        tempTop=tempTop->next;
        printf("\nDeleted Value: %d",top->data);
        free(top);
        top=tempTop;
    }
}
void display()
{
    struct stack *temp=top;
    printf("\nStack is:\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    int x=isEmpty();
    x==1?printf("\nNot Empty!!!\n"):printf("\nEmpty!!!\n");
    display();
    printf("After pushing 60\n");
    push(60);
    display();
    printf("After poping 60\n");
    pop();
    display();
    return 0;
}
