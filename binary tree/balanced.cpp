#include <iostream>
#include <stdlib.h>
#include <stack>
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
    cout << "left of " << a<<"-> ";
    r->left = create_tree();
    cout << "right of " << a<<"-> ";
    r->right = create_tree();
    return r;
}

int height(tree* root)
{
    if(root == NULL)
    return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight)+1;
    
}



int isBalanced(tree* root)
{
    if (root == NULL)
    return 1;

    int lheight = height(root->left);
    int rheight = height(root->right);

    if(abs(lheight - rheight)<= 1 && isBalanced(root->left) && isBalanced(root->right))
    return 1;

    return 0;

}

int main(int argc, char const *argv[])
{
    root = create_tree();
    int r = isBalanced(root);
    if(r == 1)
    cout<<"Tree is balanced";
    else
    cout<<"Tree is not balanced";
    return 0;
}

