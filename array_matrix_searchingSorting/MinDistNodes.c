#include <stdio.h>
#include <stdlib.h>
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
struct node *LCA(struct node *root, int a, int b)
{
    if (root == NULL)
        return root;

    if (root->a == a || root->a == b)
        return root;

    struct node *left = LCA(root->left, a, b);
    struct node *right = LCA(root->right, a, b);

    if (left != NULL && right != NULL)
        return root;

    if (left == NULL && right == NULL)
        return NULL;

    if (left != NULL)
        return LCA(root->left, a, b);

    return LCA(root->right, a, b);
}
int findDist(struct node *root, int n, int dist)
{
    if (root == NULL)
        return -1;
    if (root->a == n)
        return dist;

    int left = findDist(root->left, n, dist + 1);
    if (left != -1)
        return left;
    return findDist(root->right, n, dist + 1);
}
int MinDist(struct node *root, int a, int b)
{
    struct node *lca = LCA(root, a, b);

    int d1 = findDist(lca, a, 0);
    int d2 = findDist(lca, b, 0);
    return d1 + d2;
}
int main(int argc, char const *argv[])
{
    struct node* root=NULL;
    root = createTree();
    // printf("%d ",root->data);
    inorder(root);
    int d = MinDist(root, 2, 4);
    // printf("%d", d);
    return 0;
}
