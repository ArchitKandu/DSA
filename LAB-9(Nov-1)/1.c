#include<stdio.h>
#include<stdlib.h>
struct bt
{
    int data;
    struct bt *left;
    struct bt *right;
} *root=NULL;
void insert(int data)
{
    struct bt *newNode=(struct bt*)malloc(sizeof(struct bt));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    if (root==NULL)
        root=newNode;
    else
    {
        struct bt *curr=NULL;
        struct bt *tmp=root;
        while (tmp!=NULL)
        {
            curr=tmp;
            if(tmp->data>data)
                tmp=tmp->left;
            else if (tmp->data<data)
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
int main()
{
    insert(4);
    insert(6);
    insert(5);
    insert(1);
    insert(3);
    insert(2);
    insert(7);
    printf("\nPre-order traversal: ");
    preorder(root);
    printf("NULL");
    printf("\nIn-order traversal: ");
    inorder(root);
    printf("NULL");
    printf("\nPost-order traversal: ");
    postorder(root);
    printf("NULL\n\n");
    return 0;
}
