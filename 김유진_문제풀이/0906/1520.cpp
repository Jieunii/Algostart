#include <iostream>
using namespace std;
int m, n;
int map[501][501];
int dp[501][501];

int main() {

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}


	cout << dp[0][0] << endl;
	return 0;
}