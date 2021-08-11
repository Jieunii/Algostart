#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[5000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = x;
	}

	sort(arr, arr + n);

	cout << arr[k - 1];

	return 0;
}
