#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<fstream>
using namespace std;
struct TrieNode
{
	int cnt;
	int id;
	int child[26];
	TrieNode(int id)
	{
		this->id = id;
		cnt = 0;
		memset(child, 0, sizeof(child));
	}
};
class Trie
{
	vector<TrieNode> nodeList;

public:
	Trie()
	{
		TrieNode rootNode = TrieNode(0);
		nodeList.push_back(rootNode);
	}
	void insert(string name)
	{
		int headId = 0;
		for (int i = 0; i<name.size(); i++)
		{
			char curCh = name[i];
			int chId = curCh - 'a';
			if (nodeList[headId].child[chId] == 0)
			{
				int nodeId = nodeList.size();
				TrieNode newNode = TrieNode(nodeId);
				nodeList.push_back(newNode);
				nodeList[headId].child[chId] = nodeId;
				headId = nodeId;
			}
			else
			{
				headId = nodeList[headId].child[chId];
			}
		}
	}
	int search(string name)
	{
		int headId = 0;
		for (int i = 0; i<name.size(); i++)
		{
			int chId = name[i] - 'a';
			if (nodeList[headId].child[chId] == 0)
				return 0;
			else
			{
				headId = nodeList[headId].child[chId];
			}
		}
		nodeList[headId].cnt += 1;
		if (nodeList[headId].cnt == 1)
		{
			return 1;
		}
		else
			return 2;
	}
};
class Solution
{
public:
	void TrieSolution()
	{
		Trie trie = Trie();
		int n;
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			string name;
			cin >> name;
			trie.insert(name);
		}
		int m;
		cin >> m;
		for (int i = 0; i<m; i++)
		{
			string name;
			cin >> name;

			int result = trie.search(name);
			if (result == 0)
			{
				cout << "WRONG\n";
			}
			else if (result == 1)
			{
				cout << "OK\n";
			}
			else
			{
				cout << "REPEAT\n";
			}
		}
	}
};

int main()
{
	// ifstream fin("in.txt");
	// ofstream fout("out.txt");
	// cin.rdbuf(fin.rdbuf());
	//cout.rdbuf(fout.rdbuf());
	Solution s = Solution();
	s.TrieSolution();
    //不要用指针操作vector中的结构体, 是真的迷。比如下面的操作
	// vector<TrieNode> nodeList;
	// TrieNode p = TrieNode(0);
	// nodeList.push_back(p);
	// TrieNode *head = &nodeList[0];
	// head->child[8] = 555;
	// cout<<nodeList[0].child[8];
}