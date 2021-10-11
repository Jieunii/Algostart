#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

char map[12][6] = {};
int visited[12][6] = {};

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int chain = 0;

struct Node {
	int y, x;
};

int isInside(int y, int x) {
	if (y < 0 || y >= 12 || x < 0 || x >= 6) return 0;

	return 1;
}
void input() {
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			cin >> map[y][x];
		}
	}
}

void gravity() {

	for (int x = 0; x < 6; x++) {
		for (int y = 11; y > 0; y--) {
			if (map[y][x] == '.') {
				for (int k = y - 1; k >= 0; k--) {
					if (map[k][x] != '.') {
						map[y][x] = map[k][x];
						map[k][x] = '.';
						break;
					}
				}
			}
		}
	}
}
int cnt = 0;
vector<Node> bomb;
void dfs(int y, int x, char color) {
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (visited[ny][nx] || !isInside(ny, nx)) continue;
		
		if (map[ny][nx] == color) {
			visited[ny][nx] = 1;
			bomb.push_back({ ny,nx });
			cnt++;
			dfs(ny, nx, color);
		}
	}

}

int main() {

	input();
	int flag = 0;

	while (1) {
		memset(visited, 0, sizeof(visited));
		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 6; x++) {
				if (map[y][x] == '.') continue;
				 cnt = 0;
				 bomb.clear();
				 dfs(y, x, map[y][x]);

				 if (cnt >= 4) {
					 for (int k = 0; k < bomb.size(); k++) {
						 map[bomb[k].y][bomb[k].x] = '.';
					 }
					 flag = 1;
				 }
			}
		}
	
		if (!flag) break;
		gravity();
		chain++;
		flag = 0;
	}

	cout << chain << endl;

	return 0;
}