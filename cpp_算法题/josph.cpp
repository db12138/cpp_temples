

#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Joseph {
public:
    int getResult(int n, int m) {
        // write code here
        vector <int> people(n);
        for(int i=0;i<n;i++)
        {
            people[i] = i;
        }
        int count = 0;
        int pos= -1;
        while(people.size()>1)
        {
            //报数
            pos = (pos+1)%people.size();
            count++;
            if(count  == m)
            {
                people.erase(people.begin()+pos);
                pos = pos -1;
                count = 0;
            }
        }
        cout<<people[0]+1<<endl;
        return people[0]+1;
    }
};
using namespace std;
int main(){
//    vector<int > T;
//    for(int i=0;i<5;i++)
//    {
//        T.push_back(i);
//    }
//    T.erase(T.begin());
//    for(int i=0;i<5;i++)
//    {
//        cout<<T.size()<<endl;
//    }
    Joseph A;
    A.getResult(5, 3);
    return 0;
}
