

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//集合的子集 非常巧妙的 利用二进制思想 非常好
class Subset {
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        // write code here
        int size = 1<<n;
        vector<vector<int>> subsets;
        for(int i=size-1;i>0;i--)
        {
            vector<int > subset;
            for(int j=n-1;j>=0;j--)
            {
                if(i>>j & 1)
                {
                    subset.push_back(A[j]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};

int main(){
    vector<int > ttt(88);
    cout<<ttt[64];
    return 0;
}
