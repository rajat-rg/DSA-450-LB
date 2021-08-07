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
} *root = NULL, *root2 = NULL;
int c=0;
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

    inorder(root->left, v);
    cout << root->data << " -> ";
    v.push_back(root->data);
    // cout<<v.back();
    inorder(root->right, v);
}

int findPair(vector<int> v, vector<int> v2, int k)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int val = k - v[i];
        for (int j = 0; j < v2.size(); j++)
        {
            if (v2[j] == abs(val))
            {
                count++;
            }
        }
    }
    return count;
}
int find_kro(int a, tree* root)
{
    cout<<a<<"+";
    if(root == NULL)return 0;
    if(root->data == a)return 1;

    else if(a<root->data)find_kro(a,root->left);
    else
    find_kro(a,root->right);
    return 0;
}
int findPairOptimal(tree* root, tree* root2, int k)
{
    if(root == NULL)return 0;

    findPairOptimal(root->left,root2,k);
    // cout<<k-root->data<<"--";
    c += find_kro(k-root->data, root2);
    findPairOptimal(root->right,root2,k);

    return c;


}
int main(int argc, char const *argv[])
{
    vector<int> v;

    vector<int> v2;

    int n1, n2;
    cout << "Number of nodes for first BST:\n";
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
    inorder(root, v);

    cout << "Number of nodes for second BST:\n";
    cin >> n2;
    while (n2)
    {
        cout << "Enter number";
        int no;
        cin >> no;
        root2 = create_BST(root2, no);
        n2--;
    }
    // v2.empty();
    cout << endl;
    inorder(root2, v2);

    cout << "\nEnter K\n";
    int k, i, val;
    cin >> k;
    // int t = findPair(v, v2, k);
    int t = findPairOptimal(root, root2, k);
    cout << endl
         << c;

    return 0;
}
