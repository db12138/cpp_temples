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
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        if(target <= 0)
        {
            return ans;
        }
        
        if(candidates.size() == 1)
        {
            if(candidates[0] <= target && target%candidates[0] == 0)
            {
                vector<int> temp;
                for(int i=0;i<target/candidates[0]; i++)
                    temp.push_back(candidates[0]);
                ans.push_back(temp);
                return ans;
            }
            else
            {
                return ans;
            }
        }
        vector<int> arg1;
        for(int i=0;i<candidates.size()-1;i++)
            arg1.push_back(candidates[i]);
        vector<vector<int> > temp1 = combinationSum(arg1 , target);
        for(int i=0;i<temp1.size();i++)
        {
            ans.push_back(temp1[i]);
        }
        
        int t1 = target-candidates[candidates.size()-1];
        if(t1 == 0)
        {
            vector<int> temp;
            temp.push_back(candidates[candidates.size()-1]);
            ans.push_back(temp);
        }
        else
        {
            vector<vector<int> > temp2 = combinationSum(candidates, t1);
            for(int i=0;i<temp2.size();i++)
            {
                temp2[i].push_back(candidates[candidates.size()-1]);
                ans.push_back(temp2[i]);
            }
        }
        return ans;
    }
};

int main()
{
    
    Solution x;
    vector<int> candi= {2,3,6,7};
    vector<vector<int>> ans = x.combinationSum(candi, 7);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    

    return 0;
    
}

