#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int map[101][101];
int visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

int bfs(int y, int x) {
	int cnt = 1; // 음식물 크기
	visited[y][x] = 1;
	q.push({ y, x });
	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + nowX;
			int ny = dy[i] + nowY;
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || map[ny][nx] == 0 || visited[ny][nx] == 1) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int maxi = -21e8;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		map[y - 1][x - 1] = 1;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 1 && visited[y][x] == 0) {
				int size = bfs(y, x);
				if (maxi < size) {
					maxi = size;
				}
			}
		}
	}
	cout << maxi;
	return 0;
}