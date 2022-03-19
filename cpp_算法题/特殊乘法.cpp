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

int special_mul(string n,string m)
{
    int sum = 0;
    for(int i=0;i<n.length();i++)
    {
        int t1 = n[i] - '0';
        for(int j=0;j<m.length();j++)
        {
            int t2 = m[j]-'0';
            sum +=t1*t2;
        }
    }
    return sum;
}
int main(int argc, const char * argv[])
{
    string n,m;
    while(cin>>n>>m)
    {
        cout<<special_mul(n,m)<<endl;
    }
    return 0;
}

