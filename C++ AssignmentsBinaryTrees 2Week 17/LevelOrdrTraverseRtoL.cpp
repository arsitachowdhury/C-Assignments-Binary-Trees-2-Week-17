#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void TraverseUsingQueueRev(Node* root){
    queue<Node*>q;
    q.push(root);
    while(q.size()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->right!=NULL) q.push(temp->right);
        if(temp->left!=NULL) q.push(temp->left);
    }
    cout<<endl;
}
int main()
{
    Node* a=new Node(1);
    Node* b=new Node(7);
    Node* c=new Node(9);
    Node* d=new Node(2);
    Node* e=new Node(6);
    Node* f=new Node(9);
    Node* g=new Node(5);
    Node* h=new Node(11);
    Node* i=new Node(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    e->left=g;
    e->right=h;
    f->left=i;
   TraverseUsingQueueRev(a);
    return 0;
}