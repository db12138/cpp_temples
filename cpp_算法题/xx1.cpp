#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node (int x){val = x;left = NULL;right = NULL;}
};
void DFS(Node *root)
{
    if(root == NULL)
        return;
    cout<<root->val;
    DFS(root->left);
    DFS(root->right);
}
void BFS(Node *root)
{
    queue<Node* > A;
    A.push(root);
    while(!A.empty())
    {
        Node * temp = A.front();
        A.pop();
        cout<<temp->val;
        if(temp->left != NULL)
            A.push(temp->left);
        if(temp->right != NULL)
            A.push(temp->right);
    }
}
int main() {
//    Node *root = new Node;
//    root->val = 1;
//    root->left = new Node;
//    root->left->val = 2;
//    root->right = new Node;
//    root->right->val = 3;
//    root->right->left = NULL;
//    root->right->right = NULL;
//    root->left->left = new Node;
//    root->left->left->val = 4;
//    root->left->left->left = NULL;
//
//    root->left->right = new Node;
//    root->left->right->val = 5;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //cout<<root->val;
    DFS(root);
    cout<<endl;
    BFS(root);
    
    //cout << "Hello World!" << endl;
}
