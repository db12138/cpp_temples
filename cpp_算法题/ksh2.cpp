#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<cstring>
#include<cmath>
using namespace std;
//ks 2018 H2 Mural;
//注意滑动窗口改进策略
typedef long long ll;

int main() {
    int T;
    cin>>T;
    //cout<<ceil((double)T/2)<<endl;
    int k = 1;
    while(k<=T)
    {
        int N;
        cin>>N;
        int *A = new int[N];
        string str;
        cin>>str;
        for(int i=0;i<str.length();i++)
        {
            
            A[i] = str[i]-'0';
        }
        int sectionnum = ceil((double)N/2);
        ll ans = -1;
        int lastsum = 0;
        //滑动窗口改进
        for(int i=0;i<N-sectionnum+1;i++)
        {
            int temp = 0;
            if(i == 0)
            {
                for(int j=0;j<sectionnum;j++)
                {
                    temp+=A[j];
                }
                if(temp > ans)
                    ans = temp;
                lastsum = temp;
            }
            else
            {
                temp = lastsum-A[i-1]+A[i+sectionnum-1];
                if(temp > ans)
                    ans = temp;
                lastsum = temp;
            }
            
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;

        k++;
    }
   
    return 0;
}
