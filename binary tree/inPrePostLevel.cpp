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
void preorder(struct tree *root)
{
    // cout << "Pre order traversal of binary tree: \n";
    if (root != NULL)
    {
        cout << root->data << " -> ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct tree *root)
{
    // cout << "Post order traversal of binary tree: \n";
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " -> ";
    }
}

void levelTraversal(tree *root)
{
    // cout << "Level order traversal of binary tree: \n";
    queue<tree *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        tree *child = q.front();
        q.pop();

        if (child != NULL)
        {
            cout << child->data << " -> ";
            if (child->left != NULL)
                q.push(child->left);
            if (child->right != NULL)
                q.push(child->right);
        }

        else if (!q.empty())
            q.push(NULL);
    }
}

int main(int argc, char const *argv[])
{
    root = create_tree();
    inorder(root);
    levelTraversal(root);
    return 0;
}
