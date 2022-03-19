#include<iostream>
#include<cstring>
using namespace std;
class KMPSolution
{
public:
   KMPSolution()
   {
      string target;
      string pattern;
      cin>>target;
      cin>>pattern;
      int lt = target.length();
      int lp = pattern.length();
      target = "0"+target;
      pattern = "0"+ pattern;
      int *kmp = new int[lp+1];
      memset(kmp,0,sizeof(int)*(lp+1));
      int j=0;
      for(int i=2;i<=lp;i++)
      {
         while(j && (pattern[j+1] != pattern[i]))
            j = kmp[j];
         if(pattern[j+1] == pattern[i])
            j++;
         kmp[i] = j;
      }
      j= 0;
      for(int i=1;i<=lt;i++)
      {
         while(j && pattern[j+1] != target[i])
         {
            j = kmp[j];
         }
         if(pattern[j+1] == target[i])
            j++;
         if(j == lp)
         {
            cout<<i-lp+1<<endl;
            j=kmp[j];
         }
      }
      for (int i=1;i<=lp;i++)
         cout<<kmp[i]<<" ";
   }

};
int main()
{
   KMPSolution x;
   return 0;
}