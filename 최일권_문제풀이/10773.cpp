#include <iostream>
#include <stack>
using namespace std;

int main() {

	stack<int> st;
	int sum = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num != 0)
			st.push(num);
		else
		{
			if (st.empty()) continue;
			st.pop();
		}
	}

	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}

	cout << sum << endl;

	return 0;
}