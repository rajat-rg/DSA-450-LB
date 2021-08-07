#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
    tree(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
} *root = NULL;

struct tree *create_tree()
{
    int a;
    cout << "Enter data (0 for NULL):\n";
    cin >> a;
    if (a <= 0)
        return NULL;
    struct tree *r = new tree(a);
    cout << "left of " << a << "-> ";
    r->left = create_tree();
    cout << "right of " << a << "-> ";
    r->right = create_tree();
    return r;
}

int height(struct tree *root)
{
    if (root == NULL)
        return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    return max(h1, h2) + 1;
}

int diameter(struct tree *root)
{
    if (root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight + rheight + 1, max(ldiameter, rheight));
}

tree* mirror(struct tree *root)
{

    if (root == NULL)
    return root;

    struct tree* tmp = root->left;
    root->left = root->right ;
    root->left = tmp ;

    if(root->left)
    mirror(root->left);
    if(root->right)
    mirror(root->right);

    return root;
}

void inorder(struct tree *root)
{
    // cout << "In order traversal of binary tree: \n";
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " -> ";
        inorder(root->right);
    }
    
}

int main(int argc, char const *argv[])
{
    root = create_tree();
    cout << "Height of binary tree is :" << height(root);
    cout << "\nDiameter of binary tree is :" << diameter(root);
    cout<<endl;
    inorder(root);
    mirror(root);
    cout<<endl;
    inorder(root);

    return 0;
}

