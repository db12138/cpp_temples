#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

//主要算平均数之后 int+ int /2 有精度损失
int main(){
    int  P,T,G1,G2,G3,GJ;
    while(cin>>P>>T>>G1>>G2>>G3>>GJ)
    {
        double ans = 0;
        if(abs(G1-G2) <= T)
            ans =(double) (G2+G1)/2;
        else
        {
            bool J1 = false;
            if(abs(G3-G1) <= T)
                J1 = true;
            bool J2 =false;
            if(abs(G3-G2)<=T)
                J2 = true;
            if(J1 && J2)
            {
                ans = max(G1,max(G2,G3));
            }
            else if(J1)
            {
                ans = (double)(G3+G1)/2;
            }
            else if(J2)
            {
                ans = (double)(G3+G2)/2;
            }
            else
            {
                ans = GJ;
            }
        }
        cout<<fixed<<setprecision(1)<<ans<<endl;
        
        
    }
    
    return 0;
}


