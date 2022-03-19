/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//重建二叉树 注意加上判断 细节 容易出错
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0)
            return NULL;
        TreeNode * root = new TreeNode(0);
        if(vin.size() == 1)
        {
            root->val = vin[0];
            return root ;
        }
        
        int currootval = pre[0];
        root->val = currootval;
        for(int j=0;j<vin.size();j++)
        {
            if(currootval == vin[j])
            {
                vector<int> newpre1,newvin1;
                
                for(int k=0;k<j;k++)
                {
                    newpre1.push_back(pre[k+1]);
                    newvin1.push_back(vin[k]);
                }
                
                vector<int> newpre2,newvin2;
                for(int k2 = 0;k2<vin.size()-j-1;k2++)
                {
                    if( j <vin.size()-1) //这里加上
                    {
                        newpre2.push_back( pre[1+j+k2]);
                        newvin2.push_back( vin[j+1+k2]);
                    }
                }
                root->left = reConstructBinaryTree(newpre1,newvin1);
                root->right =  reConstructBinaryTree(newpre2,newvin2);
                return root;
            }
        }
        return root;
    }
};
