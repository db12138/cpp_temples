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

string myFun(string str)
{
    string ans = "";
//    bool flag = false;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '%')
        {
//            flag = true;
            string str_num = "";
            int t2 = i-1;
            for(;t2>=0;t2--)
            {
                if(str[t2] >='0' && str[t2] <='9')
                    str_num += str[t2];
                else
                {
                    break;
                }
            }
            reverse(str_num.begin(), str_num.end());
            //cout<<str_num<<endl;
            int repeatNum = atoi(str_num.c_str());
            for(int t3=0;t3<=t2;t3++)
            {
                ans+=str[t3];
            }
            
            int begin = i;
            int end = 0;
            int t = 1;
            for(int k=i+1;k<str.length();k++)
            {
                if(str[k] == '%')
                    t++;
                else if(str[k] == '#')
                    t--;
                
                if(t == 0)
                {    end = k;
                    break;
                }
            }
            
            string temp = str.substr(begin+1,end-begin-1);
            //cout<<temp<<endl;
            string res1 = myFun(temp);
            
            //cout<<repeatNum<<endl;
           
            for(int t1 = 0;t1<repeatNum;t1++)
            {
                ans+=res1;
            }
            if(end != str.length()-1)
            {
                
                ans += myFun(str.substr(end+1,str.length()-end-1));
            }
            return ans;
        }
    }
    
    return str;
}

int main()
{
    string str;
    cin>>str;
    cout<<myFun(str)<<endl;
    
}

