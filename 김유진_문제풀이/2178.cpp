#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<pair<int, int>, int>> q;

void bfs() {
	visited[1][1] = 1;
	q.push({ {1,1}, 1});

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (y == n && x == m) {
			cout << cnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= 0 || nx <= 0 || ny > n || nx > m) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx] == true) continue;

			visited[ny][nx] = true;
			q.push({ {ny, nx},cnt + 1 });
		}
	}

}


int main() {

	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j + 1] = str[j] - '0';
		}
	}

	bfs();

	return 0;
}
