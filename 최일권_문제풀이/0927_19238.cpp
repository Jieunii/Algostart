#include <iostream>
#include <queue>
using namespace std;

struct node {
	int y;
	int x;
};
int N, M;
int gas;
int tar_y = -1;
int tar_x = -1;
int min_y = -1;
int min_x = -1;
int min_dist = 999999;
int tar_dist = 0;

int map[21][21] = {};
int dist[21][21] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
node tar[21][21];
void init() {
	min_dist = 9999999;
	min_y = -1;
	min_x = -1;
	tar_y = -1;
	tar_x = -1;
	tar_dist = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = -1;
		}
	}
}

int isInside(int y, int x) {
	if (y<1 || y>N || x<1 || x>N)
		return 0;
	return 1;
}

void find_money(int y, int x) {
	queue<node> que;
	que.push({ y,x });
	dist[y][x] = 0;

	while (!que.empty()) {
		y = que.front().y;
		x = que.front().x;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (!isInside(ny, nx) || map[ny][nx] == 1) continue;
			if (dist[ny][nx] == -1) {
				dist[ny][nx] = dist[y][x] + 1;
				if (map[ny][nx] >1 ) {
					if (min_dist > dist[ny][nx]) {
						min_dist = dist[ny][nx];
						min_y = ny;
						min_x = nx;
					}
					else if (min_dist == dist[ny][nx]) {
						if (min_y > ny) {
							min_y = ny;
							min_x = nx;
						}
						else if (min_y == ny) {
							if (min_x > nx) {
								min_x = nx;
							}
						}
					}
				}
				que.push({ ny,nx });
			}
		}
	}
}

void go_target(int y, int x) {
	queue<node> que;
	que.push({ y,x });
	dist[y][x] = 0;
	min_y = y;
	min_x = x;

	while (!que.empty()) {
		y = que.front().y;
		x = que.front().x;
		que.pop();

		if (y == tar[min_y][min_x].y && x == tar[min_y][min_x].x ) {
			tar_y = y;
			tar_x = x;
			tar_dist = dist[y][x];
			break;
		}


		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (!isInside(ny, nx) || map[ny][nx] == 1) continue;
			if (dist[ny][nx] == -1) {
				dist[ny][nx] = dist[y][x] + 1;
				que.push({ ny,nx });
			}
		}
	}
}

int main() {
	int k = 2;
	int ans = 0;
	cin >> N >> M >> gas;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
	int y, x;
	cin >> y >> x;

	for (int i = 0; i < M; i++) {
		int p_y, p_x, t_y, t_x;
		cin >> p_y >> p_x >> t_y >> t_x;

		map[p_y][p_x] = k;
		tar[p_y][p_x] = { t_y,t_x };
		k++;
	}

	int flag = 0;
	
	while(M--){
		init();
		if (map[y][x] > 1) {
			min_y = y;
			min_x = x;
			min_dist = 0;
		}
		else
			find_money(y, x);
		if (min_y == -1 && min_x == -1) {
			flag = 1;
			break;
		}

		map[y][x] = 0;

		gas -= min_dist;

		y = min_y;
		x = min_x;
		if (gas <= 0) {
			flag = 1;
			break;
		}
		map[y][x] = 0;
		init();
		go_target(y, x); 
	
		if (tar_y == -1 && tar_x == -1) {
			flag = 1;
			break;
		}

		if (gas < tar_dist) {
			flag = 1;
			break;
		}
		gas -= tar_dist;
		gas += (tar_dist * 2);
		y = tar_y;
		x = tar_x;
	}
	
	if (flag) cout << -1 << endl;
	else
		cout << gas << endl;

	return 0;
}