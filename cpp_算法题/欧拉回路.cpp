

#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//欧拉回路 判断节点度即可  简单题
int main(){
    int n,m;
    
    while(cin>>n>>m)
    {
        vector<vector<int >> G(n);
        for(int i=0;i<n;i++)
        {
            G[i].resize(n);
        }
        for(int i=0;i<m;i++)
        {
            int s,e;
            cin>>s>>e;
            G[s-1][e-1] += 1;
            G[e-1][s-1] += 1;
        }
        
        bool judge = true;
        for(int i=0;i<n;i++)
        {
            int deg = 0;
            for(int j=0;j<n;j++)
            {
                deg+=G[i][j];
            }
            
            if(deg %2 == 1)
            {
                judge = false;
                break;
            }
        }
        if(judge == false)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}
