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
    cout << "left of " << a << "-> ";
    r->left = create_tree();
    cout << "right of " << a << "-> ";
    r->right = create_tree();
    return r;
}

void flatBinaryTree(tree *root)
{

    if (root == NULL || root->left == NULL || root->right == NULL)
        return;

    if (root->left != NULL)
    {

        flatBinaryTree(root->left);

        tree *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        tree *ptr = root->right;

        while (ptr->right)
            ptr = ptr->right;

        ptr->right = tmp;
    }

    flatBinaryTree(root->right);
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
    flatBinaryTree(root);
    cout << endl;
    inorder(root);
    return 0;
}
