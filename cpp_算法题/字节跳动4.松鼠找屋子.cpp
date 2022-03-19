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

int n,m;
int DFS(int *a,int pos,bool *flag,int cost)
{
    if(flag[pos] == true)
        return -1;
    
    flag[pos] = true;
    if(a[pos]>0)
    {
        a[pos]--;
        return cost;
    }
    else
    {
        int mincost = 0x7fffffff;
        if(pos/2>=1)
        {
            int t1 = DFS(a,pos/2,flag,cost+1);
            if(t1 != -1 && t1 < mincost)
            mincost = t1;
            
        }
        if(pos*2 <= n)
        {
            int t2 = DFS(a,pos*2,flag,cost+1);
            if(t2 != -1 && t2 < mincost)
                mincost = t2;
            
        }
        if(pos*2+1 <= n)
        {
            
            int t3 = DFS(a,pos*2+1,flag,cost+1);
            if(t3 != -1 && t3 < mincost)
                mincost = t3;
            
        }
        return mincost;
    }
}
int main()
{
    cin>>n>>m;
    int *a = new int[n+1];
    int *b = new int[m];
    a[0]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=0;j<m;j++)
        cin>>b[j];
    
    int cost = 0;
    for(int i=0;i<m;i++)
    {
        int pos = b[i];
        if(a[pos] > 0)
            a[pos]--;
        else
        {
            bool *flag = new bool[n];
            for(int k=0;k<n;k++)
            {
                flag[k] = false;
            }
            cost+=DFS(a,pos,flag,0);
        }
    }
    cout<<cost<<endl;
    
}

