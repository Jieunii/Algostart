//감소하는 수 : n번째 감소하는 숫자 구하기

#include <iostream>
#include <string>
using namespace std;

int path[11];
int n;
int cnt = -1;
string res = "";
int flag = 0;

void dfs(int depth, int now) {
	if (depth == now) {
		cnt++;
		if (cnt == n) {
			for (int i = 0; i < now; i++) {
				res += to_string(path[i]);
			}
			cout << res << endl;
			res = "";
			flag = 1;
		}
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (now == 0) {
			path[now] = i;
			dfs(depth, now + 1);
		}
		if (path[now-1] > i) {
			path[now] = i;
			dfs(depth, now + 1);
		}
	}
}

int main() {

	cin >> n;
	for (int i = 1; i <= 10; i++) {
		dfs(i, 0);
	}
	if (flag == 0) cout << -1 << endl;
	return 0;
}