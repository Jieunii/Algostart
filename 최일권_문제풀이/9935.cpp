#include <string>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
	stack<char> ans;
	stack<char> temp;
	char result[1000001] = {};
	string target;
	string bomb;

	cin >> target >> bomb;
	//acddd
	//abcd
	for (int i = 0; i < target.length(); i++)
	{
		ans.push(target[i]);
		int bomb_idx = bomb.length();

		if (ans.top() == bomb[--bomb_idx])
		{
			bool chk = true;

			for (int j = bomb_idx; j >= 0;j--)
			{
				//cout << ans.top() << " " << bomb[j] << endl;
				if (j >= 0 && ans.empty())
				{
					chk = false;
					break;
				}
				if (ans.top() == bomb[j])
				{
					temp.push(ans.top());
					ans.pop();
					chk = true;
				}
				else {
					chk = false;
					break;
				} 
			}

			if (!chk)
			{
				if (temp.size() != 0)//cba
				{
					int idx = 0;
					while (!temp.empty())
					{
						result[idx++] = temp.top();
						temp.pop();
					}
					for (int j = 0; j < idx; j++) {
						ans.push(result[j]);
						result[j] = 0;
					}
				}
			}
			else {
				while (!temp.empty())
				{
					temp.pop();
				}
			}

		}
	}

	int index = 0;
	if (ans.size() != 0) {
		while (!ans.empty())
		{
			result[index++] = ans.top();
			ans.pop();
		}
		for (int i = index - 1; i >= 0; i--)
			cout << result[i];
		cout << endl;
	}
	else
	{
		cout << "FRULA" << endl;
	}

}