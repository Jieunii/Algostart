#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int wine[10001] = { 0 };
	int dp[10001] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> wine[i];
	}
	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	for (int i = 2; i < N; i++) {
    // dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i] + wine[i - 1]의 최대값
		int temp = max(dp[i - 1], dp[i - 2] + wine[i]);
		dp[i] = max(temp, dp[i - 3] + wine[i] + wine[i - 1]);
	}
	cout << dp[N - 1];

	return 0;
}