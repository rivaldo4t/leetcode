#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


class Solution
{
public:

	void recur(vector<string>& str, string& temp, string s, int index, int count)
	{
		if (count >= 4)
		{
			if (index == s.size())
			{
				temp.pop_back();
				str.push_back(temp);
			}
			else
				temp.pop_back();
			return;
		}
		for (int i = index; i < index + 3 && i < s.size(); i++)
		{
			string a = "";
			int j = index;
			while (j <= i)
				a += s.at(j++);
			if (a.size() > 1 && a[0] == '0')
				return;
			int num = stoi(a);

			if (num < 0 || num > 255)
				return;

			temp += a;
			temp += ".";

			recur(str, temp, s, i + 1, count + 1);
			if (temp.back() == '.')
				temp.pop_back();
			while (temp.size() && temp.back() != '.')
				temp.pop_back();
		}
		return;
	}

	vector<string> restoreIpAddresses(string s)
	{
		vector<string> str;
		string temp = "";
		recur(str, temp, s, 0, 0);
		return str;
	}
};

int main()
{
	Solution s;
	//vector<string> str = s.restoreIpAddresses("25525511135");
	//vector<string> str = s.restoreIpAddresses("12345");
	vector<string> str = s.restoreIpAddresses("010010");
	for (auto i : str)
		cout << i << endl;
	return 0;
}