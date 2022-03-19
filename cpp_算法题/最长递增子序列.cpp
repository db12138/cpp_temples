

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//最长递增子序列
int main(){
    
    int num;
    vector<int > A;
    while(cin>>num)
    {
        A.push_back(num);
    }
    vector<int> dp(A.size());
    dp[0]=1;
    for(int i=1;i<A.size();i++)
    {
        int cur_max = 1;
        for(int j=0;j<i;j++)
        {
            int temp = 0;
            if(A[i] > A[j])
                temp = dp[j]+1;
            else
                temp = dp[j];
            if(temp > cur_max)
                cur_max = temp;
        }
        dp[i] = cur_max;
    }
    cout<<dp[A.size()-1]<<endl;;
    return 0;
}
