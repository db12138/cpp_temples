

#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct nation{
    int num;
    int goldmedal;
    int medals;
    int rank;
    double population;
    double goldrate;
    double medalrate;
};
bool goldmedalssort(const nation &A, const nation &B)
{
    return A.goldmedal > B.goldmedal;
}
bool medalssort(const nation &A, const nation &B)
{
    return A.medals > B.medals;
}
bool goldratesort(const nation &A, const nation &B)
{
    if(A.goldrate == B.goldrate)
        return A.goldmedal > B.goldmedal ;
    else
        return A.goldrate>B.goldrate;
}
bool medalratesort(const nation &A, const nation &B)
{
    return A.medalrate>B.medalrate;
}
int Myfind(vector<nation> A,int num)
{
    int rank = -1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i].num == num)
        {
            return A[i].rank;
        }
        
    }
    return rank;
}
void getMinrank(vector<nation>A0,vector<nation>A1,vector<nation>A2,vector<nation>A3,int num,int &rank,int &method)
{
    rank = 999999999;
    int r0 = Myfind(A0,num);
    if(r0<rank)
    {
        rank = r0;
        method = 0;
    }
    int r1 = Myfind(A1,num);
    if(r1<rank)
    {
        rank = r1;
        method = 1;
    }
    int r2 = Myfind(A2,num);
    if(r2<rank)
    {
        rank = r2;
        method = 2;
    }
    int r3 = Myfind(A3,num);
    if(r3<rank)
    {
        rank = r3;
        method = 3;
    }
    
}
void backpatch_rank(vector<nation> &A,int method)
{
    int rank = 0;
    int last_rank =0;
    for(int i=0;i<A.size();i++,rank++)
    {
        if(i == 0)
        {
            A[i].rank = 0;
            last_rank = 0;
        }
        else
        {
            switch (method) {
                case 0:
                    if(A[i-1].goldmedal > A[i].goldmedal)
                    {
                        last_rank = rank;
                    }
                    break;
                case 1:
                    if(A[i-1].medals > A[i].medals)
                    {
                        last_rank = rank;
                    }
                    break;
                case 2:
                    if(A[i-1].goldrate > A[i].goldrate)
                    {
                        last_rank = rank;
                    }
                    break;
                case 3:
                    if(A[i-1].medalrate > A[i].medalrate)
                    {
                        last_rank = rank;
                    }
                    break;
                default:
                    break;
            }
            A[i].rank = last_rank;
        }
    }
}
int main(){
    int n,m;
    while(cin>>n>>m)
    {
        vector<nation> A;
        for(int i=0;i<n;i++)
        {
            nation temp;
            temp.num = i;
            cin>>temp.goldmedal>>temp.medals>>temp.population;
            temp.goldrate = (temp.goldmedal)/temp.population;
            
            temp.medalrate = temp.medals/temp.population;
            //cout<<temp.medalrate<<endl;
            A.push_back(temp);
        }
        vector<nation> A0=A,A1=A,A2=A,A3=A;
        sort(A0.begin(),A0.end(),goldmedalssort);
        backpatch_rank(A0,0);
        sort(A1.begin(),A1.end(),medalssort);
        backpatch_rank(A1,1);
        //cout<<"test"<<A2[4].goldmedal<<endl;
        sort(A2.begin(),A2.end(),goldratesort);
        backpatch_rank(A2,2);
        sort(A3.begin(),A3.end(),medalratesort);
        backpatch_rank(A3,3);
        for(int i=0;i<A2.size();i++)
        {
            cout<<A2[i].rank<<endl;
        }
        
        for(int i=0;i<m;i++)
        {
            int num;
            cin>>num;
            int rank=0,method =0;
            getMinrank(A0,A1,A2,A3,num,rank,method);
            cout<<rank+1<<":"<<method+1<<endl;
        }
        cout<<endl;
    }
    return 0;
}
