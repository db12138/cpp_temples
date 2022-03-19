#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<fstream>
#include <typeinfo>
#include <sstream>
#include <regex>
using namespace std;
struct Node
{
	int val;
	int position;
	Node(int v,int p)
	{
		val = v;
		position = p;
	}
};
class Solution
{
public:
	Solution()
	{
		int n,k;
		cin >> n >> k;
		int * A = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		deque<Node> min_que;
		vector<int> min_res;
		deque<Node> max_que;
		vector<int> max_res;
		for (int i = 0; i < n; i++)
		{
			if (i >= k)
			{
				Node head = min_que.front();
				if (head.position < i - k + 1)
				{
					min_que.pop_front();
				}
				Node head1 = max_que.front();
				if (head1.position < i - k + 1)
				{
					max_que.pop_front();
				}
			}
			while(!min_que.empty() && A[i] <= min_que.back().val)
			{
                min_que.pop_back();
			}
			min_que.push_back(Node(A[i], i));
	
			while(!max_que.empty() && A[i] >= max_que.back().val)
			{
                max_que.pop_back();
			}
			max_que.push_back(Node(A[i], i));
			if (i >= k-1)
			{
				min_res.push_back(min_que.front().val);
				max_res.push_back(max_que.front().val);
			}
			
		}
		for (auto v : min_res)
			cout << v << " ";
		cout << endl;
		for (auto v : max_res)
			cout << v << " ";
		cout << endl;
	}
};


int main ()
{
    //ifstream fin("P1886_3.in");
	//cin.rdbuf(fin.rdbuf());
	Solution x = Solution();
	return 0;
}
