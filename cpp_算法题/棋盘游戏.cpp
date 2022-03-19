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
//巧妙之处 flag置位 DFS
#define N 6
int minCost = 0x7fffffff;
int startx,starty;
int endx,endy;

int dirct[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int A[6][6];
bool flag[6][6];
void DFS(int status,int curCost,int x,int y)
{
    if(flag[x][y] == true)
        return;
    if(curCost>=minCost)
        return;
    if(x == endx && y == endy)
    {
        if(curCost < minCost)
        {
            minCost = curCost;
            return;
        }
        else
            return;
    }
    flag[x][y] = true;
    for(int i=0;i<4;i++)
    {
        int curx =x+dirct[i][0];
        int cury =y+dirct[i][1];
        if(curx < 0 || cury <0 || curx>=N || cury>= N)
            continue;
        else
        {
            int curStepCost = status*A[curx][cury];
            int curStatus = curStepCost %4 +1;
            DFS(curStatus,curCost+curStepCost,curx,cury);
        }
        
    }
    flag[x][y] =false;
    return;
}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>A[i][j];
            flag[i][j] = false;
            
        }
    }
    
    cin>>startx>>starty>>endx>>endy;
    DFS(1,0,startx,starty);
    cout<<minCost<<endl;
    
}

