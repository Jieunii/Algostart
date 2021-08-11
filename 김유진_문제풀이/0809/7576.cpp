#include <iostream>
#include <queue>
using namespace std;

int m, n, t;
int box[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<pair<int, int>, int>> ripe; //y,x,time

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) ripe.push({ {i, j}, 0});
		}
	}

	//bfs
	while (!ripe.empty()) {
		int y = ripe.front().first.first;
		int x = ripe.front().first.second;
		t = ripe.front().second;
		ripe.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (box[ny][nx] == -1 || box[ny][nx] == 1) continue;
			box[ny][nx] = 1;
			ripe.push({ {ny, nx}, t + 1});
		}
	}

	//안익은 토마토가 남아있다면
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << t;

	return 0;
}
