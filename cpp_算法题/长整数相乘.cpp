//长整数相乘
#include <iostream>
#include <string>
using namespace std;
class Solution{
    
public:
    string add(string s1,string s2)
    {
        string str1;
        string str2;
        if(s1.length() < s2.length())
        {
            str1 = s1;
            str2 = s2;
        }
        else
        {
            str1 = s2;
            str2 = s1;
        }
        string result;
        int car = 0;
        int i=0;
        for(;i<str1.length();i++)
        {
            int x1 = str1[i]-'0';
            int x2 = str2[i]-'0';
            int t1 = x1+x2+car;
            int t2 = t1%10;
            char c = '0'+t2;
            result.push_back(c);
            
            car = t1 /10;
        }
        for(int j=(int)str1.length();j<str2.length();j++)
        {
            int x1 = str2[j] - '0';
            int t1 = x1+car;
            int t2 = t1 %10;
            car  = t1 / 10;
            result.push_back('0'+t2);
        }
        if(car != 0)
            result.push_back('0'+car);
        return result;
    }
    string myreverse(string A)
    {
        string Ar;
        for(int i=(int) A.length()-1;i>=0 ;i--)
        {
            Ar.push_back(A[i]);
        }
        return Ar;
    }
    string multiply(string A,string B)
    {
        

        
        string Ar = myreverse(A);
        string Br = myreverse(B);
        
        string strShort;
        string strLong;
        if(Ar.length() > Br.length())
        {
            strShort=Ar;
            strLong = Br;
        }
        else
        {
            strShort = Br;
            strLong = Ar;
        }
        string sum="0";
        for(int i=0;i<strShort.length();i++)
        {
            char cur = strShort[i];
            int t2 = 0;
            string temp;
            for(int k = 0;k<i;k++)
            {
                temp.push_back('0');
            }
            for(int j=0;j<strLong.length();j++)
            {
                char c2 = strLong[j];
                int x1 = cur - '0';
                int x2 = c2 - '0';
                int t1 = x1*x2 % 10;
                int t3 = t1+t2 ;
                
                temp.push_back('0'+t3%10);
                t2 = x1*x2 / 10 + t3 / 10;
            }
            if(t2 != 0)
                temp.push_back('0'+t2);
           
            sum = add(sum,temp);
            
        }
        string ans = myreverse(sum);
        while(ans.length() > 1 && ans[0] == '0')
        {
            ans.erase(ans.begin());
        }
        //cout<<1234*4321<<endl;
        return ans;
    }
};
int main()
{
    Solution A;
    cout<<A.multiply("123456789", "45675")<<endl;
//    string A = "1234";
//    A.erase(A.begin()+1);
//    cout<<A<<endl;
//    cout<<A.length();
}

