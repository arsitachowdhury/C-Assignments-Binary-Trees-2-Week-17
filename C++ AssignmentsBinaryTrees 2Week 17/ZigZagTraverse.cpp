#include <iostream>
#include <climits>
#include <vector>
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
void nthLevel(Node *root, int curr, int n, vector<int> &nums)
{
    if (root == NULL)
        return;
    if (curr == n)
    {
        nums.push_back(root->val);
        return;
    }
    if (n % 2 == 0)
    {
        nthLevel(root->left, curr + 1, n, nums);
        nthLevel(root->right, curr + 1, n, nums);
    }
    else
    {
        nthLevel(root->right, curr + 1, n, nums);
        nthLevel(root->left, curr + 1, n, nums);
    }
}
int levels(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void helper(vector<int> &nums, vector<vector<int>> &ans, Node *root)
{
    int n = levels(root);
    for (int i = 0; i < n; i++)
    {
        nthLevel(root, 0, i, nums);
        ans.push_back(nums);
        nums.clear();
    }
}
vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<int> nums;
    vector<vector<int>> ans;
    helper(nums, ans, root);
    return ans;
}
int main()
{
    Node *a = new Node(3);
    Node *b = new Node(9);
    Node *c = new Node(20);
    Node *d = new Node(15);
    Node *e = new Node(7);
    a->left = b;
    a->right = c;
    b->left=NULL;
    b->right=NULL;
    c->left = d;
    c->right = e;
    vector<vector<int>>ans;
    ans=zigzagLevelOrder(a);
      cout << "[";
    for (int i = 0; i < ans.size(); ++i) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j];
            if (j != ans[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != ans.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}
