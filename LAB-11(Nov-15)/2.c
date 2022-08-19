#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL, *tail=NULL;
void insert(int data)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL) head=tail=newNode;
    else
    {
        tail->next=newNode;
        tail=tail->next;
    }
}
void removeloop(struct node*);
void detect(struct node *head)
{
    struct node *ptr1=head, *ptr2=head;
    while(ptr1 && ptr2 && ptr2->next)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
        if(ptr1==ptr2)
        {
            printf("\nThe List Contains Loop!!");
            printf("\nAfter removing loop: ");
            removeloop(ptr1);
            return;
        }
    }
    printf("\nThe List doesn't contain Loop!!");
}
void removeloop(struct node *temp)
{
    struct node *ptr1=temp;
    struct node *ptr2=temp;
    int k=1,i;
    while (ptr1->next!=ptr2)
    {
        ptr1=ptr1->next;
        k++;
    }
    ptr1=head;
    ptr2=head;
    for (i=0;i<k;i++)
        ptr2=ptr2->next;
    while(ptr2!=ptr1)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    while(ptr2->next!=ptr1)
        ptr2 = ptr2->next;
    ptr2->next = NULL;
}
void display()
{
    if(head==NULL) printf("Empty List!!");
    else
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n\n");
    }
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    head->next->next->next->next->next=head->next;
    detect(head);
    display(head);
    return 0;
}
