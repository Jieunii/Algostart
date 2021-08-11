#include <iostream>
#include <string>
using namespace std;

int r, c;
int res = -21e8;
char map[21][21];
int apb[30];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

void dfs(int y, int x, int cnt) {

	if (res < cnt) res = cnt;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny <= 0 || nx <= 0 || ny > r || nx > c) continue;
		if (apb[map[ny][nx] - 65]) continue;

		apb[map[ny][nx]-65] = 1;
 		dfs(ny, nx, cnt+1);
		apb[map[ny][nx]-65] = 0;
	}
	return;
}

int main() {

	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j+1] = str[j];
		}
	}

	apb[map[1][1] - 65] = 1;
	dfs(1, 1, 1);

	cout << res;
	return 0;
}
