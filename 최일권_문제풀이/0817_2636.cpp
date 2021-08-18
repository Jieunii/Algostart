#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int map[101][101] = {};
int visited[101][101] = {};
int out_air[101][101] = {};
int N, M;
int cnt = 0;
int cheese = 0;
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

int isInside(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return 0;
	return 1;
}

void bfs(int y, int x) {
	queue<pair<int, int>> que;
	que.push({ y,x });
	visited[y][x] = 1;

	while (!que.empty()) {
		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int new_y = y + dir[i][0];
			int new_x = x + dir[i][1];

			if (isInside(new_y, new_x)) {

				if (map[new_y][new_x] == 1) {
					out_air[new_y][new_x]++;
				}
				else if (!visited[new_y][new_x]){
					visited[new_y][new_x] = 1;
					que.push({ new_y,new_x });
					}
			}
		}
	}
}

void solve() {
	while (1) {
		int flag = 0;
		int bz = 0;
		memset(visited, 0, sizeof(visited));
		memset(out_air, 0, sizeof(out_air));
		bfs(0, 0);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (out_air[i][j] >= 1) {
					map[i][j] = 0;
					flag = 1;
					bz++;
				}
			}
		}
		if (flag) cnt++;
		if (!flag) break;

		cheese = bz;

	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	//°Ñ¿¡¸¸ µ¹±â...

	solve();

	cout << cnt << endl;
	cout << cheese << endl;

	return 0;
}