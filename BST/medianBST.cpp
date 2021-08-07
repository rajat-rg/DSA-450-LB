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
} *root = NULL, *previous = NULL,*curr=NULL;

int c = 0;
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
int inorder(tree *root)
{
    if (root == NULL)
        return 0;

    inorder(root->left);
    cout << root->data << " -> ";
    c += 1;
    inorder(root->right);
    return c;
}

void median(tree* root, tree* previous, tree* curr, int &c, int &k, int &f)
{
    if (root == NULL)
        return;
    median(root->left, previous, curr, c, k, f);
    if (previous == NULL)
    {
        
        previous = root;
        
    }
    else if (c == (k / 2)+1)
    {
        
        curr = root;
        f = 1;
        c++;
        return;
    }
    else if (f == 0)
    {
        previous = root;
        c++;
    }
    
    median(root->right, previous, curr, c, k, f);
}
int main(int argc, char const *argv[])
{
    vector<int> v;

    vector<int> v2;

    int n1;
    cout << "Number of nodes for BST:\n";
    cin >> n1;
    while (n1)
    {
        cout << "Enter number";
        int no;
        cin >> no;
        root = create_BST(root, no);
        n1--;
    }
    // v.empty();

    int s = inorder(root);
    
    int c = 0, f = 0;
    median(root, previous, curr, c, s, f);
    cout<<"...."<<previous->data<<endl;
    if (s % 2 != 0)
        cout << curr->data;
    else
    {

        int mid = (previous->data + curr->data) / 2;
        cout << mid;
    }
    return 0;
}
