#include<stdio.h>
#include<stdlib.h>
struct bt
{
    int data;
    struct bt *left;
    struct bt *right;
} *root=NULL;
void insert(struct bt **root,int data)
{
    struct bt *newNode=(struct bt*)malloc(sizeof(struct bt));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    if (*root==NULL)
        *root=newNode;
    else
    {
        struct bt *curr=NULL;
        struct bt *tmp=*root;
        while (tmp!=NULL)
        {
            curr=tmp;
            if(tmp->data>data)
                tmp=tmp->left;
            else if(tmp->data<data)
                tmp=tmp->right;
        }
        if (curr->data>data)
            curr->left=newNode;
        else
            curr->right=newNode;
    }
}
void preorder(struct bt *root)
{
    struct bt *temp=root;
    if (temp!=NULL)
    {
        printf("%d->",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct bt *root)
{
    struct bt *temp=root;
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d->",temp->data);
        inorder(temp->right);
    }
}
void postorder(struct bt *root)
{
    struct bt *temp=root;
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d->",temp->data);
    }
}
struct bt *search(struct bt *root,int key)
{
    struct bt *temp=root;
    if(temp==NULL) return NULL;
    if(key==temp->data) return temp;
    else if(key<temp->data) return search(temp->left,key);
    else return search(temp->right,key);
}
void min(struct bt **root)
{
    struct bt *temp=*root;
    if(temp==NULL)
    {
        printf("\nTree is Empty!!");
        return;
    }
    else
    {
        while(temp->left!=NULL)
            temp=temp->left;
        printf("Smallest Element: %d\n",temp->data);
    }
}
void max(struct bt **root)
{
    struct bt *temp=*root;
    if(temp==NULL)
    {
        printf("\nTree is Empty!!");
        return;
    }
    else
    {
        while(temp->right!=NULL)
            temp=temp->right;
        printf("Largest Element: %d\n",temp->data);
    }
}
void deleteNode(struct bt *root)
{
    struct bt *temp=root;
    if(temp->left==NULL && temp->right==NULL)
    {
        free(temp);
        return;
    }
    if(temp->left!=NULL)
    {
        struct bt *t=temp->left;
        while(t->right!=NULL) t=t->right;
        temp->data=t->data;
        free(t);
    }
    else
    {
        struct bt *t=temp->right; 
        while(t->left!=NULL) t=t->left;
        temp->data=t->data; 
        free(t);
    }
}
void deleteTree(struct bt *root)
{
    struct bt *temp=root;
    if(root==NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(temp);
}
int main()
{
    int ch,data,key;
    struct bt *temp1;
    while(1)
    {
        printf("\n0. Exit\n1. Insert\n2. In-Order\n3. Pre-Order\n4. Post-Order\n5. Search");
        printf("\n6. Print Largest\n7. Print Smallest\n8. Delete Using Key\n9. Delete The Tree\n\n");
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                exit(0);
            case 1:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                insert(&root,data);
                break;
            case 2:
                printf("In-Order: ");
                inorder(root);
                printf("NULL\n\n");
                break;
            case 3:
                printf("Pre-Order: ");
                preorder(root);
                printf("NULL\n\n");
                break;
            case 4:
                printf("Post-Order: ");
                postorder(root);
                printf("NULL\n\n");
                break;
            case 5:
                printf("Enter Element to search: ");
                scanf("%d",&key);
                temp1=search(root,key);
                if(temp1!=NULL) printf("%d is present\n\n",key);
                else printf("%d is not present\n\n",key);
                break;
            case 6:
                max(&root);
                break;
            case 7:
                min(&root);
                break;
            case 8:
                printf("Enter Element to Delete: ");
                scanf("%d",&key);
                temp1=search(root,key);
                deleteNode(temp1);
                printf("%d Deleted Successfully\n",key);
                break;
            case 9:
                deleteTree(root);
                break;
            default:
                printf("Invalid Input!!");
                break;
        }
    }
    return 0;
}
