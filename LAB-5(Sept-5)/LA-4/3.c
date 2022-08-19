#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
} *head=NULL,*tail=NULL;
void getNode(int data)
{
    struct node *newnode;
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        tail=head;
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->prev=tail;
        newnode->next=NULL; 
        tail->next=newnode;
        tail=newnode;
    }
}
void printList(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void reverse()
{
    tail=head;
     while (tail->next != NULL) 
    {
        tail = tail->next;
    }
    while (tail!=head) 
    {
        printf("%d ",tail->data);
        tail = tail->prev;
    }
    printf("%d",tail->data);
}
int isEmpty()
{
    int p = head==NULL?-1:1;
    return p;
}
void insAtfrnt(int data)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=head;
    head=temp;
}
void insAtend(int data)
{
    struct node *temp,*trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=data;
    temp->next=NULL;
    trav=head;
    if (head==NULL) head=temp;
    else 
    {
        while (trav->next!=NULL) trav=trav->next;
        temp->prev=trav;
        trav->next=temp;
    }
}
void insAtPos(int data,int pos)
{
    struct node *temp, *newnode;
    int i=1;
    newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=data;
    temp=head;
    if (head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        newnode->next=NULL;
    }
    else if (pos==1)
    {
        newnode->next=head;
        newnode->next->prev=newnode;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        while (i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        temp->next->prev=newnode;
    }
}
void delAtfrnt()
{
    struct node* temp;
    if (head==NULL) printf("\nList is empty\n");
    else
    {
        temp=head;
        head=head->next;
        if(head!=NULL) head->prev = NULL;
        free(temp);
    }
}
void delAtEnd()
{
     struct node* temp;
    if (head==NULL) printf("\nList is empty\n");
    temp=head;
    while(temp->next!=NULL) temp=temp->next;
    if (head->next==NULL) head=NULL;
    else 
    {
        temp->prev->next=NULL;
        free(temp);
    }
}
void delAtPos(int pos)
{
    struct node *temp, *position;
    int i=1;
    temp=head;
    if (head==NULL) printf("\nList is empty\n");
    else
    {
        if(pos==1)
        {
            position=head;
            head=head->next;
            if (head!=NULL) head->prev = NULL;
            free(position);
            return;
        }
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        position=temp->next;
        if (position->next!=NULL) position->next->prev = temp;
        temp->next=position->next;
        free(position);
    }
}
void delKey(int key)
{
    struct node *temp;
    int i=1,pos=1;
    if (head==NULL) printf("\nList is empty\n");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==key) break;
			pos++;
			temp=temp->next;
		}
        delAtPos(pos);
    }
}
int countNodes(struct node *head)
{
    struct node* temp;
    int count=0;
	if(head!=NULL)
    {
		temp=head;
		while(temp!=NULL)
        {
			count++;
			temp=temp->next;
		}
	}
    return count;
}
int search(int s)
{
    struct node *temp;
    int i=1,pos=1;
    if (head==NULL) printf("\nList is empty\n");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==s) break;
			pos++;
			temp=temp->next;
		}
        return pos;
    }
}
int main()
{
    int n,key,s;
    printf("\nEnter total Elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num;
        printf("Enter Number: ");
        scanf("%d",&num);
        getNode(num);
    }
    int c;
    printf("\n\n");
    printf("1.  Print List: ");
    printList(head);
    printf("\n");
    printf("2.  Reverse List: ");
    reverse();
    printf("\n");
    int p=isEmpty();
    if(p!=-1) printf("3.  LL is not Empty!\n");
    else printf("3.  LL is Empty!\n");
    printf("4.  Insert 10 at Start: ");
    insAtfrnt(10);
    printList(head);
    printf("\n");
    printf("5.  Insert 100 at End: ");
    insAtend(100);
    printList(head);
    printf("\n");
    printf("6.  Insert 50 at Position 3: ");
    insAtPos(50,3);
    printList(head);
    printf("\n");
    printf("7.  Delete at Start: ");
    delAtfrnt();
    printList(head);
    printf("\n");
    printf("8.  Delete at End: ");
    delAtEnd();
    printList(head);
    printf("\n");
    printf("9.  Delete at Position 2: ");
    delAtPos(2);
    printList(head);
    printf("\n");
    printf("10. Enter key: ");
    scanf("%d",&key);
    printf("    Deleted using Key %d: ",key);
    delKey(key);
    printList(head);
    printf("\n");
    printf("11. Total Nodes: %d\n",countNodes(head));
    printf("12. Search Element: ");
    scanf("%d",&s);
    printf("    %d is at %d position",s,search(s));
    printf("\n\n");
    return 0;
}
