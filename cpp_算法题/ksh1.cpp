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
//ks 2018 H Big button;
typedef long long ll;
ll Pow(ll base,ll ex)
{
    ll ans = 1;
    for(int i=0;i<ex;i++)
    {
        ans*=base;
    }
    return ans;
}
bool issubString(string str1,string str2)
{
    
    if(str1.length()<=str2.length())
    {
        for(int i=0;i<str1.length();i++)
        {
            if(str1[i] != str2[i])
                return false;
        }
        return true;
    }
    else{
        for(int i=0;i<str2.length();i++)
        {
            if(str2[i] != str1[i])
                return false;
        }
        return true;
    }
}
int main() {
    int T;
    cin>>T;
    int k = 1;
    while(k<=T)
    {
        int N,P;
        cin>>N>>P;
        ll ans = Pow(2,N);
        vector<string> strsets;
        
        for(int i=0;i<P;i++)
        {
            string temp;
            cin>>temp;
            //check
            bool flag = false;
            for(int t1 = 0;t1<strsets.size();t1++)
            {
                if(strsets[t1][0] == temp[0])
                {
                    bool judge = issubString(temp,strsets[t1]);
                    if(judge)
                    {
                        if(temp.length() < strsets[t1].length())
                            strsets[t1] = temp;
                        flag = true;
                        break;
                    }
                    
                }
            }
            if(flag == false)
                strsets.push_back(temp);
        }
        for(int t1 = 0;t1<strsets.size();t1++)
        {
            ans -= Pow(2,N-strsets[t1].length());
        }
        
        cout<<"Case #"<<k<<": "<<ans<<endl;
        
        k++;
    }
   
    return 0;
}
