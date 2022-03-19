

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//最长回文子串
class Palindrome {
public:
    vector<vector<int>> dp;
    int getLongestPalindrome(string A, int n) {
        // write code here
        dp.resize(n);
        for(int i=0;i<n;i++)
            dp[i].resize(n);
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
        }
        int Max = 1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(A[i] ==A[j])
                {
                    if(i+1 == j)
                        dp[i][j] = 1;
                    else if(i+1 <= j-1  && dp[i+1][j-1] == 1)
                    {
                        dp[i][j] = 1;
                        if(j-i+1 > Max)
                            Max = j-i+1;
                    }
                }
                
            }
        }
        //cout<<dp[1][2]<<endl;
        return Max;
        
    }
};
int main(){
    
    Palindrome T;
    string A = "baabccc";
    cout<<T.getLongestPalindrome(A,A.length() )<<endl;
    return 0;
}
