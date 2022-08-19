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
int isEmpty()
{
    return !head;
}
void insertAtfront(struct node **head, int newdata)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=(*head);
    (*head)=newnode;
}
void insertAtEnd(struct node **head, int newdata)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *last=*head;
    newnode->data=newdata;
    newnode->next=NULL;
    if (*head==NULL) *head=newnode;
    while (last->next!=NULL) last=last->next;
    last->next=newnode;
}
void insertAtPos(int pos,int newdata)
{
    struct node *temp, *newnode;
	int i=1;
	newnode=(struct node*)malloc(sizeof(struct node));
	temp=head;
	newnode->data=newdata;
	newnode->next=0;
	while (i<pos-1)
    {
		temp = temp->next;
		i++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void deleteAtFirst()
{
    struct node* temp;
	temp=head;
	head=head->next;
	free(temp);
}
void deleteAtEnd()
{
	struct node *temp, *pnode;
	temp=head;
	while (temp->next!= 0)
    {
		pnode=temp;
		temp=temp->next;
	}
	free(temp);
	pnode->next=0;
}
void deleteAtPos(int pos)
{
	struct node *temp, *post;
	int i=1;
	post=(struct node*)malloc(sizeof(struct node));
	temp=head;
	if(pos==1)
    {
		deleteAtFirst();
	}
	else
    {
		while (i<pos-1)
        {
			temp = temp->next;
			i++;
		}
		post=temp->next;
		temp->next=post->next;
		free(post);
	}
}
int search(int s)
{
    struct node* temp;
    int pos=0;
	if (head!=NULL)
    {
		temp=head;
		while(temp!=NULL)
        {
            pos++;
            if(temp->data==s) break;
			temp=temp->next;
		}
	}
    return temp==NULL?-1:pos;
}
void delkey(struct node **head,int key)
{
    struct node *temp=(*head), *prev;
    if (temp!=NULL && temp->data==key) 
    {
        *head=temp->next;
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL) return;
    prev->next=temp->next;
    free(temp);
}
int countNodes()
{
    struct node* temp;
    int count=0;
	if(head!=NULL)
    {
		temp=head;
		while(temp!=NULL)
        {
			count++;
			temp = temp->next;
		}
	}
    return count;
}
int main()
{
    head=getNode(5);
    head->next=getNode(7);
    head->next->next=getNode(9);
    head->next->next->next=getNode(11);
    int size=4;
    printf("\n\nLinked list before insertion: ");
    printList(head);
    isEmpty()?printf("\n\nList is empty!"):printf("\n\nList is not empty!");
    insertAtfront(&head,1);
    printf("\n\nLinked list after insertion of 1 at front: ");
    printList(head);
    insertAtEnd(&head,12);
    printf("\n\nLinked list after insertion of 12 at end: ");
    printList(head);
    insertAtPos(2,2);
    printf("\n\nLinked list after insertion of 2 at position 2: ");
    printList(head);
    deleteAtPos(2);
    printf("\n\nLinked list after deletion of data at position 2: ");
    printList(head);
    deleteAtFirst();
    printf("\n\nLinked list after deletion of data at front: ");
    printList(head);
    deleteAtEnd();
    printf("\n\nLinked list after deletion of data at end: ");
    printList(head);
    delkey(&head,9);
    printf("\n\nLinked list after deletion of 9 using key: ");
    printList(head);
    printf("\n\nTotal number of current nodes are: %d",countNodes());
    printf("\n\nSearching 7:-\n");
    printf("7 is at %d position currently\n\n",search(7));
    return 0;
}
