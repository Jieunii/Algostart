#include <iostream>

using namespace std;

int N;
int arr[10001];
int dp[10001];

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	/// dp ///
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	// 뒤에서부터 생각한다. 현재잔은 마실껀데,
	// 이전잔을 안마신 경우 : dp[n] = dp[n-2](arr[n-2]까지 저장된 합) + arr[n] <- arr[n-1]은 안마셨음.
 	// 이전잔을 이미 마신 경우 : dp[n] = dp[n-3] + arr[n-1] + arr[n] <- arr[n-2] 는 마시면 3잔 연속이므로 안마신걸로 계산

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]); // 두잔 연속으로 안마신 경우 대비
	}

	cout << dp[N];

	return 0;
}