// 슬라이딩 윈도우

#include <iostream>
using namespace std;

int n, k, b;
int light[100001];
int res = 21e8;

int main() {

	cin >> n >> k >> b;
	for (int i = 1; i <= n; i++) {
		light[i] = 1;
	}
	for (int i = 0; i < b; i++) {
		int broken = 0;
		cin >> broken;
		light[broken] = 0;
	}

	//구간합
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += light[i];
	}

	//비교
	res = min(k - sum, res);
	for (int i = 1; i <= n - k; i++) {
		sum -= light[i];
		sum += light[i + k];
		res = min(k - sum, res);
	}

	cout << res;
	return 0;
}