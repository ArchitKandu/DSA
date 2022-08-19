#include<stdio.h>
int stack[20],top=-1,temp[20],t=-1;
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
void display()
{
    if(top==-1) printf("Stack is empty!!\n\n");
    else
    {
        printf("Stack is: \n");
        for(int i=top;i>-1;i--) printf("%d\n",stack[i]);
        printf("\n");
    }
}
void bubblesort()
{
    int tmp,tmp1;
    int i=0,n=top;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            while(top!=-1)
            {
                tmp=pop();
                ++t;
                while(temp[t]<tmp)
                {
                    temp[t]=top;
                }
                if(temp[t]>tmp)
                {
                    tmp1=tmp;
                    temp[t]=tmp;
                    tmp=tmp1;
                    push(tmp);
                }
            }
        }
        temp[n-1-i]=pop();
    }
    for(int j=t;j>-1;j--) push(temp[j]);
}
int main()
{
    push(40);
    push(20);
    push(50);
    push(30);
    push(10);
    push(60);
    printf("\nBefore Sorting\n");
    display();
    printf("After Sorting\n");
    bubblesort();
    display();
    return 0;
}
