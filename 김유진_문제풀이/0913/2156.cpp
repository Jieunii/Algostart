//포도주 시식
#include <iostream>
using namespace std;

int glass[10001];
int dp[10001];
int n;

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> glass[i];
	}

	dp[1] = glass[1];
	dp[2] = glass[1] + glass[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + glass[i], dp[i - 1]);
		dp[i] = max(dp[i], dp[i - 3] + glass[i - 1] + glass[i]);
	}

	cout << dp[n] << "\n";

	return 0;
}
