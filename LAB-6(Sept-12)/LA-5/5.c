#include<stdio.h>
char stack[50];
int top=-1,len;
void push(char data)
{
    top++;
    stack[top]=data;
}
void pop()
{
    stack[top--];
}
int d(char a)
{
    if((a=='(')||(a==')')) return 1;
    else if((a=='{')||(a=='}')) return 2;
    else if((a=='[')||(a==']')) return 3;
    return 0;
}
void check(char *e)
{
    int temp1,temp2;
    while(*e!='\0')
    {
        if((*e=='(')||(*e=='{')||(*e=='['))
            push(*e);
        else
        {
            if(stack[top]=='\0')
            {
                printf("Result is: NO\n\n");
                break;
            }
            else
            {
                temp1=d(stack[top]);
                temp2=d(*e);
                if(temp1==temp2) pop();
                else
                {
                    printf("Result is: NO\n\n");
                    break;
                }
            }
        }
        e++;
    }
    if(stack[top]=='\0') printf("Result is: YES\n\n");
}
int main()
{
    char exp[25];
    printf("\nEnter Exp: ");
    scanf("%s",exp);
    char *e=exp;
    check(e);
    return 0;
}
