#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
using namespace std;
//序列化树和反序列化树  因为我要用引用 而人家不让用引用 所以没通过
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string x = "";
        if(root == NULL)
        {
            x+="#|";
            return x;
        }
        else
        {
            string str = "";
            int t = root->val;
            while( t!= 0)
            {
                char c = '0' + t%10;
                str += c;
                t = t/10;
            }
            if(root->val < 0)
                str+='-';
            reverse(str.begin(), str.end());
            x+=str;
            x+="|";
            x+serialize(root->left);
            x+serialize(root->right);
            return x;
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data) {
        char str[10000];
        TreeNode *head = new TreeNode(0);
        strcpy(str,data.c_str());
        char *cur = strtok(str,"|");
        if(strcmp(cur,"#") == 0)
        {
            data = data.substr(2,data.size()-2);
            return NULL;
        }
        else
        {
            int x = atoi(cur);
            head->val = x;
            data = data.substr(strlen(cur),data.size()-strlen(cur));
            head->left = deserialize(data);
            head->right = deserialize(data);
            return head;
        }
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main()
{
    string str = "";
    cout<<str.length()<<endl;
    return 0;
}


