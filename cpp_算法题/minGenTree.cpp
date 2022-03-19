//最小生成树
//https://nanti.jisuanke.com/t/34
#include <iostream>
#include <vector>
#define MAX 80000000
using namespace std;
struct treenode
{
    int num;
    int weight;
    int lastnode;
};
bool inNodeSet(int num,vector<treenode>nodeSet)
{
    int i=0;
    for(;i<nodeSet.size();i++)
    {
        if(nodeSet[i].num == num)
            return true;
    }
    return false;
}
int minGenTree(int **A,int N)
{
    vector <treenode> nodeSet;
    treenode start;
    start.num = 0;
    start.lastnode = -1;
    nodeSet.push_back(start);
    
    int sumWeight = 0;
    while(true)
    {
        //getMinFringe(nodeSet);
        treenode min;
        min.weight = MAX;
        
        for(int i=0;i<nodeSet.size();i++)
        {
            for(int j=0;j<N;j++)
            {
                int cur = A[nodeSet[i].num][j];
                if(cur >0  && (inNodeSet(j,nodeSet) == false))
                {
                    if(cur < min.weight)
                    {
                        min.weight=cur;
                        min.lastnode = nodeSet[i].num;
                        min.num = j;
                    }
                }
            }
        }
        if(min.weight == MAX)
        {
            break;
        }
        // printf("%d - > %d : %d\n",min.lastnode,min.num,min.weight);
        sumWeight+=min.weight;
        nodeSet.push_back(min);
    }
    return sumWeight;
}
int main()
{
    int N;
    cin >> N;
    int **A = new int*[N];
    for(int i=0;i<N;i++)
    {
        A[i] = new int[N];
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>A[i][j];
        }
    }
    int min = minGenTree(A, N);
    cout<<min<<endl;
    return 0;
}

