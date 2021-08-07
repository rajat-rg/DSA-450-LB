#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int>::iterator it;

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

void inorder(tree *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}
void preorder(tree *root)
{
    if (root == NULL)
        return;

    cout << root->data << " -> ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(tree *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " -> ";
}
void binary(tree *root)//inorder traversal se vector me sauda bhr do
{
    if (root == NULL)
        return;
    binary(root->left);
    v.push_back(root->data);
    binary(root->right);
}

void toBST(tree *root, vector<int> v, int *i)
{
    if (root == NULL)
        return;

    toBST(root->left, v, &*i);
    v[*i] = root->data;
    *i++;
    toBST(root->right, v, &*i);
}

tree *binary2BST(tree *root)
{
    binary(root);
    sort(v.begin(), v.end());
    int i = 0;

    toBST(root, v, &i);

    return root;
}
tree* balancedBST(int start,int end){
    if(start>end)return NULL;

    int mid = (end+start)/2;
    tree* ptr = new tree(v[mid]);
    ptr->left = balancedBST(start,mid-1);
    ptr->right = balancedBST(mid+1,end);
    return ptr;
    
}
int main(int argc, char const *argv[])
{
    root = create_tree();
    inorder(root);
    
    binary2BST(root);
    
    
    root = balancedBST(0,v.size());
    cout<<endl;
    inorder(root);
    

    return 0;
}
