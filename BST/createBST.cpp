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

int search(tree* root,int data)
{
    tree* ptr = root;
    if(ptr->data==data)return 1;
    if(ptr== NULL)return 0;
    search(ptr->left, data);
    search(ptr->right, data);
    return 0;

}
tree* inorderSucc(tree* root)
{
    tree* curr = root;
    while(curr and curr->left!= NULL)
    curr = curr->left;
    return curr;
}
tree* deletekrdo(tree* root, int data)
{
    if(data < root->data)
    root->left = deletekrdo(root->left,data);
    else if(data > root->data)
    root->right = deletekrdo(root->right,data);
    else
    {
        if(root->left == NULL)
        {
            tree* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            tree* temp = root->left;
            free(root);
            return temp;
        }
        tree* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deletekrdo(root->right,temp->data);
    }
    return root;

}

void minMax(tree* root)
{
    tree* min = root;
    tree* max = root;
    while(min->left)
    {
        min = min->left;
    }
    while(max->right)
    {
        max = max->right;
    }
    cout<<"Min value of this binary tree is "<<min->data<<"\n";
    cout<<"Max value of this binary tree is "<<min->data<<"\n";
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
    cout<<endl;
    deletekrdo(root,4);
    inorder(root);
    return 0;
}
