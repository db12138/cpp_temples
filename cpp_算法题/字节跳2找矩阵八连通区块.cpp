#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<cstring>
using namespace std;
int dirct[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
struct Node
{
    int val;
    bool flag;
};
int curnum = 1;
int n,m;
void DFS(Node **A,int curx,int cury)
{
    A[curx][cury].flag = true;
    A[curx][cury].val = curnum;
    
    for(int i=0;i<8;i++)
    {
        int nextx = curx + dirct[i][0];
        int nexty = cury + dirct[i][1];
        if(nextx >=0 && nextx <n && nexty >=0 && nexty <m)
        {
            if(A[nextx][nexty].val == 1 && A[nextx][nexty].flag == false)
                DFS(A,nextx,nexty);
        }
    }
}
int main()
{
    
    cin>>n>>m;
    Node **A = new Node *[n];
    for(int i=0;i<n;i++)
    {
        A[i] = new Node[m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j].val;
            A[i][j].flag = false;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j].flag == false && A[i][j].val == 1)
            {
                DFS(A,i,j);
                curnum++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<A[i][j].val;
        }
        cout<<endl;
    }
    cout<<curnum-1<<endl;
}

