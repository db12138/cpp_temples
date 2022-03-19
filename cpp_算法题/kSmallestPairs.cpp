#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
//class Solution {
//public:
//    vector<int > oneSmallest(vector<int>& nums1, vector<int>& nums2,int curup,int curdown)
//    {
//        if(curup == nums1.size()-1 && curdown == nums2.size()-1)
//        {
//            vector<int> temp;
//            return temp;
//        }
//        if(curup == nums1.size()-1)
//        {
//            vector<int> temp;
//            temp.push_back(curup);
//            temp.push_back(curdown+1);
//            return temp;
//        }
//        if(curdown == nums2.size()-1)
//        {
//            vector<int> temp;
//            temp.push_back(curup+1);
//            temp.push_back(0);
//            return temp;
//        }
//        if(curup<=curdown)
//        {
//            if(nums1[curup] + nums2[curdown+1] <= nums1[curup+1]+nums2[0])
//            {
//                vector<int> temp;
//                temp.push_back(curup);
//                temp.push_back(curdown+1);
//                return temp;
//            }
//            else
//            {
//                vector<int> temp;
//                temp.push_back(curup+1);
//                temp.push_back(0);
//                return temp;
//            }
//
//        }
//        else
//        {
//            if(nums1[curup] + nums2[curdown+1] <= nums1[curup-1]+nums2[curdown+1])
//            {
//                vector<int> temp;
//                temp.push_back(curup);
//                temp.push_back(curdown+1);
//                return temp;
//            }
//            else
//            {
//                vector<int> temp;
//                temp.push_back(curup);
//                temp.push_back(curdown+1);
//                return temp;
//            }
//        }
//    }
//    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//
//        vector<vector<int>> ans;
//        if(nums1.size() == 0 || nums2.size()==0)
//            return ans;
//        vector<int> temp;
//        temp.push_back(nums1[0]);
//        temp.push_back(nums2[0]);
//        ans.push_back(temp);
//        int curup = 0;
//        int curdown=0;
//        for(int i=0;i<k-1;i++)
//        {
//            vector<int> t1 = oneSmallest(nums1, nums2, curup, curdown);
//            if(t1.size() == 0)
//                break;
//            curup = t1[0];
//            curdown = t1[1];
//            vector<int> t2;
//
//            t2.push_back(nums1[curup]);
//            t2.push_back(nums2[curdown]);
//            ans.push_back(t2);
//        }
//        return ans;
//    }
//};
struct Node{
    int x;
    int y;
    int sum;
    Node(int t1,int t2){
        x=t1;
        y=t2;
        sum = t1+t2;
    }
};
bool mysort(Node &a1 , Node &a2)
{
    return a1.sum <a2.sum;
}
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<Node> A;
        for(int i=0;i<k && i<nums1.size();i++)
        {
            for(int j=0;j<k && j<nums2.size();j++)
            {
                if(i*j >k)
                    break;
                Node temp(nums1[i],nums2[j]);
                A.push_back(temp);
            }
        }
        sort(A.begin(),A.end(),mysort);
        vector<vector<int>> ans;
        for(int i=0;i<k && i<A.size();i++)
        {
            vector<int> temp;
            temp.push_back(A[i].x);
            temp.push_back(A[i].y);
            ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{
    
    Solution x;
    vector<int> nums1= {1,2};
    vector<int> nums2 = {3};
    vector<vector<int>> ans = x.kSmallestPairs(nums1, nums2, 3);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    

    return 0;
    
}

