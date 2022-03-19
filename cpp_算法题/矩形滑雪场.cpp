//矩形滑雪场
//https://nanti.jisuanke.com/t/203
#include <iostream>
#include <vector>
using namespace std;
int r,c;
int around(int **A,int i,int j)
{
    //cout<<r<<" "<<c<<endl;
    if(i>=0 && i<r && j>=0 && j<c)
    {
        return A[i][j];
    }
    else
    {
        return -1;
    }
}
int fill(int **A,int **ans,int i,int j)
{
   if(ans[i][j] != -1)
   {
       return ans[i][j];
   }
   else
   {
       int max = 1;
       
       int temp = around(A, i-1, j);
       if(temp != -1)
       {
           if(A[i][j] > temp)
           {
               int cur = fill(A,ans,i-1,j)+1;
               if(cur > max)
                   max = cur;
           }
       }
       
       temp = around(A, i+1, j);
       if(temp != -1)
       {
           if(A[i][j] > temp)
           {
               int cur =  fill(A,ans,i+1,j)+1;
               if(cur > max)
                   max = cur;
           }
       }
       
       temp = around(A, i, j-1);
       if(temp != -1)
       {
           if(A[i][j] > temp)
           {
               int cur =  fill(A,ans,i,j-1)+1;
               if(cur > max)
                   max = cur;
           }
       }
       
       temp = around(A, i, j+1);
       if(temp != -1)
       {
           if(A[i][j] > temp)
           {
               int cur = fill(A,ans,i,j+1)+1;
               if(cur > max)
                   max = cur;
           }
       }
       ans[i][j] = max;
       return ans[i][j];
   }
}
int main()
{
    
    cin >> r>>c;
    int **A = new int*[r];
    int **ans = new int*[r];
    for(int i=0;i<r;i++)
    {
        A[i] = new int[c];
        ans[i] = new int[c];
    }
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>A[i][j];
            ans[i][j] = -1;
        }
    }
    int max = -1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int cur = fill(A,ans,i,j);
            if(cur > max)
                max = cur;
        }
    }
    cout<<max<<endl;
    
    return 0;
}

