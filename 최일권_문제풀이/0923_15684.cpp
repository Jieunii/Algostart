#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int ladder[11][31] = {};
int ans = 9999999;

int test_ladder() {
	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[cur][j] == 1) cur += 1;
			else if (ladder[cur - 1][j] == 1) cur -= 1;
		}
		if (cur != i) return 0;
	}
	return 1;
}

void set_ladder(int start,int idx) {
	if (start > 3) {
		return;
	}
	if (test_ladder()) {
		if (ans > start)
			ans = start;
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (ladder[j][i] == 1) continue;
			if (ladder[j - 1][i] == 1) continue;
			if (ladder[j + 1][i] == 1) continue;
			ladder[j][i] = 1;
			set_ladder(start + 1, i);
			ladder[j][i] = 0;
		}
	}

}

int main() {
	cin >> N >> M >> H;
	if (M == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		ladder[b][a] = 1;
	}


	set_ladder(0, 1);


	if (ans > 3) cout << -1 << endl;
	else
		cout << ans << endl;
	

	return 0;
}
