// 테트로미노
// 총 만들어지는 도형수 :19 * 500 * 500

#include <iostream>
using namespace std;

int n, m, res;
int map[501][501];
int visited[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void check(int sum) {
	if (sum > res) res = sum;
}

void dfs(int y, int x, int level, int sum) {
	if (level == 3) {
		check(sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || nx >= m || ny >= n) continue;
		if (visited[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, level+1, sum+map[ny][nx]);
		visited[ny][nx] = 0;
	}
}

void find(int y, int x, int sum) {
	int tmp = 0;
	tmp = sum + map[y - 1][x] + map[y][x - 1] + map[y][x + 1];
	check(tmp);

	tmp = sum + map[y+1][x] + map[y][x - 1] + map[y][x + 1];
	check(tmp);

	tmp = sum + map[y][x+1] + map[y-1][x] + map[y+1][x];
	check(tmp);

	tmp = sum + map[y][x - 1] + map[y - 1][x] + map[y + 1][x];
	check(tmp);
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	//凸제외하고 모든 모형
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs(i, j, 0, map[i][j]);
			visited[i][j] = 0;
		}
	}

	//凸 모형
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			find(i, j, map[i][j]);
		}
	}
	cout << res;

	return 0;
}