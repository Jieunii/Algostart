// ATM

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1001];

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);

	//ДЉРћЧе
	for (int i = 0; i < n - 1; i++) {
		p[i + 1] = p[i] + p[i + 1];
	}


	int res = 0;
	for (int i = 0; i < n; i++) {
		res += p[i];
	}
	cout << res;
	return 0;
}