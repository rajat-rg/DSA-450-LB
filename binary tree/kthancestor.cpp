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

tree* kThancestor(tree *root, int a, int k)
{
    cout<<"-";
    if(root ==NULL)return root;

    if(root->data==a or kThancestor(root->left, a,k) or kThancestor(root->right, a,k))
    {
        cout<<"!";
        if(k>0)
        k--;
        else if(k==0)
        {
            cout<<"k th ancestor is"<<root->data;
            return NULL;
        }
        
    return root;
    }
}

int main(int argc, char const *argv[])
{
    root = create_tree();
    kThancestor(root,4,2);
    return 0;
}
