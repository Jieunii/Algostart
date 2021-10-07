//�α��̵�

#include <iostream>
#include <queue>
using namespace std;

int n, l, r;
int map[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct info {
	int y;
	int x;
};

int bfs() {
	//����ã��
	int visited[51][51] = { 0, };
	int is_moved = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			queue<info> c;
			int world_cnt = 0;
			int population = 0;

			if (!visited[i][j]) {
				queue<info> q;
				c.push({ i, j }); //�̰Ÿ� ���ٰ� �Ѳ���?
				q.push({ i, j });
				visited[i][j] = 1;
				world_cnt++;
				population += map[i][j];

				while (!q.empty()) {
					int y = q.front().y;
					int x = q.front().x;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
						if (visited[ny][nx] == 1) continue;
						if (l <= abs(map[ny][nx] - map[y][x]) && abs(map[ny][nx] - map[y][x]) <= r) {
							world_cnt++;
							population += map[ny][nx];
							visited[ny][nx] = 1;
							q.push({ ny, nx });
							c.push({ ny, nx });
						}
					}
				}
			}

			//���� �α� �̵�
			if (c.size() != 1) {
				while (!c.empty()) {
					//cout << c.front().y << " " << c.front().x << " " << population / world_cnt << "\n";
					map[c.front().y][c.front().x] = population / world_cnt;
					c.pop();
					is_moved = 1;
				}
			}
		}
	}
	if (is_moved == 1) return 1;
	else return 0;
}

int main() {

	//input
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int res = 0;
	while (1) {
		int check = bfs();
		if (check == 0) break;
		res++;
	}

	cout << res << endl;

	return 0;
}