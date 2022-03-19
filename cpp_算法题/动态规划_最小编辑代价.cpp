

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//刷LeetCode就像练级一样 打游戏一样 贼爽 666 学会新招的感觉
//长度为i的A修改为长度为j的B可以分为：
//1、长度为i的A修改为长度为j-1的B，然后插入j位置的字符；
//2、长度为i-1的A修改为长度为j的B，然后删除i位置的字符；
//3、长度为i-1的A修改为长度为j-1的B，然后i位置的字符修改为j位置的字符。
class MinCost {
public:
    int min(int x,int y,int z)
    {
        int mmin = x;
        mmin = mmin>y?y:mmin;
        mmin = mmin>z?z:mmin;
        
        return mmin;
    }
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        vector<vector<int>> dp(n+1);
        //n+1 * m+1
        for(int i=0;i<n+1;i++)
        {
            dp[i].resize(m+1);
        }
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = i*c1;
        }
        for(int i=0;i<m+1;i++)
        {
            dp[0][i] = i*c0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(A[i-1] == B[j-1])  //出错点 字符下标是少一位的
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i][j-1]+c0,dp[i-1][j]+c1,dp[i-1][j-1]+c2);
                }
            }
        }
        return dp[n][m];
    }
};
int main(){
    vector<int > ttt(88);
    cout<<ttt[64];
    return 0;
}
