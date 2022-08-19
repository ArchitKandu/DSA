#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head=NULL,*tail=NULL;
void getNode(int data)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=head;
    }
    else
    {
        tail->next=newNode;
        tail=tail->next;
    }
}
struct node *middle(struct node *head,struct node *tail)
{
    if(head==NULL)
        return NULL;
    int n=1;
    struct node *temp=head;
    while(temp!=tail)
    {
        n++;
        temp=temp->next;
    }
    n=n/2;
    temp=head;
    while(n--)
        temp=temp->next;
    return temp;
}
struct node *binarySearch(int value)
{
    while(head!=NULL)
    {
        struct node *mid=middle(head,tail);
        if(mid==NULL)
            return NULL;
        if(mid->data==value)
            return mid;
        else if(mid->data<value)
            head=mid->next;
        else
            tail=mid;
    }
    return NULL;
}
int main()
{
    int ch,data,value;
    while(1)
    {
        printf("\n0. Exit\n1. Insert\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter Data: ");
            scanf("%d",&data);
            getNode(data);
        }
        else break;
    }
    printf("\nEnter Value to Search: ");
    scanf("%d",&value);
    struct node *result=binarySearch(value);
    if(result==NULL) printf("\nValue Not Found!!\n\n");
    else printf("%d is Found!!\n\n",value);
    return 0;
}
