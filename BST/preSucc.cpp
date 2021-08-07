#include <iostream>

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
} *root = NULL, *pre=NULL, *suc=NULL;

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
void inorder(tree *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}
tree *inpre(tree *root)
{
    tree *p = root->left;
    while (p->right)
        p = p->right;
    return p;
}
tree *insucc(tree *root)
{
    tree *p = root->right;
    while (p->left)
        p = p->left;
    return p;
}

void findpresucc(tree *root, tree *pre, tree *suc, int key)
{
    cout<<"! ";
    if (!root)
        return;
    if (root->data == key)
    {
        cout<<"@ "
;        if (root->left)
            pre = inpre(root);
        if (root->right)
            suc = insucc(root);
            cout<< "* ";
            // return "* ";
        return;
    }

    if (root->data > key)
    {
        cout<<"# ";
        suc = root;
        findpresucc(root->left, pre, suc, key);
    }

    else if (root->data < key)
    {
        cout<<"$ ";
        pre = root;
        findpresucc(root->right, pre, suc, key);
    }
}

int main(int argc, char const *argv[])
{
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
    inorder(root);
    findpresucc(root, pre,suc, 4);
    cout<<"dafdfs";
    // if(pre!= NULL)
    cout <<"yeline na ho pa ri h"<< pre->data << "  " << suc->data;
    return 0;
}
