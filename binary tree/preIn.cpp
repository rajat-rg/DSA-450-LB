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

int search(int in[], int start, int end, int curr)
{

    for (int i = start; i < end; i++)
    {
        if (in[i] == curr)
            return i;
    }
    return -1;
}

tree *newTree(int pre[], int in[], int start, int end)
{
    if (start > end)
        return NULL;
    static int idx = 0;
    int curr = pre[idx];
    idx++;

    int pos = search(in, start, end, curr);
    tree *node = new tree(curr);
    if (start == end)
        return node;
    node->left = newTree(pre, in, start, pos - 1);
    node->right = newTree(pre, in, pos + 1, end);
    return node;
}

int main(int argc, char const *argv[])
{
    // root = create_tree();
    int pre[] = {1, 2, 4, 3, 5};
    int in[] = {4, 2, 1, 5, 3};
    root = newTree(pre, in, 0, 4);
    cout << endl;
    inorder(root);
    return 0;
}
