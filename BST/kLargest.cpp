#include <iostream>
#include <vector>

using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
    tree(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
} *root = NULL;

tree *create_BST(tree *root, int data)
{
    tree *ptr = new tree(data);
    if (root == NULL)
        return ptr;
    if (data <= root->data)
        root->left = create_BST(root->left, data);
    else
        root->right = create_BST(root->right, data);
    return root;
}
void inorder(tree *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left,v);
    cout << root->data << " -> ";
    v.push_back(root->data);
    // cout<<v.back();
    inorder(root->right,v);
}
void preorder(tree *root)
{
    if (root == NULL)
        return;

    cout << root->data << " -> ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(tree *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " -> ";
}

void minMax(tree *root)
{
    tree *min = root;
    tree *max = root;
    while (min->left)
    {
        min = min->left;
    }
    while (max->right)
    {
        max = max->right;
    }
    cout << "Min value of this binary tree is " << min->data << "\n";
    cout << "Max value of this binary tree is " << min->data << "\n";
}
int main(int argc, char const *argv[])
{
    vector<int> v;
    vector<int>::iterator it;
    int n;
    cout << "Number of nodes:\n";
    cin >> n;
    while (n)
    {
        cout << "Enter number";
        int no;
        cin >> no;
        root = create_BST(root, no);
        n--;
    }
    v.empty();
    inorder(root,v);
    
    cout << "Enter K\n";
    int k, i, val;
    cin >> k;

    for(i=v.size()-1;i>0;i--)
    {
        if(i== v.size()-k)
        cout<<"Max kth number is "<<v[i]<<"\n";
        if(i== k-1)
        cout<<"Min kth number is "<<v[i];
    }
    
    return 0;
}
