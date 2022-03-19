#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

struct unit
{
	int val;
	char opera;
	bool isVal;
	unit(int v)
	{
		this->val = v;
		isVal = true;
	}
	unit(char op)
	{
		opera = op;
		this->isVal = false;
	}
	friend ostream &operator<<(ostream &output,const unit &u)
	{
		output << u.isVal << " " << u.val << " " << u.opera << endl;
		return output;
	}
};
class Solution
{
public:
	vector<unit> inputFunc()
	{
		string str;
		char ops[4] = { '+', '-', '*', '/' };
		vector<char> operators(ops,ops+4);
		cin >> str;
		//cout << str << endl;
		vector<unit> inputs;
		string curNum = "";
		for (int i = 0; i < str.size(); i++)
		{
			if (find(operators.begin(), operators.end(), str[i]) == operators.end())
			{
				//not found
				if (str[i] != '.' && str[i] != '@')
				{
					curNum += str[i];
				}
				else
				{
					if (curNum != "")
					{
						int num = atoi(curNum.c_str());
						inputs.push_back(unit(num));
						curNum = "";
					}
					
				}
			}
			else
			{
				inputs.push_back(unit(str[i]));
			}
		}
		//for (auto t : inputs)
		//{
		//	cout << t.isVal << " " << t.val<<" " << t.opera << endl;
		//	cout << "************" << endl;
		//}
		return inputs;
	}
	void postFixExpression()
	{	
		vector<unit> inputs = inputFunc();
		vector<unit> resStack;
		for (auto u : inputs)
		{
			if (u.isVal)
				resStack.push_back(u);
			else
			{
				unit op2 = resStack.back();
				resStack.pop_back();
				unit op1 = resStack.back();
				resStack.pop_back();
				unit temp(0);
				if (u.opera == '+')
					temp = unit(op1.val + op2.val);
				else if (u.opera == '-')
					temp = unit(op1.val - op2.val);
				else if (u.opera == '*')
					temp = unit(op1.val * op2.val);
				else if (u.opera == '/')
					temp = unit(op1.val / op2.val);
				//else
					//cout << "error" << u.opera << endl;
				resStack.push_back(temp);
			}

		}
		cout << resStack.back().val << endl;
	};
};

int main()
{
	/*ifstream fin("in.txt");
	ofstream fout("out.txt");
	cin.rdbuf(fin.rdbuf());*/
	//cout.rdbuf(fout.rdbuf());
	Solution s = Solution();
	s.postFixExpression();
}