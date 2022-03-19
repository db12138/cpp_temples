#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<fstream>
#include <typeinfo>
#include <sstream>
#include <regex>
using namespace std;
#define ll long long
int main()
{
    int n;
    int seq_len = 0;
    cin>>n;
    int *seq = new int[n+1];
    memset(seq,0,sizeof(int)*(n+1));
    for(int i=1;i<=n;i++)
    {
        int cur_val;
        cin>>cur_val;
        if(cur_val>seq[seq_len])
            seq[++seq_len]=cur_val;
        else
        {
            *lower_bound(seq+1,seq+seq_len+1,cur_val)=cur_val;
        }
    }
    cout<<n-seq_len<<endl;
    return 0;
}