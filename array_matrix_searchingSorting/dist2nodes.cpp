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

tree *LCA(tree *root, int a, int b)
{
    if (root == NULL)
        return root;

    if (root->data == a or root->data == b)
        return root;

    tree *l = LCA(root->left, a, b);
    tree *r = LCA(root->right, a, b);

    if (l != NULL and r != NULL)
        return root;

    return (l != NULL) ? l : r;
}

int calcDist(tree *root, int a, int level)
{
    if (root == NULL)
        return 0;

    if (root->data == a)
        return level;

    return max(
        calcDist(root->left, a, level + 1),
        calcDist(root->right, a, level + 1));
}
int dist(tree *root, int a, int b)
{
    tree *lca = LCA(root, a, b);
    int d1 = calcDist(lca, a, 0);
    int d2 = calcDist(lca, b, 0);

    return d1 + d2;
}

int main(int argc, char const *argv[])
{
    root = create_tree();
    tree *l = LCA(root, 5, 6);
    int d = dist(root, 5,6);
        cout << "--" << d;
    return 0;
}
