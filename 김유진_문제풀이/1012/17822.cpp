//원판돌리기

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct info {
	int x;
	int d;
	int k;
};
int n, m, t, flag;
int map[51][51];
int visited[51][51];
int dx[4] = { 0,0,-1,1 }; //상하좌우
int dy[4] = { -1,1,0,0 };
vector<info> v;

void rotation(int y, int dir, int time) {
	for (int j = 0; j < time; j++) {
		int tmp = 0;
		if (dir == 0) { //시계방향
			tmp = map[y][m];
			for (int i = m - 1; i >= 0; i--) {
				map[y][i + 1] = map[y][i];
			}
			map[y][1] = tmp;
		}
		else { //반시계방향
			tmp = map[y][1];
			for (int i = 2; i <= m; i++) {
				map[y][i - 1] = map[y][i];
			}
			map[y][m] = tmp;
		}
	}
}

int main() {
	//input
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < t; i++) {
		int x = 0, d=0, k=0;
		cin >> x >> d >> k;
		v.push_back({ x, d, k });
	}

	//start
	for (int test = 0; test < t; test++) {
		int x = v[test].x;
		int d = v[test].d;
		int k = v[test].k;

		for (int i = x; i <= n; i += x) {
			rotation(i, d, k);
		}

		flag = 0;
		memset(visited, 0, sizeof(visited));
		int tmp[51][51] = { 0, };
		memcpy(tmp, map, sizeof(map));
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] > 0 && !visited[i][j]) {
					queue<pair<int, int> > q;
					int num = map[i][j];
					q.push({ i, j });
					visited[i][j] = 1;
					int part_flag = 0;

					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int l = 0; l < 4; l++) {
							int ny = y + dy[l];
							int nx = x + dx[l];

							if (ny <= 0 || ny > n) continue;
							if (nx <= 0) nx = m;
							else if (nx > m) nx = 1;

							if (visited[ny][nx] == 1) continue;
							if (map[ny][nx] != num) continue;
							visited[ny][nx] = 1;
							tmp[ny][nx] = 0;
							q.push({ ny,nx });
							flag = 1;
							part_flag = 1;
						}
					}
					
					if (part_flag == 1) tmp[i][j] = 0;
				}
			}
		}
		memcpy(map, tmp, sizeof(tmp));
		

		if (flag == 0) {
			int sum = 0;
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (map[i][j] > 0) {
						sum += map[i][j];
						cnt++;
					}
				}
			}
			if (cnt == 0) {
				cout << 0 << "\n";
				exit(1);
			}
			int avg = sum / cnt;
			int left = sum % cnt;

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (map[i][j] > avg) {
						if(map[i][j] > 0) map[i][j] -= 1;
					}
					else if (map[i][j] < avg) {
						if(map[i][j] > 0) map[i][j] += 1;
					}
					else if (map[i][j] == avg && left > 0) {
						if (map[i][j] > 0) map[i][j] += 1;
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res += map[i][j];
		}
	}

	cout << res << "\n";
	return 0;
}