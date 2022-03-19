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
    int next;
};
int main()
{
    int addr1,addr2,N;
    while(cin>>addr1>>addr2>>N)
    {
        vector<Node> St(100000);
        for(int i=0;i<N;i++)
        {
            int cur_addr;
            Node temp;
            cin>>cur_addr>>temp.ch>>temp.next;
            St[cur_addr] = temp;
        }
        vector<int> list1;
        vector<int > list2;
        
        while(addr1 != -1)
        {
            list1.push_back(addr1);
            addr1 = St[addr1].next;
        }
        while(addr2 != -1)
        {
            list2.push_back(addr2);
            addr2 = St[addr2].next;
        }
        int ans = -1;
        for(int i=0;i<list1.size();i++)
        {
            for(int j=0;j<list2.size();j++)
            {
                if(list1[i] == list2[j])
                {
                    ans = list1[i];
                    goto L1;
                }
            }
        }
    L1:
        cout<<ans<<endl;
    }
    return 0;
}


