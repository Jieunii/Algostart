#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int arr[1001] = {};
	int n, k;

	cin >> n >> k;
	int sz = 0;
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
		sz++;
	}
	int ans = 0;
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i] != 0) {
			for (int j = i; j <= n; j += i) {
				if (arr[j] == 0) continue;
				cnt++;
				if (cnt == k) {
					ans = arr[j];
					break;
				}
				arr[j] = 0;
			}
		}
	}
	cout << ans << endl;

	return 0;
}