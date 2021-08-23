#include <iostream>

using namespace std;

int n;
int t[21], p[21];
int max_p = -21e8;

void init() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
}

void DFS(int lv, int sum) {
	
	if (lv > n + 1) return; // 바닥조건 2. 퇴사날 넘어간경우 
	if (lv == n + 1) { // 바닥조건 1. 퇴사날
		max_p = max(max_p, sum);

		return;
	}

	// lv일차에 그 일을 수주하거나
	DFS(lv + t[lv], sum + p[lv]);

	// 수주하지 않거나 
	DFS(lv + 1, sum);

}

int main() {

	init();

	DFS(1,0);

	cout << max_p;

	return 0;
}