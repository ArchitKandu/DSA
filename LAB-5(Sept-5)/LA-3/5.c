#include<stdio.h>
#include<stdlib.h>
 
struct node 
{
    int coef;
    int pX;
    int pY;
    struct node *next;
}*head=NULL;
 
void result(struct node* head)
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
 
    else {
        temp = head;
        while (temp != NULL) {
            printf("(%d)x^(%d)y^(%d) + ",temp->coef,temp->pX,temp->pY);
            temp = temp->next;
        }
    }
}
 
void insert(struct node** head,int coef,int pX,int pY){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coef = coef;
    temp->pX = pX;
    temp->pY = pY;
    temp->next = *head;
    *head = temp;
}
 
void freeList(struct node* head)
{
    struct node *temp = head;
    head = head->next;
    while (head != NULL)
    {
        free(temp);
        temp = head;
        head = head->next;
    }
}
 
int main()
{
    int i=1,n;
    printf("\nEnter total: ");
    scanf("%d",&n);
    while(n--)
    {
        int coef,pX,pY;
        printf("\nEnter %d\n",i);
        printf("Enter the coefficient: ");
        scanf("%d",&coef);
        printf("Enter the power of x: ");
        scanf("%d",&pX);
        printf("Enter the power of y: ");
        scanf("%d",&pY);
        insert(&head,coef,pX,pY);
        i++;
    }
    printf("\n");
    printf("Polynomial: ");
    result(head);
    freeList(head);
    return 0;
}
