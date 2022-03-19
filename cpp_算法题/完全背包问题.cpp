#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<fstream>
#include <typeinfo>
#include <sstream>
#include <regex>
using namespace std;
#define ll long long
const int N=1e4+5;
ll w[N],v[N];
int main ()
{
    // ifstream fin("P1616_1.in");
	// cin.rdbuf(fin.rdbuf());
    ll t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i]>>v[i];
    }
    //二维会空间超限。 看看动态转移方差 dp[i][j] 依赖于上一行的dp[i-1][j] 和当前这一行dp[i][j-w[i]]
    //所以说只要保留当前一行就行了
    //上一行的保留在原来的位置
    //这一行从前往后更新就可
    ll *dp = new ll[t+1];
    memset(dp,0,sizeof(ll)*(t+1));
    for(int i=1;i<=m;i++)
    {
        for(int j=w[i];j<=t;j++)
        {
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[t]<<endl;
    //二维数组方法
    // ll **dp = new ll*[m+1];
    // for(int i=0;i<=m;i++)
    // {
    //     dp[i] = new ll[t+1];
    //     memset(dp[i],0,sizeof(ll)*(t+1));
    // }
    // for(int i=1;i<=m;i++)
    // {
    //     for(int j=1;j<=t;j++)
    //     {
    //         if(j-w[i]< 0)
    //             dp[i][j] = dp[i-1][j];
    //         else
    //             dp[i][j] = max(dp[i-1][j],dp[i][j-w[i]]+v[i]);
    //         //cout<<dp[i][j]<<endl;
    //     }
    // }
    // cout<<dp[m][t]<<endl; 
	return 0;
}