#include<iostream>
using namespace std;

int main()
{
	int n, cnt, sum;
	char str[80];


	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		cnt = 0;
		sum = 0;

		for (int j = 0; j < str[j] != '\0'; j++) {
			if (str[j] == 'O') {
				cnt++;
				sum += cnt;
			}
			else if (str[j] == 'X') {
				cnt = 0;
			}
		}
		cout << sum << endl;
	}


	return 0;
}