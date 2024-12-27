#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int levels(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void helper(Node *root, int &maxDia)
{
    if (root == NULL)
        return;
    int dia = levels(root->left) + levels(root->right);
    maxDia = max(maxDia, dia);
    helper(root->left, maxDia);
    helper(root->right, maxDia);
}
int diameterOfBinaryTree(Node *root)
{
    int maxDia = 0;
    helper(root, maxDia);
    return maxDia;
}
int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    cout<<"The diameter of the tree is "<<diameterOfBinaryTree(a);
    return 0;
}
