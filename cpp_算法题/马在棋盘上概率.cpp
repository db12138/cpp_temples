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
    double dp[101][25][25];
    Solution()
    {
        memset(dp, 0, sizeof(dp));
    }
    int dirc[8][2] = {{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1},{-2,-1},{-2,1}};
    double knightProbability(int N, int K, int r, int c) {
        
        if(r <0 || r>N-1 || c<0 || c>N-1)
            return 0;
        if(K == 1)
        {
            int ans = 0;
            for(int i=0;i<8;i++)
            {
                if((r+dirc[i][0] >= 0) && (r+dirc[i][0]<N) && (c+dirc[i][1] >=0) && (c+dirc[i][1] < N))
                {
                    ans++;
                }
            }
            dp[1][r][c] = (double)ans/8;
            return dp[1][r][c];
        }
        if(K == 0)
            return 1.0;
        if(dp[K][r][c] != 0)
            return dp[K][r][c];
        else
        {
            for(int i=0;i<8;i++)
            {
                dp[K][r][c] += knightProbability(N, K-1, r-dirc[i][0],c-dirc[i][1] )*0.125;
            }
            return dp[K][r][c];
        }
    }
};

int main()
{
    
    Solution x;
    cout<<x.knightProbability(10, 13, 5, 3);
    

    return 0;
    
}

