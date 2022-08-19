#include <stdio.h>
#include<stdlib.h>
struct node
{  
    int data;  
    struct node *prev;  
    struct node *next;  
};      
struct node *head, *tail = NULL; 
void getNode(int data)
{  
    //Create a new node  
    struct node *newNode=(struct node*)malloc(sizeof(struct node));  
    newNode->data = data;
    if(head == NULL)
    {  
        head = tail = newNode;  
        head->prev=NULL;  
        tail->next=NULL;  
    }  
    else
    {  
        tail->next=newNode;  
        newNode->prev=tail;
        tail=newNode;  
        tail->next=NULL;  
    }  
} 
void removeDuplicateNode()
{   
    struct node *current, *index, *temp;  
    if(head == NULL)
    {  
        return;  
    }  
    else
    {  
        current=head;
        while(current!= NULL)
        {
            index=current->next;
            while(index!=NULL)
            {  
                if(current->data==index->data)
                {  
                    temp=index;  
                    index->prev->next=index->next;  
                    if(index->next!=NULL)  
                        index->next->prev=index->prev;   
                    temp=NULL;
                }
                index=index->next;
            }
            current=current->next; 
        }  
    }  
}   
void display()
{
    struct node *temp=head;  
    if(head==NULL)
    {  
        printf("List is empty\n");  
        return;  
    }  
    while(temp!=NULL)
    {  
        printf("%d ", temp->data);  
        temp=temp->next;  
    }  
    printf("\n");  
}  
int main()  
{  
    getNode(1);  
    getNode(2);  
    getNode(3);  
    getNode(2);  
    getNode(2);  
    getNode(4);  
    getNode(5);  
    getNode(3);
    printf("\n"); 
    printf("Originals list: ");  
    display();  
    removeDuplicateNode();  
    printf("List after removing duplicates: ");  
    display();
    printf("\n");
    return 0;  
}
