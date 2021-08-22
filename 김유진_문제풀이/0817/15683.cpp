#include <iostream>
#include <vector>
using namespace std;

struct info {
	int y;
	int x;
	int type;
};

int n, m;
int res = 21e8;
int map[10][10];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 }; //하,상,좌,우
vector<info> cctv;
vector<pair<int, int>> color[8];
int dir3[4][2] = { {1,3},{0,3},{2,0},{2,1} };
int dir4[4][3] = { {1,2,3},{0,1,3},{0,1,2},{0,2,3} };

void check(int cnt, int i) {
	int y = cctv[cnt].y;
	int x = cctv[cnt].x;
	int ny = y;
	int nx = x;
	while (1) {
		ny += dy[i];
		nx += dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
		if (map[ny][nx] == 6) break;
		if (map[ny][nx] == 0) {
			color[cnt].push_back({ ny, nx });
			map[ny][nx] = 7;
		}
	}
}

void erase_check(int cnt, int i) {
	for (int i = 0; i < color[cnt].size(); i++) {
		map[color[cnt][i].first][color[cnt][i].second] = 0;
	}
}

void go(int cnt) {
	if (cnt == cctv.size()) {
		//사각지대 계산

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) cnt++;
			}
		}

		res = min(res, cnt);
		return;
	}

	int y = cctv[cnt].y;
	int x = cctv[cnt].x;

	if (cctv[cnt].type == 1) {
		for (int i = 0; i < 4; i++) {
			check(cnt, i);
			go(cnt + 1);
			erase_check(cnt, i);
			color[cnt].clear();
		}
	}
	else if (cctv[cnt].type == 2) {
		for (int i = 0; i < 4; i+=2) {
			check(cnt, i);
			check(cnt, i + 1);
			go(cnt + 1);
			erase_check(cnt, i);
			erase_check(cnt, i+1);
			color[cnt].clear();
		}
	}
	else if (cctv[cnt].type == 3) {
		for (int i = 0; i < 4; i ++) {
			for (int j = 0; j < 2; j++) {
				check(cnt, dir3[i][j]);
			}
			go(cnt + 1);
			for (int j = 0; j < 2; j++) {
				erase_check(cnt, dir3[i][j]);
			}
			color[cnt].clear();
		}
	}
	else if (cctv[cnt].type == 4) {
		for (int i = 0; i < 4; i ++) {
			for (int j = 0; j < 3; j++) {
				check(cnt, dir4[i][j]);
			}
			go(cnt + 1);
			for (int j = 0; j < 3; j++) {
				erase_check(cnt, dir4[i][j]);
			}
			color[cnt].clear();
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			check(cnt, i);
		}
		go(cnt + 1);
		for (int i = 0; i < 4; i++) {
			erase_check(cnt, i);
		}
		color[cnt].clear();
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
				cctv.push_back({ i, j, map[i][j] });
			}
		}
	}

	go(0);

	cout << res;

	return 0;
}