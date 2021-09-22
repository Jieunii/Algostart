//상어중학교

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int n, m;
int res;
int map[21][21];
int visited[21][21];
struct info {
	int size;
	int rainbow_cnt;
	int y;
	int x;
	int block[21][21];
};
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
info big_block;

bool cmp(int b_cnt, int r_cnt, int y, int x) {
	if (big_block.size == 0) return true;
	else {
		if (big_block.size < b_cnt) return true;
		else if(big_block.size == b_cnt) {
			if (big_block.rainbow_cnt < r_cnt) return true;
			else if (big_block.rainbow_cnt == r_cnt) {
				if (big_block.y < y) return true;
				else if (big_block.y == y) {
					if (big_block.x < x) return true;
					else if (big_block.x == x) {
						return false;
					}
				}
			}
		}
	}
	return false;
}

void find_big_block() {
	//big_block 초기화
	big_block.size = 0;
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > 0 && !visited[i][j]) {
				queue<pair<int, int> >q;
				int temp_block[21][21] = {0,};
				q.push({ i, j });
				temp_block[i][j] = 1;
				visited[i][j] = 1;
				int r_cnt = 0;
				int b_cnt = 1;

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
						if (map[ny][nx] == -1) continue;
						if (map[ny][nx] == -2) continue;
						if (map[ny][nx] != map[i][j] && map[ny][nx] != 0) continue;
						if (visited[ny][nx]) continue;
						visited[ny][nx] = 1;
						if (map[ny][nx] == 0) r_cnt++;
						b_cnt++;
						temp_block[ny][nx] = 1;
						q.push({ ny,nx });
					}
				}

				if (cmp(b_cnt, r_cnt, i, j)) {
					big_block.size = b_cnt;
					big_block.rainbow_cnt= r_cnt;
					big_block.y = i;
					big_block.x = j;
					memcpy(big_block.block, temp_block, sizeof(temp_block));
				}
				//rainbow인곳 visited 초기화
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						if (map[a][b] == 0) {
							visited[a][b] = 0;
						}
					}
				}
			}
		}
	}

}

void remove_block() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (big_block.block[i][j] == 1) {
				map[i][j] = -2;
			}
		}
	}
	res += big_block.size * big_block.size;
}

void gravity() {
	for(int i = n-2; i >= 0; i--){
		for (int j = 0; j < n; j++) {
			if (map[i][j] == -2) continue;
			if (map[i][j] == -1)continue;

			int color = map[i][j];
			int nx = i + 1;
			while (1) {
				if (map[nx][j] != -2) break;
				if (nx == n) break;
				nx++;
			}
			nx--;
			map[i][j] = -2;
			map[nx][j] = color;
		}
	}
}

void rotate() {
	int tmp[21][21] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[n-j-1][i] = map[i][j];
		}
	}
	memcpy(map, tmp, sizeof(tmp));
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		find_big_block();
		if (big_block.size < 2) break;
		remove_block();
		gravity();
		rotate();
		gravity();
	}
	
	cout << res << endl;
	return 0;
}