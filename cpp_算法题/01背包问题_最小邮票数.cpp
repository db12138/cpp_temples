//
//  main.cpp
//  tx
//
//  Created by cz on 2019/1/10.
//  Copyright © 2019年 cz. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
#define MAX 99999999
int main(int argc, const char * argv[])
{

    int M, N;
    int stamp[20];
    int dp[20][100];
    while(cin>>M>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>stamp[i];
        }
        
        for(int i=0;i<N;i++)
            dp[i][0] = 0;
        for(int j=0;j<=M;j++)
        {
            if(j == stamp[0])
                dp[0][j]=1;
            else
                dp[0][j]=MAX;
        }
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=stamp[i] && dp[i][j] > dp[i-1][j-stamp[i]]+1)
                    dp[i][j] = dp[i-1][j-stamp[i]]+1;
            }
        }
        if( dp[N-1][M] <  MAX)
            cout<<dp[N-1][M]<<endl;
        else
            cout<<"0"<<endl;
        
    }
    return 0;
}
