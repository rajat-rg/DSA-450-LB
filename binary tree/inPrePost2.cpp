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
    tree* curr = root;
    stack<tree*> s;

    while(curr!= NULL or !s.empty())
    {
        while(curr!= NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" -> ";

        curr = curr->right;
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

int main(int argc, char const *argv[])
{
    root = create_tree();
    inorder(root);
    // preorder(root);
    // postorder(root);
    
    return 0;
}
