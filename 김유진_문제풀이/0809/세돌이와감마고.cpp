#include <iostream>
#include <queue>
using namespace std;

char map[20][20];
queue<pair<int, int>> sedol; //@
queue<pair<int, int>> gam; //O
int m, k;
int y, x;
int res;

int dx[8] = {-1,1,0,0,-1,1,-1,1};
int dy[8] = {0,0,-1,1,1,-1,-1,1};

bool check(int yy, int xx, char now) { //return true하면 끝
	for (int i = 0; i < 8; i += 2) {
		int cnt = 1;

		int ny = yy;
		int nx = xx;
		//왼
		while (1) {
			ny = ny + dy[i];
			nx = nx + dx[i];
			if (ny <= 0 || nx <= 0 || ny > 19 || nx > 19) break;
			if (map[ny][nx] != now) {
				break;
			}
			else {
				cnt++;
			}
		}

		ny = yy;
		nx = xx;

		//오
		while (1) {
			ny = ny + dy[i+1];
			nx = nx + dx[i+1];
			if (ny <= 0 || nx <= 0 || ny > 19 || nx > 19) break;
			if (map[ny][nx] != now) {
				break;
			}
			else {
				cnt++;
			}
		}

		if (cnt == k) {
			return true;
		}
	}

	return false;
}

void start() {
	for (int t = 1; t <= 2 * m; t++) {
		if (t % 2 == 1) {//세돌이 차례
			int yy = sedol.front().first;
			int xx = sedol.front().second;
			map[yy][xx] = '@';
			sedol.pop();
			if (check(yy, xx, map[yy][xx])) {
				cout << t << "\n";
				cout << "세돌이";
				return;
			}
		}
		else {//감마 차례
			int yy = gam.front().first;
			int xx = gam.front().second;
			map[yy][xx] = 'O';
			gam.pop();
			if (check(yy, xx, map[yy][xx])) {
				cout << t << "\n";
				cout << "감마고";
				return;
			}
		}
	}
	cout << "0";
}

int main() {

	cin >> m >> k;
	for (int i = 0; i < m; i++){
		cin >> y >> x;
		sedol.push({ y, x });
	}
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		gam.push({ y, x });
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = '_';
		}
	}

	start();

	return 0;
}