#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[50],prefix[50];
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
int precedence(char ch)
{
    if(ch==')')
        return 1;
    if(ch=='+'||ch=='-')
        return 2;
    if (ch=='*'||ch=='/')
        return 3;
    return 0;
}
void check(char *e)
{
    int i=0;
    char x;
    strrev(e);
    while (*e!='\0')
    {
        if (isalnum(*e))
        {
            prefix[i]=*e;
            i++;
        }
        else if (*e==')')
        {
            push(*e);
        }
        else if (*e== '(')
        {
           while((x=pop())!=')')
                prefix[i++]=x;
        }
        else
        {
            while(precedence(stack[top])>=precedence(*e))
                prefix[i++]=pop();
            push(*e);
        }
        e++;
    }
    while (top!=-1)
    {
        prefix[i]=pop();
        i++;
    }
    strrev(prefix);
    prefix[i]='\0';
    printf("EQUIVALENT PREFIX NOTATION : %s\n\n", prefix);
}
int main()
{
    char exp[25];
    printf("\nEnter infix: ");
    scanf("%s",exp);
    char *e=exp;
    check(e);
    return 0;
}
