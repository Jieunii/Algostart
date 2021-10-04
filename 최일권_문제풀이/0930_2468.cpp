#include <iostream>
#include <queue>
using namespace std;

int N;
int map[101][101] = {};
int visited[101][101] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ans = -999999;
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
int isInside(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N) {
		return 0;
	}
	return 1;
}

void find_island(int y, int x) {

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (isInside(ny, nx) && !visited[ny][nx]) {
			find_island(ny, nx);
		}

	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for(int n=0;n<=100;n++){
		int height = n;
		int cnt = 0;

		init();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] <= height) {
					visited[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					find_island(i, j);
					cnt++;
				}
			}
		}

			if (ans < cnt) {
				ans = cnt;
			}

		}

	cout << ans << endl;

	return 0;
}