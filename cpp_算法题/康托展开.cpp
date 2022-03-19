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
class Solution
{
public:
    int N;
    int *a; 
    int *tree_array;
    ll *prefix_factor;
    ll mod = 998244353;
    int *lowbit;
    int sum(int index)
    {
        int res = 0;
        while(index > 0)
        {
            res += tree_array[index];
            index -= lowbit[index];
        }
        return res;
    }
    void add(int index,int val)
    {
        while(index <= N)
        {
            tree_array[index] += val;
            index += lowbit[index];
        }
    }
	Solution()
	{
        cin>>this->N;
        this->a = new int[this->N + 1];
        this->tree_array  = new int[this->N + 1];
        this->lowbit = new int[this->N+1];
        for(int i=1;i<=this->N;i++)
        {
            cin>>this->a[i];
            lowbit[i]=i&-i;
        }
        for(int i=1;i<=this->N;i++)
        {
            add(i,1);
        }

        prefix_factor = new ll[this->N];
        prefix_factor[1] = 1;
        for(int i=2;i<this->N;i++)
        {
            prefix_factor[i] = (prefix_factor[i-1]*i) % this->mod;
        }
        ll res=0;
        for(int i=1;i<N;i++)
        {
            // cout<<"factor :"<<(N-i)<<" "<<prefix_factor[N-i]<<endl;
            // cout<<"sum: "<<sum(a[i])<<endl;
            res += (prefix_factor[N-i] * (sum(a[i])-1 )) % this->mod;
            add(a[i],-1);
            // for(int i=1;i<=N;i++)
            //     cout<<tree_array[i]<<" ";
            // cout<<endl;
        }
        res+=1;
        cout<<(res % this->mod)<<endl;
        
    }
};
int main ()
{
    //ifstream fin("P1886_3.in");
	//cin.rdbuf(fin.rdbuf());
	Solution x = Solution();
	return 0;
}