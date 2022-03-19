

#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
//网易校招 等差数列 很简单的题
int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    int last = 0;
    for(int i=0;i<n-1;i++)
    {
        if (i == 0)
            last =A[i] - A[i+1];
        else if(A[i] - A[i+1] != last)
        {    cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}
