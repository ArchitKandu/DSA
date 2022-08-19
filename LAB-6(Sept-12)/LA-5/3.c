#include<stdio.h>
#include<ctype.h>
char stack[50];
int top=-1;
void push(char data)
{
    top++;
    stack[top]=data;
}
char pop()
{
    return stack[top--];
}
int priority(char x)
{
    if(x=='(')
        return 1;
    if(x == '+' || x == '-')
        return 2;
    if(x == '*' || x == '/')
        return 3;
    return 0;
}
int main()
{
    char exp[100];
    char *e, x;
    printf("\nEnter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e=exp;
    printf("Result is: ");
    while(*e!='\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x=pop())!='(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    printf("\n\n");
    return 0;
}
