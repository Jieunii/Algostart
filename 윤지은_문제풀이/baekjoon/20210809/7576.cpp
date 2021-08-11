#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int M, N;
int map[MAX][MAX];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

void tomato() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == 0) {
				map[ny][nx] = map[y][x] + 1;
				q.push(make_pair(ny, nx));

			}
		}
	}
}
int main() {
	cin >> M >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) q.push(make_pair(y, x));
		}
	}
	tomato();

	int max = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 0) {
				cout << "-1" << '\n';
				return 0;
			}
			if (max < map[y][x]) max = map[y][x];
		}
	}
	cout << max - 1 << '\n';
	return 0;
}