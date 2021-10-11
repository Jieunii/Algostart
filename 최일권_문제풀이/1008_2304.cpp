#include <iostream>
#include <algorithm>
using namespace std;

int N; //1이상 1000이하
int L, H; //L은 x H는 y 1 이상 1000이하
int height[1002] = {};
int main() {
	int max_x = -9999999;
	int max_y = -999999;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> L >> H;
		height[L] = H;
		
		if (max_y < H) {
			max_x = L;
			max_y = H;
		}
	}

	int ans = 0;

	//왼쪽
	int left = 0;
	for (int i = 0; i < max_x; i++) {
		left = max(left, height[i]);
		ans += left;
	}
	//오른쪽
	int right = 0;
	for (int i = 1000; i >= max_x; i--) {
		right = max(right, height[i]);
		ans += right;
	}

	cout << ans << endl;

	return 0;
}