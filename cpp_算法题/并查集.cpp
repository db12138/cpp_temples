#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
class UFsets
{
public:
	UFsets(int N)
	{
		parents = new int[N+1];
		for (int i = 0; i < N+1; i++)
		{
			parents[i] = -1;
		}
	}
	int find(int p) // 不做路径压缩会TLE
	{
		int root = p;
		while(true)
		{
			if (parents[root] < 0)
				break;
			else
				root = parents[root];
		} // 搜索根
		while (p != root)
		{
			int next_p = parents[p];
			parents[p] = root;
			p = next_p;
		}
		return root;

	}
	void weightedUnion(int p1, int p2)
	{
		int root1, root2;
		root1 = find(p1);
		root2 = find(p2);
		if (root1 != root2)
		{
			int temp = parents[root1] + parents[root2];
			if (parents[root1] > parents[root2])
			{
				parents[root2] = root1;
				parents[root1] = temp;
			}
			else
			{
				parents[root1] = root2;
				parents[root2] = temp;
			}
		}
	}
private:
	int *parents;
};
class Solution
{
public:
	Solution()
	{
		int N, M;
		cin >> N>>M;
		UFsets ufsets = UFsets(N);
		int z, x, y;
		for (int i = 0; i < M; i++)
		{
			cin >> z >> x >> y;
			if (z == 1)
			{
				ufsets.weightedUnion(x, y);
			}
			else if (z == 2)
			{
				(ufsets.find(x) == ufsets.find(y)) ? cout << "Y\n" : cout << "N\n";
			}
		}
	}
};

int main()
{
	//ifstream fin("in.txt");
	//ofstream fout("out.txt");
	//cin.rdbuf(fin.rdbuf());
	//cout.rdbuf(fout.rdbuf());
	Solution s = Solution();
}