#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	string ans;
	int cnt = 0;
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ans;
		for (int j = 0; j < ans.length(); j++)
		{
			if (ans[j] == 'O')
				cnt++;
			else if (ans[j] == 'X')
				cnt = 0;
			sum += cnt;
		}
		cout << sum << endl;
		sum = 0;
		cnt = 0;
	}

	return 0;
}