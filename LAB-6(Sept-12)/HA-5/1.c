#include<stdio.h>
int stack[20],rstack[20],top=-1,rtop=-1;
void push(int data)
{
    if(top==19) printf("Stack is full!!\n\n");
    else
    {
        top++;
        stack[top]=data;
    }
}
int pop()
{
    if(top==-1) printf("Stack is empty!!\n\n");
    else
    {
        int temp=stack[top];
        top--;
        return temp;
    }
    return 0;
}
void rev()
{
    int i=top;
    if(i==19) printf("Stack is full!!\n\n");
    else
    {
        while(i!=-1)
        {
            rtop++;
            rstack[rtop]=pop();
            i--;
        }
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
void displayrev()
{
    if(rtop==-1) printf("Stack is empty!!\n\n");
    else
    {
        printf("\nStack is: \n");
        for(int i=rtop;i>-1;i--) printf("%d\n",rstack[i]);
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
    printf("Original Stack\n");
    display();
    printf("Reveresed Stack\n");
    rev();
    displayrev();
    return 0;
}
