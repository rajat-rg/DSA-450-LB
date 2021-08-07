#include<stdio.h>
#include<stdlib.h>
struct node{
    int a;
    struct node* left;
    struct node* right;

}*root = NULL;

void traverse(struct node* root)
{
    if (root == NULL)
    return;
    traverse(root->left);
    printf("%d-> ", root->a, root->right);
    traverse(root->right);
}
struct node* createNode()
{
    int a;
    printf("Enter data\n");
    scanf("%d", &a);

    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->a = a;
    ptr->left =NULL;
    ptr->right =NULL;
    return ptr;
}
struct node* createTree()
{
    int ch;
    printf("Enter choice\n");
    scanf("%d", &ch);
    if(ch<0)
    return NULL;
    struct node* ptr ;
    ptr = createNode();
    ptr -> left =createTree();
    ptr -> right =createTree();
    return ptr;
}
void flattenTree(struct node* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    return;

    if(root->left != NULL)
    {
        flattenTree(root->left);
        struct node* tmp = root->right;
        root->right = root->left;
        root->left =NULL;


        struct node* t = root->right;
        while(t != NULL)
        t = t->right;

        t->right = tmp;
    }

flattenTree(root->right);
}
int main(int argc, char const *argv[])
{
    root = createTree();
    traverse(root);
    flattenTree(root);

    traverse(root);

    /* code */
    return 0;
}
