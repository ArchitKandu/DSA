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
    if(root==NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
int countLeafNodes(struct bt *root)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int countNodes(struct bt *root)
{
    if(root==NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int countNonLeafNodes(struct bt *root)
{
    return countNodes(root)-countLeafNodes(root);
}
int sumOfNodes(struct bt *root)
{
    if(root==NULL) return 0;
    return root->data + sumOfNodes(root->right) + sumOfNodes(root->left);
}
int maxDepth(struct bt *root)
{
    if(root==NULL) return 0;
    else
    {
        int ld=maxDepth(root->left);
        int rd=maxDepth(root->right);
        if (ld>rd)
            return ld+1;
        else
            return rd+1;
    }
}
void printCurrentLevel(struct bt *root,int level)
{
    if(root==NULL) printf("Empty Tree!!");
    if (level==1)
        printf("%d ",root->data);
    else if (level>1)
    {
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}
void printMax(struct bt *root)
{
    int h=maxDepth(root);
    printCurrentLevel(root,h);
}
void printLevelOrder(struct bt *root)
{
    int i;
    printf("\nEnter Level: ");
    scanf("%d",&i);
    printCurrentLevel(root,i);
}
int isBST(struct bt *temp)
{
    if(temp == NULL) 
        return 1; 
    if(temp->left != NULL && temp->left->data >temp->data) 
        return 0; 
    if (temp->right != NULL && temp->right->data <temp->data) 
        return 0; 
    if (!isBST(temp->left) || !isBST(temp->right)) 
        return 0; 
  return 1; 
}
struct bt *lca(struct bt *root,int n1,int n2)
{
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
    return root;
}
int main()
{
    int ch,data,key,n1,n2,t;
    struct bt *temp1;
    while(1)
    {
        printf("\n0. Exit\n1. Insert\n2. In-Order\n3. Pre-Order\n4. Post-Order\n5. Search");
        printf("\n6. Print Largest\n7. Print Smallest\n8. Delete Using Key\n9. Delete The Tree");
        printf("\n10. Count Leaf Nodes\n11. Count Non-Leaf Nodes\n12. Count Nodes");
        printf("\n13. Sum of All Nodes\n14. Depth\n15. Nodes at Maximum Depths");
        printf("\n16. Elements of Kth Level\n17. Common Ancestors and Path");
        printf("\n18. Check tree is BST or not\n\n");
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
                printf("Tree Deleted Successfully!!\n");
                break;
            case 10:
                printf("There are %d number of Leaf Nodes\n",countLeafNodes(root));
                break;
            case 11:
                printf("There are %d number of Non-Leaf Nodes\n",countNonLeafNodes(root));
                break;
            case 12:
                printf("There are %d number of Nodes\n",countNodes(root));
                break;
            case 13:
                printf("Sum of Nodes: %d\n",sumOfNodes(root));
                break;
            case 14:
                printf("Max Depths Nodes: %d\n",maxDepth(root));
                break;
            case 15:
                printf("Nodes at Max Depths: ");
                printMax(root);
                break;
            case 16:
                printLevelOrder(root);
                break;
            case 17:
                printf("Enter two Numbers: ");
                scanf("%d%d",&n1,&n2);
                temp1=lca(root,n1,n2);
                printf("%d is common Ancestor\nPath is: ",temp1->data);
                preorder(temp1);
                printf("NULL\n\n");
                break;
            case 18:
                t=isBST(root);
                if(t==0) printf("Tree is not a Binary Search Tree\n\n");
                else printf("Tree is a Binary Search Tree\n\n");
                break;
            default:
                printf("Invalid Input!!");
                break;
        }
    }
    return 0;
}
