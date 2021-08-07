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
void zigzag(tree* root) {
    if (root == NULL) return;
    stack<tree* > curr;
    stack<tree* > nexts;
    bool left2right = true;

    curr.push(root);
    while(!curr.empty())
    {
        tree* tmp = curr.top();
        curr.pop();

        if(tmp!= NULL)
        {
            cout<<tmp->data<<" ";
            if(left2right)
            {
                if(tmp->left)
                    nexts.push(tmp->left);
                if(tmp->right)
                    nexts.push(tmp->right);
            }

            else
            {
                if(tmp->right)
                    nexts.push(tmp->right);
                if(tmp->left)
                    nexts.push(tmp->left);

            }


        }
        if (curr.empty())
        {
            left2right = !left2right;
            swap(curr,nexts);

        }
        
    }

}


int main(int argc, char const *argv[])
{
    root = create_tree();
    zigzag(root);       
    return 0;
}

