#include<stdio.h>
int stack[20],top=-1;
void isEmpty()
{
    if(top!=-1) printf("\nNot Empty!!!\n");
    else printf("\nEmpty!!!\n");
}
void push(int data)
{
    if(top==19) printf("Stack is full!!\n\n");
    else
    {
        top++;
        stack[top]=data;
    }
}
void pop()
{
    if(top==-1) printf("Stack is empty!!\n\n");
    else
    {
        printf("\nDeleted Item is: %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1) printf("Stack is empty!!\n\n");
    else
    {
        printf("\nStack is: \n");
        for(int i=top;i>-1;i--) printf("%d\n",stack[i]);
        printf("\n");
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    isEmpty();
    display();
    printf("After pushing 60\n");
    push(60);
    display();
    printf("After poping 60\n");
    pop();
    display();
    return 0;
}
