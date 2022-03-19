#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Node{
    char ch;
    int deep;
    Node *lchild;
    Node *rchild;
};
Node *findnode(vector<Node> &A,Node p)
{

    for(int i=0;i<A.size();i++)
    {
        if(A[i].ch == p.ch)
            return &A[i];
    }
    p.deep =0;
    p.lchild = NULL;
    p.rchild =NULL;
    A.push_back(p);
    return &A[A.size()-1];
}
int  mysearch(vector<Node>A,char ch1,char ch2)
{
    int c1index = -1;
    int c2index = -1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i].ch == ch1)
            c1index = i;
        if(A[i].ch == ch2)
            c2index = i;
    }

    if(c1index!=-1 && c2index != -1)
    {
        Node *head = &A[c1index];
        queue<Node*> que;
        que.push(head);
        while(!que.empty())
        {

            Node *p =que.front();
            que.pop();
            if(p != NULL)
            {
                if(p->ch == ch2)
                {
                    return p->deep - head->deep;
                }
                que.push(p->lchild);
                que.push(p->rchild);
            }
        }
        return -1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n,m;
    vector<Node> A(100);
    while(cin>>n>>m)
    {
        string temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            Node p,p1,p2;
            p.ch = temp[0];
            p1.ch = temp[1];
            p2.ch = temp[2];
            Node *c1 = findnode(A,p);
            Node *c2 = findnode(A,p1);
            Node* c3 = findnode(A,p2);
            c1->lchild = c2;
            c1->rchild = c3;
            c2->deep = c1->deep+1;
            c3->deep = c1->deep+1;
        }
        
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            char ch1 = temp[0];
            char ch2 = temp[1];
            int deep1 = mysearch(A, ch1, ch2);
            if(deep1 != -1)
            {
                if(deep1 == 1 )
                    cout<<"child"<<endl;
                else if(deep1 == 2)
                    cout<<"grandchild"<<endl;
                else
                {
                    string ans="";
                    while(deep1>=3)
                    {
                        ans +="great-";
                        deep1--;
                    }
                    ans+="grandchild";
                    cout<<ans<<endl;
                }
            }
            else
            {
                int deep2 = mysearch(A,ch2,ch1);
                if(deep2 != -1)
                {
                    if(deep2 == 1 )
                        cout<<"parent"<<endl;
                    else if(deep2 == 2)
                        cout<<"grandparent"<<endl;
                    else
                    {
                        string ans="";
                        while(deep2>=3)
                        {
                            ans +="great-";
                            deep2--;
                        }
                        ans+="grandparent";
                        cout<<ans<<endl;
                    }
                }
                else
                {
                    cout<<"-"<<endl;
                }
            }
            
            
        }
        
    }
    return 0;
}


