#include <iostream>
#include <queue>

#define MAX 100

using namespace std;

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int cnt[MAX][MAX];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void findMiro(int x, int y) {
	visited[x][y] = 1;
	cnt[x][y]++;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) { // 미로 크기 범위
				if (visited[nx][ny] == 0 && map[nx][ny] == 1) { // 방문하지 않았고 갈 수 있는 길일 때
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					cnt[nx][ny] = cnt[qx][qy] + 1;
				}
			}
		}
	}
}

int main(void) {
	cin >> N >> M;

	// 붙어서 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	// 미로 탐색
	findMiro(0, 0);

	cout << cnt[N - 1][M - 1];

	return 0;
}