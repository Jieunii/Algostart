#include <iostream>
#include <deque>
#include <queue>
using namespace std;

struct info {
	int y;
	int x;
	int dir;
};

int map[101][101];
deque<info> snake;
queue<pair<int, char>> dir;
int n, k, l;
int dx[4] = { 1,0,-1,0 }; //우하좌상
int dy[4] = { 0,1,0,-1 };

void input() {
	//input
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int y = 0;
		int x = 0;
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x = 0;
		char c = ' ';
		cin >> x >> c;
		dir.push({ x, c});
	}
}

bool go() {

	int dir = snake.front().dir;
	int ny = snake.front().y + dy[dir];
	int nx = snake.front().x + dx[dir];

	if (ny < 1 || nx < 1 || nx > n || ny > n) return false;
	if (map[ny][nx] == 2) return false;

	if (map[ny][nx] != 1) {//사과가 없으면
		int by = snake.back().y;
		int bx = snake.back().x;
		snake.pop_back();
		map[by][bx] = 0;
	}
	snake.push_front({ ny, nx, dir });
	map[ny][nx] = 2;

	return true;
}

void turn() {
	char d = dir.front().second;
	dir.pop();
	int nd = 0;
	if (d == 'D') { //오른쪽
		nd = snake.front().dir + 1;
	}
	else {
		nd = snake.front().dir - 1;
	}
	if (nd < 0) nd = 3;
	else if (nd > 3) nd = 0;
	snake.front().dir = nd;
}

int main() {

	input();
	//뱀의 위치와 방향 추가
	snake.push_front({ 1, 1, 0});
	map[1][1] = 2;

	for (int i = 1; i < 15000; i++) {
		if (!go()) {
			cout << i;
			return 0;
		}

		if (dir.empty()) continue;
		if (dir.front().first == i) {
			turn();
		}
	}

	return 0;
}