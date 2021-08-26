#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, b, k;
	int arr[100001] = {};

	cin >> n >> k >> b;

	for (int i = 1; i <= n; i++)
		arr[i] = 1;

	for (int i = 0; i < b; i++) {
		int num;
		cin >> num;
		arr[num] = 0;
	}
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += arr[i];
	}
	int min_ = 99999999;
	for (int i = 1; i <= n - k; i++) {
		int m = k - sum;
		if (min_ > m)
			min_ = m;
		sum += arr[i + k];
		sum -= arr[i];
	}
	if (min_ > k - sum) {
		min_ = k - sum;
	}
	cout << min_ << endl;


	return 0;
}