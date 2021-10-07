#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

struct Node {
	int y, x;
};

int cnt = 0;
int N;
int flag = 1;
int ans = 0;
int L, R;
int map[51][51] = {};
int visited[51][51] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int isInside(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)
		return 0;
	return 1;
}

void move_city(int y, int x,int k) {
	queue<Node> que;
	que.push({ y,x });
	int people = 0;
	cnt = 0;
	visited[y][x] = 1;
	while (!que.empty()) {
		y = que.front().y;
		x = que.front().x;
		people += map[y][x];

		cnt++;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (!isInside(ny, nx) || visited[ny][nx]) continue;
			
			int dif = abs(map[y][x] - map[ny][nx]);
			if (dif < L || dif > R) continue;
			visited[y][x] = k;
			visited[ny][nx] = k;
			que.push({ ny, nx });
		}
	}
	if (cnt > 1) {
		flag = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == k) {
					map[i][j] = people / cnt;
				}
			}
		}
	}
	
}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//4방향을 보면서 차이를 계산하고 L,R비교
	
	while (1) {
		memset(visited, 0, sizeof(visited));
		flag = 1;
		int k = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				move_city(i, j,++k);
			}
		}
		if (flag) break;
		ans++;
	}

	cout << ans << endl;

	
}