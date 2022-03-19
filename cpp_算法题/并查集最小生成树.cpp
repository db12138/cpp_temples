#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
//基于并查集的最小生成树 kruskal 实现 外加已经建好的等价于代价为0 ；非常好的思路 值得学习
//还不用邻接矩阵什么的 不用缩边
struct edge{
    int a;
    int b;
    int cost;
    int flag;
};
bool cmp(edge &A,edge &B)
{
    if(A.flag != B.flag)
    {
        return A.flag > B.flag;
    }
    else
    {
        return A.cost<B.cost;
    }
}
int Findroot(vector<int> &Tree,int num)
{
    int cur = num;
    while(Tree[cur] != -1)
    {
        cur = Tree[cur];
    }
    return cur;
}
int main(){
    int n;
    while(cin>>n)
    {
        vector<int> Tree(n+1);
        for(int i=1;i<=n;i++)
        {
            Tree[i] = -1;
        }
        vector<edge> ed(n*(n-1)/2);
        for(int i=0;i< n*(n-1)/2;i++)
        {
            edge temp;
            cin>>temp.a>>temp.b>>temp.cost>>temp.flag;
            ed[i] = temp;
        }
        sort(ed.begin(),ed.end(),cmp);
        
        int sum = 0;
        for(int i=0;i<ed.size();i++)
        {
            int ra = Findroot(Tree,ed[i].a);
            int rb = Findroot(Tree,ed[i].b);
            if(ra != rb)
            {
                Tree[rb] = ra;
                if(ed[i].flag == 0)
                {
                    sum+= ed[i].cost;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
