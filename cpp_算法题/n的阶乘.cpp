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

long long fun(int n)
{
    long long res = 1;
    for(int i=1;i<=n;i++)
        res *=i;
    return res;
}
int main(int argc, const char * argv[])
{
    
    int n;
    while(cin>>n)
    {
        cout<<fun(n)<<endl;
    }
    return 0;
}

