#include <iostream>
#include <algorithm>
using namespace std;

int N, M;//M이 세로, N이 가로
int map[501][501] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int DP[501][501] = {};
int ans = 0;
int isInside(int y, int x) {
	if (y < 0 || y >= M || x < 0 || x >= N)
		return 0;
	return 1;
}

int dfs(int y, int x) {


	if (y == M - 1 && x == N - 1) {
		return 1;
	}
	if (DP[y][x] != -1) return DP[y][x];
	DP[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (isInside(ny, nx) && map[y][x] > map[ny][nx]){
			DP[y][x] = DP[y][x] + dfs(ny, nx);
		}
	}
	return DP[y][x];
}

int main() {

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			DP[i][j] = -1;
		}
	}

	ans = dfs(0, 0);

	cout << ans << endl;

	return 0;
}