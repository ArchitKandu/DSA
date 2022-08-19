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
    tail->next=head;
}
void traverse(struct node *head)
{
    struct node *temp;
    temp=head;
	printf("The Circular list is => ");
	while (temp->next!=head)
    {
		printf("%d->",temp->data);
		temp = temp->next;
	}
    printf("%d->first node\n\n",temp->data);
}
int isEmpty()
{
    return head==NULL?-1:1;
}
void insertAtPos(int data, int pos)
{
    struct node *temp;
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    if(pos==1)
    {
        newNode->next=head;
        head=newNode;
        tail->next=newNode;
    }
    else
    {
        temp=head;
        pos=pos-2;
        while(pos--)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
void delAtPos(int pos)
{
    struct node *current,*temp;
    if(pos==1)
    {
        temp=head;
        head=head->next;
        tail->next=head;
        free(temp);
    }
    else
    {
        current=head;
        pos=pos-2;
        while(pos--)
        {
            current=current->next;
        }
        temp=current->next;
        current->next=temp->next;
        free(temp);
    }
}
void delByKey(int key)
{
    struct node *temp=head;
    int pos=1;
    while(temp->data!=key)
    {
        temp=temp->next;
        pos++;
    }
    if(pos==1) printf("No such element!!");
    else delAtPos(pos);
}
int countNodes()
{
    struct node *temp=head;
    int count=0;
    if(temp!=NULL)
    {
        count=1;
        while(temp->next!=head)
        {
            count++;
            temp=temp->next;
        }
    }
    return count;
}
int search(int s)
{
    struct node *temp=head;
    int search=0;
    if(temp!=NULL)
    {
        search=1;
        while(temp->next!=head && temp->data!=s)
        {
            search++;
            temp=temp->next;
        }
    }
    return search;
}
int main()
{
    getNode(10);
    getNode(20);
    getNode(30);
    getNode(40);
    getNode(50);
    int e=isEmpty();
    if(e==-1) printf("\nList is Empty!!!\n");
    else printf("\nList is not Empty!!!\n");
    printf("\nOriginal List:\n");
    traverse(head);
    printf("Inserting 25 at position 3:\n");
    insertAtPos(25,3);
    traverse(head);
    printf("Deleting at position 3:\n");
    delAtPos(3);
    traverse(head);
    printf("Deleting 30:\n");
    delByKey(30);
    traverse(head);
    printf("Total Nodes: %d\n\n",countNodes());
    printf("Searching 20...\n");
    printf("20 is at Position %d\n\n",search(20));
    return 0;
}
