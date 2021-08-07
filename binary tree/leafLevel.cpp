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

int checkLeaf(tree *root, int level, int *leaflevel)
{
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
    {
        if (leaflevel = 0)
        {
            *leaflevel = level;
        }

        return (*leaflevel = level);
    }

    return checkLeaf(root->left, level + 1, leaflevel) &&checkLeaf(root->right, level + 1, leaflevel);
}

int checkleaf(tree *root)
{
    int level, leaflevel;
    level = 0;
    leaflevel = 0;

    return checkLeaf(root, level, &leaflevel);
}

int main(int argc, char const *argv[])
{
    root = create_tree();
    cout<<checkleaf(root)<<endl;
    return 0;
}
