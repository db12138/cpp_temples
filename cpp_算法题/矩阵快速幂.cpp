#include<iostream>
#include<fstream>
#define ll long long
#define mo 1000000007
using namespace std;

class Matrix{
    public:
    Matrix(ll n){
        length = n;
        this->a = new ll*[n];
        for(ll i=0;i<n;i++)
        {
            this->a[i] = new ll[n];
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                this->a[i][j] = 0;
            }
        }
    }
    void identityMatrix()
    {
        for(ll i=0;i<length;i++)
        {
            a[i][i] = 1;
        }
    }
    Matrix operator*(const Matrix &b)
    {
        Matrix c = Matrix(length);
        for(ll i=0;i<length;i++)
        {
            for(ll j=0;j<length;j++)
            {
                for(ll k = 0;k<length;k++)
                {
                    c.a[i][j] += (this->a[i][k] * b.a[k][j]) % mo;
                }
                c.a[i][j] = c.a[i][j] % mo ;
            }
        }
        return c;
    }
    ll length;
    ll **a ;
};
class MatrixMultiSolution
{
    private:
    ll n;
    ll k;
    public:
    MatrixMultiSolution()
    {    
        Matrix A = inputFunc();
        Matrix res = mySolution(A);
        outputFunc(res);
    }
    Matrix mySolution(Matrix A)
    {
        Matrix res(A.length);
        res.identityMatrix();
        while(k)
        {
            if(k & 1)
                res = res * A;
            A = A*A;
            k>>=1;
        }
        return res;
    }
    Matrix inputFunc()
    {
        cin>>this->n>>this->k;
        Matrix A(n);
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cin>>A.a[i][j];
            }
        }
        return A;
    }
    void outputFunc(Matrix A)
    {
        for(ll i=0;i<this->n;i++)
        {
            for(ll j=0;j<this->n;j++)
            {
                cout<<A.a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    // ifstream fin("in.txt");
    // ofstream fout("out.txt");
    // cin.rdbuf(fin.rdbuf());
    // cout.rdbuf(fout.rdbuf());
    MatrixMultiSolution s ;
    return 0;
}