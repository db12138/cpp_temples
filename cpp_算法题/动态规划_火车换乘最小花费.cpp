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
#include<stdio.h>
#include<cassert>
#include <algorithm>
using namespace std;
int L1,L2,L3,C1,C2,C3;
int A,B;
int N;
int get_price(int distance)  //距离到价格的换算函数
{
    if(distance <= L1)
        return C1;
    else if(distance <=L2)
        return C2;
    else if(distance <= L3)
        return C3;
    else
    {
        assert(0);
        return -1; //error
        
    }
}
int compute(int **dp,int *distance,int start,int end) //计算从start站到end站的最小价格
{
    if(dp[start][end] != -1) //说明已经算出来了，填入表中了 直接返回；
        return dp[start][end];
    else
    {
        int Min_cost = 99999999;
        
        //经停中间站的情况 计算出最小价格
        for(int i=start+1;i<end;i++)
        {
            int current_cost = compute(dp,distance,start,i) + compute(dp,distance,i,end);
            if(current_cost < Min_cost)
                Min_cost = current_cost;
        }
        //直接从start 到 end 不经过中间站
        int s2e_distance = distance[end-2]-distance[start-2]; //计算从start站到end的距离
        if(s2e_distance <= L3) //说明可以直达 不用中转
        {
            int direct_price = get_price(s2e_distance);
            if(direct_price < Min_cost)
                Min_cost = direct_price;
        }
        
        dp[start][end] = Min_cost; //填表
        return dp[start][end];
    }
}

int main(int argc, const char * argv[])
{
    while(cin>>L1>>L2>>L3>>C1>>C2>>C3>>A>>B>>N)
    {
        int *distance = new int[N-1]; //第i项表示 第i+2站到第1站的距离
        for(int i=0;i<N-1;i++)
        {
            cin>>distance[i];
        }
        int **dp = new int*[N+1];  //dp[i][j]表示 从i站到j站的最小价格
        for(int i=0;i<N+1;i++)
        {
            dp[i] = new int [N+1];
        }
        for(int i = 0;i<N+1;i++)
        {
            for(int j=0;j<N+1;j++)
            {
                dp[i][j] = -1;
            }
        }
        //初始化
        for(int i=1;i<N;i++)
        {
            int dist;
            if(i > 1)
            {
                dist = distance[i-1] -distance[i-2];  //第i到第i+1个站之间的距离
            }
            else
            {
                dist = distance[0]; //第2个站到第一个站之间的距离
            }
            dp[i][i+1] = get_price(dist); //距离换算为价格
        }
        cout<<compute(dp, distance,A, B)<<endl;
        //释放空间
        for(int i=0;i<N+1;i++)
        {
            delete[] dp[i];
        }
        delete [] dp;
    }
    return 0;
}

