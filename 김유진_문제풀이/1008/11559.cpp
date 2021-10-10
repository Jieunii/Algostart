//»Ñ¿ä»Ñ¿ä
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int res = 0;
char map[12][7];
int visited[12][7];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int> > block;

void gravity() {
	stack<char> s;
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y <= 11; y++) {
			if(map[y][x] != '.') s.push(map[y][x]);
		}

		int idx = 11;
		while (!s.empty()) {
			char c = s.top();
			map[idx][x] = c;
			idx--;
			s.pop();
		}
		while (idx > -1) {
			map[idx][x] = '.';
			idx--;
		}
	}
}

void dfs(int y, int x, char color) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6) continue;
		if (map[ny][nx] != color) continue;
		if (visited[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		block.push_back({ ny, nx });
		dfs(ny, nx, color);
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		cin >> map[i];
	}

	while (1) {
		int flag = 0;
		gravity();
		
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					block.clear();
					visited[i][j] = 1;
					block.push_back({ i, j });
					dfs(i, j, map[i][j]);
					if (block.size() >= 4) {
						for (int k = 0; k < block.size(); k++) {
							map[block[k].first][block[k].second] = '.';
							flag = 1;
						}
					}
				}
			}
		}
		if (flag == 0) break;
		res++;
	}

	cout << res << "\n";

	return 0;
}