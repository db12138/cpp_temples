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


//bfs 节点的高度为其由开始的交换次数
queue <string> Q;
string Myswap(string str,int i)
{
    string temp = str;
    char ch = str[i];
    temp[i] = temp[i+1];
    temp[i+1] = ch;
    return temp;
}
map<string,int> M;
//这个题可以优化很多 判断有没有出现过。
int BFS()
{
    while(!Q.empty())
    {
        string cur = Q.front();
        Q.pop();
        if(cur.find("2012") != string::npos )
        {
            //找到了
            return M[cur];
        }
        else
        {
            for(int i=0;i<cur.length()-1;i++)
            {
                string new_temp;
                new_temp = Myswap(cur,i);
                //判断之前有没有出现过在队列中
                if(M.find(new_temp) == M.end())
                {
                    M[new_temp] = M[cur]+1;
                    Q.push(new_temp);
                }
            }
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string initial_str;
    int N;
    while(cin>>N>>initial_str)
    {
        
        Q.push(initial_str);
        M[initial_str] = 0;
        cout<<BFS()<<endl;
        
        //清空队列
        while(!Q.empty())
        {
            Q.pop();
        }
    }
    return 0;
}
