#include<iostream>

using namespace std;

struct tree{
    int data; 
    tree* left;
    tree* right;
    tree(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
}*root = NULL;

tree* create_BST(tree* root, int data)
{
    tree* ptr = new tree(data);
    if(root == NULL)
        return ptr;
    if(data <= root->data)
        root->left = create_BST(root->left,data);    
    else 
        root->right = create_BST(root->right,data);    
    return root;

}
void inorder(tree* root)
{
    if(root==NULL)return;

    inorder(root->left);
    cout<<root->data<<" -> ";
    inorder(root->right);
}
void preorder(tree* root)
{
    if(root==NULL)return;

    cout<<root->data<<" -> ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(tree* root)
{
    if(root==NULL)return;

    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" -> ";
}
bool isBST(tree* root, tree* min, tree* max)
{
    if(root == NULL)return true;

    if(min!= NULL and root->data <= min->data)return false;
    if(max!= NULL and root->data >= max->data)return false;

    bool left = isBST(root->left, min, root);
    bool right = isBST(root->right,root,max);

    return left && right;
}
int main(int argc, char const *argv[])
{
    int n;
    cout <<"Number of nodes:\n";
    cin>>n;
    while(n)
    {   cout<<"Enter number";
        int no;
        cin>>no;
        root = create_BST(root,no);
        n--;

    }
    inorder(root);
bool v =     isBST(root,NULL,NULL);
if(v)
cout<<"Valid BST hai\n";
    else
    cout<<"na hai valid";
    return 0;
}
