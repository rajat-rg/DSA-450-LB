#include <iostream>

using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
    tree(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
} *root = NULL;

tree *create_BST(tree *root, int data)
{
    tree *ptr = new tree(data);
    if (root == NULL)
        return ptr;
    if (data <= root->data)
        root->left = create_BST(root->left, data);
    else
        root->right = create_BST(root->right, data);
    return root;
}
void inorder(tree *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}
void preorder(tree *root)
{
    if (root == NULL)
        return;

    cout << root->data << " -> ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(tree *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " -> ";
}

tree *LCA(tree *root, int a, int b)
{
    if (root == NULL)
        return root;

    if (root->data == a || root->data == b)
        return root;
    tree *left = LCA(root->left, a, b);
    tree *right = LCA(root->right, a, b);

    if (left == NULL and right == NULL)
        return NULL;

    if (left and right)
        return root;

    if (left != NULL)
        return left;
    if (right != NULL)
        return right;

    return root;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Number of nodes:\n";
    cin >> n;
    while (n)
    {
        cout << "Enter number";
        int no;
        cin >> no;
        root = create_BST(root, no);
        n--;
    }
    tree *ptr = LCA(root, 6, 3);
    if (ptr)
        cout << ptr->data;
    return 0;
}
