//안전영역 : 장마철에 물이 잠기지 않는 안전한 영역

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n, cnt;
int map[101][101];
int visited[101][101];
int low = 21e8;
int high = -21e8;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int rain, int i, int j) {
	queue<pair<int, int> > q;

	cnt++;
	q.push({ i, j });
	visited[i][j] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] == 1) continue;
			if (map[ny][nx] <= rain) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] < low) low = map[i][j];
			if (map[i][j] > high) high = map[i][j];
		}
	}

	int res = 0;
	for (int i = low - 1; i <= high; i++) {
		//visited 초기화
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (map[y][x] > i && !visited[y][x]) bfs(i, y, x);
			}
		}

		if (res < cnt) res = cnt;
	}

	cout << res << endl;
	return 0;
}