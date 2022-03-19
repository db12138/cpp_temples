//二维数组中的查找 很难想到 好思路
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int cx = array.size()-1;
        int cy = 0;
        int colnum = array[0].size();
        while(cx>=0 && cy<colnum)
        {
            if(array[cx][cy] > target)
            {
                cx-=1;
            }
            else if(array[cx][cy] < target)
                cy+=1;
            else
                return true;
        }
        return false;
    }
};
