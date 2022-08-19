#include <stdio.h>
#include <stdlib.h> 
typedef struct Node
{
    int data;
    struct Node *next;
} node;
typedef struct HeaderList
{
    int size;
    int id;
    node *next;
} hl;
void insert(hl *h, node **head, int data)
{
    node *temp=(*head);
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL)
        *head=newNode, h->next=(*head);
    else
    {
        while (temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
}
void deleteNode(hl *h, node **head, int data)
{
    node *temp= *head, *pos=NULL;
    if (temp==NULL)
    {
        printf("No Such Data Found!\n");
        return;
    }
    if(temp->data==data)
        h->next=temp->next;
    else
    {
        while (temp!=NULL)
        {
            if (temp->next->data==data)
            {
                pos=temp->next;
                temp->next=pos->next;
                free(pos);
                printf("Node deleted!!\n");
                return;
            }
            temp=temp->next;
        }
    }
}
void arrange(hl arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i].size<arr[j].size)
            {
                hl temp;
                temp.id=arr[i].id;
                temp.next=arr[i].next;
                temp.size=arr[i].size;
                arr[i].id=arr[j].id;
                arr[i].next=arr[j].next;
                arr[i].size=arr[j].size;
                arr[j].id=temp.id;
                arr[j].next=temp.next;
                arr[j].size=temp.size;
            }
        }
    }
}
void displayHeader(hl arr[], int n)
{
    for(int i=0;i<n;i++)
        if(arr[i].id!=-1)
            printf("Linked List Id = %d\nNumber of nodes = %d\n", arr[i].id, arr[i].size);
}
void displayNodeList(node *head)
{
    if(head==NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    while(head!=NULL)
    {
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    int n;
    printf("\nEnter n as size of array: ");
    scanf("%d",&n);
    hl *arr=(hl *)malloc(n*sizeof(hl));
    for(int i=0;i<n;i++)
    {
        arr[i].size=0;
        arr[i].id=-1;
        arr[i].next=NULL;
    }
    while (1)
    {
        int ch;
        printf("\n---------MENU---------\n"
               "0)Exit.\n"
               "1)Add new header.\n"
               "2)Add node to a specific header.\n"
               "3)Delete node from a specific header.\n"
               "4)Print all nodes from a specific header.\n"
               "5)Print all the headers.\n"
               "Enter a choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            int id,i;
            printf("Enter the Linked List Id: ");
            scanf("%d",&id);
            for(int i=0;i<n;i++)
            {
                if(arr[i].id==id)
                {
                    printf("Linked List already present!\n");
                    id=-1;
                    break;
                }
                else if(arr[i].id==-1)
                    break;
            }
            if (id!=-1)
                arr[i].id=id; arrange(arr,n);
        }
        break;
        case 2:
        {
            int id,data,i;
            printf("Enter Linked List Id: ");
            scanf("%d",&id);
            printf("Enter Data to Insert: ");
            scanf("%d",&data);
            for(i=0;i<n;i++)
            {
                if(arr[i].id==id)
                {
                    insert(&arr[i],&arr[i].next,data);
                    arr[i].size++;
                    arrange(arr,n);
                    break;
                }
                else if (i == n - 1)
                    i = -1;
            }
            if (i == -1)
                printf("Linked List Id doens't exist!\n");
        }
        break;
        case 3:
        {
            int id, data, i;
            printf("Enter Linked List Id: ");
            scanf("%d",&id);
            printf("Enter Data to Delete: ");
            scanf("%d",&data);
            for(i = 0; i < n; i++)
            {
                if(arr[i].id==id)
                {
                    deleteNode(&arr[i], &arr[i].next,data);
                    arr[i].size--;
                    arrange(arr,n);
                    break;
                }
                else if(i==n-1)
                    i= -1;
            }
            if (i==-1)
                printf("Linked List Id doens't exist!\n");
        }
        break;
        case 4:
        {
            int id,i;
            printf("Enter Linked List Id to print: ");
            scanf("%d",&id);
            for (i=0;i<n;i++)
            {
                if (arr[i].id==id)
                {
                    printf("Linked list for Linked List Id = %d is: \n",id);
                    displayNodeList(arr[i].next);
                    break;
                }
                else if (i==n-1)
                    i= -1;
            }
            if (i==-1)
                printf("Linked List Id doens't exist!\n");
        }
        break;
        case 5:
            displayHeader(arr,n);
            break;
        default:
            printf("Enter a correct choice!\n");
            break;
        }
    }
    return 0;
}
