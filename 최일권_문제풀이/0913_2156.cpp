#include <iostream>
#include <algorithm>
using namespace std;

int N;
int wine[10001] = {};
int DP[10001] = {};

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}

	DP[1] = wine[1];

	if (N >= 2) {
		DP[2] = wine[1] + wine[2];

		for (int i = 3; i <= N; i++) {
			DP[i] = max(max(DP[i - 2] + wine[i], DP[i - 1]), DP[i - 3] + wine[i - 1] + wine[i]);
		}
	}
	// ooxo, oxoo, xoox
	cout << DP[N] << endl;
	return 0;
}