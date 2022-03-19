//
//  main.cpp
//  tx
//
//  Created by cz on 2019/1/10.
//  Copyright © 2019年 cz. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
//二叉树遍历 二叉树的建立 注意细节和逻辑
struct Node
{
    string ch;
    Node * lchild;
    Node * rchild;
};
string str;
int i=0;
Node * createTree()
{
    
    if(str[i] == '#')
    {
        i++;
        return NULL;
    }
    Node * p = new Node;
    p->ch = str[i++];
    p->lchild = createTree();
    p->rchild = createTree();
    return p;
}
void middleOrderTravel(Node *Root)
{
    if(Root == NULL)
        return;
    else
    {
        middleOrderTravel(Root->lchild);
        cout<<Root->ch<<" ";
        middleOrderTravel(Root->rchild);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    while(cin>>str)
    {
        Node * Root = createTree();
        middleOrderTravel(Root);
    }
    return 0;
}
