#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

char map[12][6];
int visited[12][6];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int bomb; // 터질 수 있는지 여부
int result;

void gravity() {
	for (int x = 0; x < 6; x++) {
		for (int y = 11; y >= 0; y--) {
			if (map[y][x] != '.') continue;
			bool flag = false;
			for (int i = y - 1; i >= 0; i--) {
				if (map[i][x] != '.') {
					map[y][x] = map[i][x];
					map[i][x] = '.';
					flag = true;
					break;
				}
			}
			if (!flag) break;
		}
	}
}

void erase(char color, int yy, int xx) {
	int color_cnt = 1;
	queue<pair<int, int>> loc; // bfs용 queue
	vector<pair<int, int>> e; // 지울 좌표 저장
	memset(visited, 0, sizeof(visited));

	loc.push({ yy, xx });
	e.push_back({ yy, xx });
	visited[yy][xx] = 1;

	while(!loc.empty()){
		int y = loc.front().first;
		int x = loc.front().second;
		loc.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6 || map[ny][nx] == '.') continue;
			if (visited[ny][nx] == 1 || map[ny][nx] != color) continue;
			visited[ny][nx] = 1;
			loc.push({ ny, nx });
			e.push_back({ ny, nx });
			color_cnt++;

			int tmpY = ny;
			int tmpX = nx;
			for (int j = 0; j < 4; j++) {
				ny = tmpY + dy[j];
				nx = tmpX + dx[j];
				if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6 || map[ny][nx] == '.') continue;
				if (visited[ny][nx] == 1 || map[ny][nx] != color) continue;
				visited[ny][nx] = 1;
				loc.push({ ny, nx });
				e.push_back({ ny, nx });
				color_cnt++;
			}			
			ny = tmpY;
			nx = tmpX;
		}
	}

	if(color_cnt >= 4){
		while (!e.empty()) {
			int eraseY = e.back().first;
			int eraseX = e.back().second;
			map[eraseY][eraseX] = '.';
			e.pop_back();
		}
		bomb = 1;
	}
}

int main() {
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			cin >> map[y][x];
		}
	}

	while (1) {
		int y, x;
		bomb = 0;
		for (y = 0; y < 12; y++) {
			for (x = 0; x < 6; x++) {
				if (map[y][x] == '.') continue;
				erase(map[y][x], y, x);
			}
		}
		if (bomb) { // 터질 수 있는 뿌요가 있거나 여러 그룹이면 동시에 터지고 한번만 추가
			result++;
			gravity();
		}
		else break;
	}
	
	cout << result;
	
	return 0;
}