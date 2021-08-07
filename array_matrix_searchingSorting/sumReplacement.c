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
void sumReplacement(struct node* root)
{
    if(root == NULL)
    return ;

     sumReplacement(root->left);
     sumReplacement(root->right);

    if(root->left != NULL)
    root ->a += root->left->a;
    
    
    if(root->right != NULL)
    root ->a += root->right->a;





}
int main(int argc, char const *argv[])
{
    root = createTree();
    traverse(root);
    sumReplacement(root);
    printf("\n");
    traverse(root);

    /* code */
    return 0;
}
