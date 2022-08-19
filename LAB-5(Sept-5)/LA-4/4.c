#include<stdio.h>  
#include<stdlib.h>  
struct node  
{
    int data; 
    struct node *prev;  
    struct node *next; 
} *head;
void getNode(int data)
{
    struct node *ptr,*temp;  
    ptr=(struct node *) malloc(sizeof(struct node));    
    ptr->data=data;  
    if(head==NULL)  
    {  
        head=ptr;  
        ptr->next=head;   
        ptr->prev=head;   
    }
   else  
   {  
        temp=head;
        while(temp->next!=head) temp=temp->next;  
        temp->next=ptr;  
        ptr->prev=temp;  
        head->prev=ptr;  
        ptr->next=head;  
   }    
}
void printList(struct node *head)  
{  
    struct node *ptr;  
    ptr=head;  
    if(head==NULL)  
    {  
        printf("List is Empty!");  
    }     
    else  
    {
        while(ptr->next!=head)  
        {  
            printf("%d ",ptr->data);  
            ptr=ptr->next;  
        }  
        printf("%d ",ptr->data);  
    }               
}
int main()
{
    int n;
    printf("\nEnter total: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num;
        printf("Enter Number: ");
        scanf("%d",&num);
        getNode(num);
    }
    printf("\n\nLL is: ");
    printList(head);
    printf("\n\n");
    return 0;
}
