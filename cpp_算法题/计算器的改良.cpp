#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include <typeinfo>
#include <sstream>
#include <regex>

using namespace std;

class Solution
{
public:
	string identifyFunc(string s,vector<int > & num,vector<int > & var)
	{
		string num_pattern = "\\-*\\+*[0-9\\.]+(?![a-zA-Z0-9])";
		string var_pattern = "\\-*\\+*[0-9\\.]*[a-zA-Z]";
		regex num_p(num_pattern);
		regex var_p(var_pattern);
		smatch m;
		string s1 = s;
		while (regex_search(s, m, num_p))
		{
			for (auto x : m)
			{
				int cur = atoi(x.str().c_str());
				//cout << "num:" << cur << " ";
				num.push_back(cur);
			}
			s = m.suffix().str();
		}
		string var_name = "";
		while (regex_search(s1, m, var_p)) 
		{
			for (auto x : m)
			{
				int cur;
				if (x.str().length() > 2)
					cur = atoi(x.str().c_str());
				else if (x.str()[0] == '-')
					cur = -1;
				else if (x.str()[0] == '+')
					cur = 1;
				else if (x.str().length() == 1)
					cur = 1;
				else
					cur = atoi(x.str().c_str());
				var_name = x.str()[x.str().length() - 1];
				//cout <<"var:"<< cur << " ";
				var.push_back(cur);
			}	
			s1 = m.suffix().str();
		}
		return var_name;
	}
	Solution(string input)
	{
		string split = "=";
		int split_postion = input.find(split, 0);
		//cout << split_postion << endl;
		string left = input.substr(0, split_postion);
		string right = input.substr(split_postion + 1);
		//cout << left << " = " << right << endl;
		vector<int >left_num;
		vector<int >left_var;
		vector<int >right_num;
		vector<int >right_var;
		string var_name = "";
		string var_n1 = identifyFunc(left, left_num, left_var);
		string var_n2 = identifyFunc(right, right_num, right_var);
		int var = 0;
		for (auto v : left_var)
			var += v;
		for (auto v : right_var)
			var -= v;
		int num = 0;
		for (auto v : left_num)
			num -= v;
		for (auto v : right_num)
			num += v;
		//cout << num << " "<<var << endl;
		if (var_n1.length() != 0)
			var_name = var_n1;
		else
			var_name = var_n2;
		double res = double(num) / double(var);
		cout << var_name << "=";
		printf("%.3f\n", res == 0 ? abs(res) : res);
	}
};


int main ()
{
  //std::string s ("44-3-48x=9889x+8");
  	//ifstream fin("P1022_1.in");
  	//cin.rdbuf(fin.rdbuf());
	string input;
	cin >> input;
	Solution x(input);
	return 0;
}
//int main()
//{
//	//ifstream fin("in.txt");
//	//ofstream fout("out.txt");
//	//cin.rdbuf(fin.rdbuf());
//	//cout.rdbuf(fout.rdbuf());
//	Solution s = Solution();
//}