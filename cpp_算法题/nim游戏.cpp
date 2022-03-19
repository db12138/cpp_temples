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

class Solution
{
public:
	Solution()
	{
        int T;
        cin>>T;
        while(T--)
        {
            int n;
            cin>>n;
            int ans=0;
            cin>>ans;
            for(int i=1;i<n;i++)
            {
                int temp;
                cin>>temp;
                ans ^= temp;
            }
            if(ans)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
};


int main ()
{
    //ifstream fin("P1886_3.in");
	//cin.rdbuf(fin.rdbuf());
	Solution x = Solution();
	return 0;
}