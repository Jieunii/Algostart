#include <iostream>
#include <queue>
using namespace std;

struct info {
	int y;
	int x;
	int dir;
};

int n, m;
int r, c, d;
int cnt;
int flag;
int dx[4] = {0,1,0,-1}; // 북동남서
int dy[4] = {-1,0,1,0};
int map[51][51];
queue<info> robot;

void current_clean() {
	int y = robot.front().y;
	int x = robot.front().x;

	if (map[y][x] != 2) {
		map[y][x] = 2;
		cnt++;
	}
}

bool near_find() {
	int y = robot.front().y;
	int x = robot.front().x;
	int d = robot.front().dir;

	for (int i = 1; i <= 4; i++) {
		int nd = d - i;
		if (nd < 0) nd = 4 + nd;

		int nx = x + dx[nd];
		int ny = y + dy[nd];

		if (map[ny][nx] == 1 || map[ny][nx] == 2) continue;
		if (map[ny][nx] == 0) {
			robot.pop();
			robot.push({ ny, nx, nd });
			return true;
		}
	}
	return false;
}

bool back() {
	int y = robot.front().y;
	int x = robot.front().x;
	int d = robot.front().dir;
	int nd = 0;
	if (d == 0) nd = 2;
	else if (d == 1) nd = 3;
	else if (d == 2) nd = 0;
	else nd = 1;

	int ny = y + dy[nd];
	int nx = x + dx[nd];
	if (map[ny][nx] != 1) {
		robot.pop();
		robot.push({ ny, nx, d });
		return true;
	}

	return false;
}

int main() {

	cin >> n >> m;
	cin >> r >> c >> d;
	robot.push({ r,c,d });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		current_clean();
		
		if (!near_find()) { //빈곳 없음
			if (!back()) { //뒤에 벽이면
				cout << cnt;
				return 0;
			}
		}
	}

	return 0;
}