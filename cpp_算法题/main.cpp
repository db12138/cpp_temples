#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Node{
    int val;
    int deep;
};
class Solution {
public:
    vector<Node> deleteNode(vector<Node> A,int i)
    {
        for(int k=i;k<A.size()-1;k++)
        {
            A[k] = A[k+1];
        }
        A.resize(A.size()-1);
        return A;
    }
    TreeNode* recoverFromPreorder(string S) {
        TreeNode *root = NULL;
        vector<Node> A;
        
        int num_begin = 0;
        int num_end = 0;
        bool first_meet = true;
        int curdeep = 0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i] != '-')
            {
                if(first_meet)
                {
                    num_begin = i;
                    first_meet = false;
                }
                
            }
            else
            {
                if(first_meet == false)
                {
                    num_end = i;
                    first_meet = true;
                   
                    Node temp;
                    temp.val = stoi(S.substr(num_begin,num_end));
                    temp.deep = curdeep;
                    A.push_back(temp);
                    curdeep = 1;
                }
                else
                {
                    curdeep++;
                }
                
            }
        }
        Node temp;
        temp.val =stoi(S.substr(num_begin,S.size()));
        temp.deep = curdeep;
        A.push_back(temp);
//        for(int i=0;i<A.size();i++)
//        {
//            cout<<A[i].val<<","<<A[i].deep<<endl;
//        }
        TreeNode **nodelist = new TreeNode*[A.size()];
        for(int i = 0;i<A.size();i++)
        {
            nodelist[i] = new TreeNode(A[i].val);
        }
        for(int i = 1;i<A.size();i++)
        {
            int k=i-1;
            for(;k>=0;k--)
            {
                if(A[i].deep -A[k].deep == 1)
                    break;
            }
            if(nodelist[k]->left == NULL)
                nodelist[k]->left = nodelist[i];
            else
                nodelist[k]->right = nodelist[i];
        }
        
        
        return nodelist[0];
    }
};

int main()
{
    
    Solution x;
    x.recoverFromPreorder("1-2--3---4-5--6---7");
    

    return 0;
    
}

