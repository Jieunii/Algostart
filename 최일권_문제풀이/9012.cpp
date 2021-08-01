#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n;
	string temp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		stack<char> bracket;
		int flag = 0;
		cin >> temp;

		for (int j = 0; j < temp.length(); j++)
		{
			if (j == 0)
			{
				if (temp[j] == ')') {
					cout << "NO" << endl;
					flag = 1;
					break;
				}
				else
					bracket.push(temp[j]);
			}
			else if (j == temp.length() - 1) {
				if (temp[j] == '(')
				{
					cout << "NO" << endl;
					flag = 1;
					break;
				}
				else if (temp[j] == ')')
				{
					if (bracket.empty()) {
						cout << "NO" << endl;
						flag = 1;
						break;
					}
					else
						bracket.pop();
				}
			}
			else
			{
				if (temp[j] == '(')
					bracket.push(temp[j]);
				else if (temp[j] == ')') {
					if (bracket.empty()) {
						cout << "NO" << endl;
						flag = 1;
						break;
					}
					else
						bracket.pop();
				}
			}

		}
		if (!flag) {
			if (bracket.empty())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}