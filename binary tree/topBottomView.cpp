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

void levelorder(tree *root)
{
    tree* curr = root;
    queue<tree*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        curr = q.front();
        q.pop();

        q.push(curr->left);
        q.push(curr->right);

        if(q.front() == NULL and !q.empty())
        {
            cout<<curr->data;
            q.pop();
            curr = q.front();
            cout<<curr->data;
            q.push(NULL);
        }


    }




}




void topview(tree* root, int c)
{
    

}


int main(int argc, char const *argv[])
{
    root = create_tree();
    topview(root,1);
    return 0;
}
