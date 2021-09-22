//두동전

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m;
char map[21][21];
int res;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct info {
	int y1;
	int x1;
	int y2;
	int x2;
	int cnt;
};
queue<info> q;

void go(int fy, int fx, int sy, int sx, int c, int d) {
	int nfy = fy + dy[d];
	int nfx = fx + dx[d];
	int exit = 0;

	if (nfy < 0 || nfx < 0 || nfy >= n || nfx >= m) {
		fy = nfy;
		fx = nfx;
		exit++;
	}
	else if (map[nfy][nfx] == '.') {
		fy = nfy;
		fx = nfx;
	}

	int nsy = sy + dy[d];
	int nsx = sx + dx[d];

	if (nsy < 0 || nsx < 0 || nsy >= n || nsx >= m) {
		exit++;
		sy = nsy;
		sx = nsx;
	}
	else if (map[nsy][nsx] == '.') {
		if(!(fy == nsy && fx == nsx)) {
			sy = nsy;
			sx = nsx;
		}
	}

	if (exit == 1 || exit == 0) q.push({ fy, fx, sy, sx, c + 1 });
	
}

int bfs() {
	while (!q.empty()) {
		int y1 = q.front().y1;
		int x1 = q.front().x1;
		int y2 = q.front().y2;
		int x2 = q.front().x2;
		int c = q.front().cnt;
		if (c > 10) return -1;
		q.pop();

		if (y1 < 0 || x1 < 0 || y1 >= n || x1 >= m) return c;
		if (y2 < 0 || x2 < 0 || y2 >= n || x2 >= m) return c;

		for (int i = 0; i < 4; i++) {
			if (i == 0) { //아래, y가 큰 코인부터
				if (y1 < y2) go(y2, x2, y1, x1, c, i);
				else go(y1, x1, y2, x2, c, i);
			}
			else if (i == 1) { //위, y가 작은 코인부터
				if (y1 > y2) go(y2, x2, y1, x1, c, i);
				else go(y1, x1, y2, x2, c, i);
			}
			else if (i == 2) { //오른쪽, x가 큰 코인부터
				if (x1 < x2) go(y2, x2, y1, x1, c, i);
				else go(y1, x1, y2, x2, c, i);
			}
			else { //왼쪽, x가 작은 코인부터
				if (x1 > x2) go(y2, x2, y1, x1, c, i);
				else go(y1, x1, y2, x2, c, i);
			}
		}
	}
	return -1;
}

int main() {

	cin >> n >> m;
	string str = "";
	int coin = 1;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
			if (str[j] == 'o' && coin == 1) {
				map[i][j] = '.';
				y1 = i;
				x1 = j;
				coin++;
			}
			else if (str[j] == 'o' && coin == 2) {
				map[i][j] = '.';
				y2 = i;
				x2 = j;
			}
		}
	}
	q.push({ y1, x1, y2, x2, 0 });
	res = bfs();
	cout << res;
	return 0;
}