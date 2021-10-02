//미세먼지 안녕

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int r, c, t;
vector<pair<int, int> > air_cond;
int map[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void spread() {
	int tmp[51][51] = { 0, };
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (map[y][x] > 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
					if (map[ny][nx] == -1) continue;
					cnt++;
					tmp[ny][nx] += map[y][x] / 5;
				}
				tmp[y][x] += (map[y][x] - (map[y][x] / 5) * cnt);
			}
		}
	}
	memcpy(map, tmp, sizeof(map));
	map[air_cond[0].first][air_cond[0].second] = -1;
	map[air_cond[1].first][air_cond[1].second] = -1;
}

void air_on_up() {
	int y = air_cond[0].first;
	int x = air_cond[0].second;

	for (int i = y-1; i >= 0; i--) {
		if (map[i + 1][0] != -1) map[i + 1][0] = map[i][0];
	}
	for (int i = 1; i <= c-1; i++) {
		map[0][i - 1] = map[0][i];
	}
	for (int i = 1; i <= y; i++) {
		map[i - 1][c - 1] = map[i][c - 1];
	}
	for (int i = c - 2; i >= 1; i--) {
		map[y][i+1] = map[y][i];
	}
	map[y][x + 1] = 0;
}

void air_on_down() {
	int y = air_cond[1].first;
	int x = air_cond[1].second;

	for (int i = y+2; i <= r-1; i++) {
		map[i-1][0] = map[i][0];
	}
	for (int i = 1; i <= c - 1; i++) {
		map[r-1][i - 1] = map[r-1][i];
	}
	for (int i = r-2; i >= y; i--) {
		map[i + 1][c - 1] = map[i][c - 1];
	}
	for (int i = c - 2; i >= 1; i--) {
		map[y][i + 1] = map[y][i];
	}
	map[y][x + 1] = 0;
}

int main() {

	//input
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) air_cond.push_back({ i, j });
		}
	}
	//t초 동안 미세먼지 확산
	for (int time = 1; time <= t; time++) {
		//1. 미세먼지 확산
		spread();

		//2. 공기청정기 작동
		air_on_up();
		air_on_down();
	}

	//남아있는 미세먼지 계산
	int res = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) res += map[i][j];
		}
	}

	cout << res << "\n";
	return 0;
}