#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head=NULL;
struct node *getNode(int data)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
void reverse()
{
	struct node *a, *b, *temp;
	a=b=NULL;
	while(head!=NULL)
    {
		b=head->next;
		head->next=a;
		a=head;
		head=b;
	}
	head=a;
	temp=head;
}
int main()
{
    head=getNode(2);
    head->next=getNode(4);
    head->next->next=getNode(6);
    head->next->next->next=getNode(8);
    printf("\nOriginal linked list: ");
    printList(head);
    reverse();
    printf("\n\nReversed linked list: ");
    printList(head);
    printf("\n\n");
    return 0;
}
