#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool binaryFind(vector<int> a , int target)
    {
        int begin=0;
        int end = a.size()-1;
        if(begin==end && target == a[begin])
            return true;
        int mid = (begin+end)/2;
        while(begin != mid )
        {
            if(a[mid] < target)
            {
                begin = mid;
            }
            else if(a[mid] > target)
                end = mid;
            else
            {
                
                return true;
            }
            mid = (begin+end)/2;
        }
        if(a[begin] == target || a[end] == target)
            return true;
        else
            return false;
    }

    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 1)
        {
            return binaryFind(array[0],target);
        }
        int begin=0;
        for(;begin<array.size();begin++)
        {
            if(array[begin][0] > target )
            {
                begin = begin -1;
                break;
            }   
        }
    
        vector<vector<int> > temp(begin);
        int colnum = array[0].size();
        for(int i=0;i<begin;i++)
        {
            temp[i].resize(colnum-1);
        }
        for(int i=0;i<begin;i++)
        {
            for(int j=1;j<colnum;j++)
            {
                temp[i][j-1] = array[i][j];
            }
        }
        return Find(target,temp);
    }
};
int main()
{
    Solution A;
    vector<int> temp ;
    for(int i=0;i<6;i++)
    {
        temp.push_back(i);
    }
    vector<vector<int> > B;
    B.push_back(temp);
    //cout<<A.binaryFind(temp,5)<<endl;
    cout<<A.Find(5,B)<<endl;
}