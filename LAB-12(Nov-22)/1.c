#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct HeaderNode
{
    int id;
    int size;
    struct HeaderNode *next;
};
int countNodes(struct Node *temp)
{
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}
void insertHeader(struct HeaderNode **head,int n,struct Node *temp)
{
    *head=(struct HeaderNode*)malloc(sizeof(struct HeaderNode));
    int size=countNodes(temp);
    (*head)->size=size;
    (*head)->id=n;
    (*head)->next=temp;
}
void insert(struct Node **head,int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL) head=newNode;
    else
    {
        struct Node *temp=(*head);
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newNode;
    }
}
void delAtPos(struct Node *head,int pos)
{
    struct Node *temp, *position;
    int i=1;
    temp=head;
    if (head==NULL) printf("\nList is empty\n");
    else
    {
        if(pos==1)
        {
            position=head;
            head=head->next;
            free(position);
            return;
        }
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        position=temp->next;
        temp->next=position->next;
        free(position);
    }
}
void delKey(struct Node *head,int key)
{
    struct Node *temp;
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
        delAtPos(head,pos);
    }
}
void diplay(struct Node *head,struct HeaderNode *temp)
{
    printf("\nLL ID: %d\nLL Size: %d\n",temp->id,temp->size);
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
void arrange(int *arr,struct HeaderNode *temp,int n)
{
    
}
int main()
{
    int n;
    int *arr;
    printf("\nEnter Size of Array: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    struct Node *head=(struct Node*)malloc(n*sizeof(struct Node));
    struct HeaderNode *hhead=(struct HeaderNode*)malloc(n*sizeof(struct HeaderNode));
    return 0;
}
