#include<stdio.h>
int stack[20],top=-1,a[20],at=-1;
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
void display(int temp[],int n)
{
    if(n==-1) printf("Stack is empty!!\n\n");
    else
    {
        printf("Stack is: \n");
        for(int i=n;i>-1;i--) printf("%d\n",temp[i]);
        printf("\n");
    }
}
void sort()
{
    int i,j;
    int temp,temp1;
    while(top!=-1)
    {
        temp=pop();
        while(at!=-1 && a[at]>temp)
        {
            temp1=a[at];
            at--;
            push(temp1);
        }
        a[++at]=temp;
    }
    display(a,at);
}
int main()
{
    push(40);
    push(20);
    push(50);
    push(30);
    push(10);
    printf("\nBefore Sorting\n");
    display(stack,top);
    printf("After Sorting\n");
    sort();
    return 0;
}
