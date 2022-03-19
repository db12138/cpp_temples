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
#include <algorithm>
using namespace std;
long long max(long long a,long long b)
{
    return a>b ? a:b;
}
int main(int argc, const char * argv[])
{
    int N;
    while(cin>>N)
    {
        
        long long sum = 0;
        long long Max = 0xffffffffffffffff;
        for(int i=0;i<N;i++)
        {
            int x;
            cin>>x;
            sum = max(sum+x,x);
            Max = max(Max,sum);
        }
        cout<<Max<<endl;
    }
    return 0;
}

