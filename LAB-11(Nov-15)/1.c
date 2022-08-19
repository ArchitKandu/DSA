#include<stdio.h>
#include<stdlib.h>
struct node
{
    int amt;
    int qty;
    float uprice;
    struct node *prev;
    struct node *next;
} *head=NULL,*tail=NULL;
void insert(int amt,int qty)
{
    struct node *newnode;
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->amt=amt;
        head->qty=qty;
        head->uprice=amt/qty;
        head->prev=NULL;
        head->next=NULL;
        tail=head;
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->amt=amt;
        newnode->qty=qty;
        newnode->uprice=(float)amt/qty;
        newnode->prev=tail;
        newnode->next=NULL; 
        tail->next=newnode;
        tail=newnode;
    }
}
void display()
{
    struct node *temp;
    if(head==NULL) printf("List is Empty!!");
    else
    {
        temp=head;
        printf("\n");
        while(temp!=NULL)
        {
            printf("Amount = %d, Quantity = %d, Unit Price = %.2f\n",temp->amt,temp->qty,temp->uprice);
            temp=temp->next;
        }
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
            if(temp->amt==key||temp->qty==key) break;
			pos++;
			temp=temp->next;
		}
        delAtPos(pos);
    }
}
void sortList()
{  
    struct node *current=NULL, *index=NULL;
    float temp1,temp2,temp3;
    if(head==NULL) printf("\nList is Empty!!\n");
    else 
    {  
        for(current=head;current->next!=NULL;current=current->next)
        {
            for(index=current->next;index!=NULL;index=index->next)
            {
                if(current->uprice > index->uprice)
                {  
                    temp1=current->uprice;
                    temp2=current->amt;
                    temp3=current->qty;
                    current->uprice=index->uprice;
                    current->amt=index->amt;
                    current->qty=index->qty;
                    index->uprice=temp1;
                    index->amt=temp2;
                    index->qty=temp3;
                }
            }
        }
    }
    display();
} 
int main()
{
    insert(15000,110);
    insert(8000,50);
    insert(7000,60);
    insert(9000,70);
    insert(10000,90);
    insert(5000,40);
    printf("\n-----Linked List-----\n");
    display();
    printf("\n-----After deletion-----\n");
    delKey(70);
    display();
    printf("\n-----After Sorting-----\n");
    sortList();
    printf("\n");
    return 0;
}
