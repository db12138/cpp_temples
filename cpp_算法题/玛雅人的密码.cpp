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
using namespace std;

struct Node{
    string str;
    int swap_num;
};
//bfs 节点的高度为其由开始的交换次数
queue <Node> Q;
string Myswap(string str,int i)
{
    string temp = str;
    char ch = str[i];
    temp[i] = temp[i+1];
    temp[i+1] = ch;
    return temp;
}

//这个题可以优化很多 判断有没有出现过。
int BFS()
{
    while(!Q.empty())
    {
        Node cur = Q.front();
        Q.pop();
        if(cur.str.find("2012") != string::npos )
        {
            //找到了
            return cur.swap_num;
        }
        else
        {
            for(int i=0;i<cur.str.length()-1;i++)
            {
                Node new_temp;
                new_temp.str = Myswap(cur.str,i);
                new_temp.swap_num = cur.swap_num+1;
                
                //这里push之前应该加一次优化 判断之前有没有出现过在队列中
                Q.push(new_temp);
            }
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Node initial_str;
    initial_str.swap_num = 0;
    int N;
    while(cin>>N>>initial_str.str)
    {
        Q.push(initial_str);
        cout<<BFS()<<endl;
        
        //清空队列
        while(!Q.empty())
        {
            Q.pop();
        }
    }
    return 0;
}
