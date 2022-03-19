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
int main(int argc, const char * argv[])
{
    int x,y;
    while(cin>>x>>y)
    {
        int max,min;
        if(x>y)
        {   max = x;
            min=y;
        }
        else
        {
            max = y;
            min = x;
        }
        while(max != min)
        {
            max = max/2;
            if(max < min)
            {
                int tmp =max;
                max = min;
                min = tmp;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}

