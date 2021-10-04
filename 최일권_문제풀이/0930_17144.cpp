#include <iostream>
#include <queue>
using namespace std;

int R, C, T;
int up_airy = 0;
int down_airy = 0;

int map[51][51] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int isInside(int y, int x) {
	if (y<0 || y>=R || x<0 || x>=C)
		return 0;
	return 1;
}

void spread_dust() {
	queue<pair<pair<int, int>,int>> que;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1 && map[i][j] != 0) {
				que.push({{ i,j },map[i][j]});
			}
		}
	}

	while (!que.empty()) {
		int y = que.front().first.first;
		int x = que.front().first.second;
		int dust = que.front().second;
		int cnt = 0;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (map[ny][nx] != -1 && isInside(ny, nx)) {
				map[ny][nx] += (dust / 5);
				cnt++;
			}
		}
		map[y][x] = map[y][x] - (cnt*(dust / 5));
	}
}

void move_dust() {
	//반시계 방향
	//1열
	if (map[up_airy - 1][0] != 0) {
		map[up_airy - 1][0] = 0;
	}
	for (int y = up_airy - 1; y > 0; y--) {
		if (map[y][0] == 0 && map[y - 1][0] != 0) {
			map[y][0] = map[y - 1][0];
			map[y - 1][0] = 0;
		}
	}

	for (int x = 0; x < C - 1; x++) {
		if (map[0][x] == 0 && map[0][x + 1] != 0) {
			map[0][x] = map[0][x + 1];
			map[0][x + 1] = 0;
		}
	}
	// 끝 방향
	for (int y = 0; y < up_airy; y++) {
		if (map[y][C - 1] == 0 && map[y + 1][C - 1] != 0) {
			map[y][C - 1] = map[y + 1][C - 1];
			map[y + 1][C - 1] = 0;
		}
	}
	for (int x = C - 1; x > 1; x--) {
		if (map[up_airy][x] == 0 && map[up_airy][x - 1] != 0) {
			map[up_airy][x] = map[up_airy][x - 1];
			map[up_airy][x - 1] = 0;
		}
	}
	//시계 방향

	//1열
	if (map[down_airy + 1][0] != 0) {
		map[down_airy + 1][0] = 0;
	}
	for (int y = down_airy + 1; y < R - 1; y++) {
		if (map[y][0] == 0 && map[y + 1][0] != 0) {
			map[y][0] = map[y + 1][0];
			map[y + 1][0] = 0;
		}
	}

	for (int x = 0; x < C - 1; x++) {
		if (map[R-1][x] == 0 && map[R-1][x + 1] != 0) {
			map[R - 1][x] = map[R - 1][x + 1];
			map[R - 1][x + 1] = 0;
		}
	}
	// 끝 방향
	for (int y = R - 1; y > down_airy; y--) {
		if (map[y][C - 1] == 0 && map[y - 1][C - 1] != 0) {
			map[y][C - 1] = map[y - 1][C - 1];
			map[y - 1][C - 1] = 0;
		}
	}

	for (int x = C - 1; x > 1; x--) {
		if (map[down_airy][x] == 0 && map[down_airy][x - 1] != 0) {
			map[down_airy][x] = map[down_airy][x - 1];
			map[down_airy][x - 1] = 0;
		}
	}
	
}

int main() {
	//1단계 => 먼지의 확산 
	//2단계 => 공기청정기 작동
	
	int flag = 0;
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (!flag) {
					up_airy = i;
					flag = 1;
				}
				else {
					down_airy = i;
				}
			}
		}
	}

	while (T--) {
		//먼지 확산
		spread_dust();
		move_dust();
	}

	int ans = 0;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] != -1 && map[y][x] != 0) {
				ans += map[y][x];
			}
		}
	}

	cout << ans << endl;

	return 0;
}