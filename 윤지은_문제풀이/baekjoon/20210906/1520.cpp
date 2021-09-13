#include <iostream>

using namespace std;

int M, N, result;
int map[501][501];
int dp[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
	if (y == M - 1 && x == N - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (map[ny][nx] < map[y][x]) dp[y][x] += dfs(ny, nx);
	}
	return dp[y][x];
}

int main() {
	cin >> M >> N;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			dp[y][x] = -1;
		}
	}
	cout << dfs(0, 0);
	return 0;
}