#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;

    map<string, int> m;
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

string solve(tree *root)
{
    if (!root)
        return "$";
    string s = "";
    if (!root->left && !root->right)
    {
        s += to_string(root->data);
        return s;
    }

    s += to_string(root->data);
    s += solve(root->left);
    s += solve(root->right);
    m[s]++;
    return s;
}
bool subtree(tree *root)
{
    m.clear();
    solve(root);
    for(auto x:m)
    {
        if(x.second >= 2)
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    root = create_tree();
    if(subtree(root))
    cout<<"Exists";
    return 0;
}
