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

 struct UndirectedGraphNode {
 int label;
 vector<struct UndirectedGraphNode *> neighbors;
 UndirectedGraphNode(int x) : label(x) {}
 };

//注意a == NULL b == NULL 这种情况没考虑

class Path {
public:
    bool Myfind(queue <UndirectedGraphNode *> Q,int label)
    {
        while(!Q.empty())
        {
            UndirectedGraphNode * cur = Q.front();
            if(cur ->label == label)
                return true;
            Q.pop();
        }
        return false;
    }
    bool checkoneside(UndirectedGraphNode* a, UndirectedGraphNode* b)
    {
        if(a == NULL || b ==NULL)
            return false;
        else if(a == b)
            return true;
        map <UndirectedGraphNode*,bool> mp1;
        queue<UndirectedGraphNode*> Q;
        Q.push(a);
        mp1[a] = true;
        while(!Q.empty())
        {
            UndirectedGraphNode* cur = Q.front();
            Q.pop();
            vector<UndirectedGraphNode*> neigh = cur->neighbors;
            for(int i=0;i<neigh.size();i++)
            {
                if(neigh[i]->label == b->label)
                    return true;
                else
                {
                    if(mp1[neigh[i]] != true)
                    {
                        Q.push(neigh[i]);
                        mp1[neigh[i]] = true;
                    }
                    
                }
            }
        }
        return false;
    }
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        // write code here  BFS
        bool J1 = checkoneside(a,b);
        bool J2 = checkoneside(b,a);
        if(J1 || J2)
            return true;
        else
            return false;
    }
};
int main()
{
    map<int,bool> m1;
    m1[77] = true;
    if(m1.find(7) == m1.end())
        cout<<"sadfa"<<endl;
    
    cout<<m1[33]<<endl;
    return 0;
}


