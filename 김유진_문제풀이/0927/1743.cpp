//음식물 피하기 : 제일 큰 음식물 덩어리 크기 구하기

#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int map[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int res = 0;

void bfs(int i, int j) {
	int cnt = 1;
	queue<pair<int, int> > q;
	q.push({ i, j });
	visited[i][j] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny <= 0 || nx <= 0 || ny > n || nx > m) continue;
			if (visited[ny][nx] == 1) continue;
			if (map[ny][nx] == 0) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
			cnt++;
		}
	}
	if (res < cnt) res = cnt;
}

int main() {

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int y = 0, x = 0;
		cin >> y >> x;
		map[y][x] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1 && !visited[i][j]) bfs(i, j);
		}
	}

	cout << res << endl;
	return 0;
}