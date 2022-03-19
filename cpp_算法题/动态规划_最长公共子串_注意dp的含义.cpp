

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//最长公共子串 注意dp的含义  不能搞错了
class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        // write code here
        vector<vector<int>> dp(m);
        for(int i=0;i<m;i++)
        {
            dp[i].resize(n);
        }
        int maxnum = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(B[i] == A[j])
                {
                    if(i>0 && j>0)
                        dp[i][j] = dp[i-1][j-1] +1;
                    else
                        dp[i][j] =1;
                }
                if(dp[i][j] > maxnum)
                    maxnum = dp[i][j];
            }
        }
        return maxnum;
    }
};
int main(){
    
    return 0;
}
