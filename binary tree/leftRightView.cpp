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

void leftView(struct tree *root)
{
    cout << "Left view of binary tree:\n";
    queue<tree *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        struct tree *ptr;
        ptr = q.front();
        q.pop();
        if (ptr)
        {
            cout << ptr->data << " -> ";
            if (ptr->left)
                q.push(ptr->left);
            else
                q.push(ptr->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
void rightView(struct tree *root)
{
    cout << "right view of binary tree:\n";
    queue<tree *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        struct tree *ptr;
        ptr = q.front();
        q.pop();
        if (ptr)
        {
            cout << ptr->data << " -> ";
            if (ptr->right)
                q.push(ptr->right);
            else
                q.push(ptr->left);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int main(int argc, char const *argv[])
{
    root = create_tree();
    leftView(root);
    rightView(root);
    return 0;
}
