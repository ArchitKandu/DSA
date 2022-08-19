#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head=NULL,*tail=NULL;
struct node *getNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
    if(head==NULL)
    {   
        head=newNode;  
        tail=newNode;  
    }  
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}
void printList(struct node *head)
{
    printf("\nThe Linear list is => ");
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
void convertCicular(struct node *head)
{
    struct node *temp=head;
    while (temp->next!=NULL)
        temp=temp->next;
    temp->next=head;
}
void traverse(struct node *head)
{
    struct node *temp;
    temp=head;
	printf("\nThe Circular list is => ");
	while (temp->next!=head)
    {
		printf("%d->",temp->data);
		temp = temp->next;
	}
    printf("%d->first node\n\n",temp->data);
}
int main()
{
    getNode(1);
    getNode(2);
    getNode(3);
    getNode(4);
    getNode(5);
    printList(head);
    convertCicular(head);
    traverse(head);
    return 0;
}
