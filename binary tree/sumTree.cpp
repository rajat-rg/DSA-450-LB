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
int sumTree(tree* root) {
    
    if(root==NULL)return 0;

    int old = root->data;

    root->data = sumTree(root->left)+ sumTree(root->right);
    root->data+= old;
    return root->data;
}
bool isSumTree(tree* root) {
    if(root == NULL)return true;


    if(root->data == root->left->data+ root->right->data)
    {
        isSumTree(root->left);
        isSumTree(root->right);
        
    }
    else
    return false;

}



int main(int argc, char const *argv[])
{
    root = create_tree();
    sumTree(root);
    inorder(root); 
    cout<<isSumTree(root);   
    return 0;
}

