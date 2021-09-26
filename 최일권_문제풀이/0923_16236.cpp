#include <iostream>
#include <queue>
using namespace std;
struct node {
	int y;
	int x;
};
int map[21][21] = {};
int dist[21][21] = {};
int N;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int food_y = -1, food_x = -1;
int food_dist = 99999999;
int shark_y = 0, shark_x = 0;
int shark_size = 2;
int ans = 0;
//크기가 같으면 지나갈 수는 있지만 먹을 수는 없다
//아기 상어 위치 = 9
//아기 상어 크기 = 2

int isInside(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)
		return 0;
	return 1;
}

void init() {
	food_y = -1;
	food_x = -1;
	food_dist = 9999999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = -1;
		}
	}
}

void baby_shark(int y, int x) {
	node Node;
	Node.y = y;
	Node.x = x;

	queue<node> shark;
	shark.push(Node);
	dist[y][x] = 0;
	while (!shark.empty()) {
		node temp = shark.front();
		y = temp.y;
		x = temp.x;
		shark.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];

			if (dist[dy][dx] != -1) continue;
			if (!isInside(dy, dx) || map[dy][dx] > shark_size) continue;

			if (dist[dy][dx]==-1) {
				dist[dy][dx] = dist[y][x] + 1;
				if (map[dy][dx]!=0 && map[dy][dx] < shark_size) {
					if (food_dist > dist[dy][dx]) {
						food_dist = dist[dy][dx];
						food_y = dy;
						food_x = dx;
					}
					else if (food_dist == dist[dy][dx]) {
						if (food_y > dy) {
							food_y = dy;
							food_x = dx;
						}
						else if (food_y == dy) {
							if (food_x > dx) {
								food_y = dy;
								food_x = dx;
							}
						}
					}
				}
				shark.push({ dy,dx });
			}
		}

	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark_y = i;
				shark_x = j;
			}
		}
	}

	int food = 0;
	while (1) {
		init();
		baby_shark(shark_y, shark_x);
		if (food_y == -1 && food_x == -1) break;
		map[shark_y][shark_x] = 0;
		map[food_y][food_x] = 9;
		shark_y = food_y;
		shark_x = food_x;
		ans += food_dist;
		food++;
		if (food == shark_size) {
			food = 0;
			shark_size++;
		}
	}
	printf("%d\n", ans);

	return 0;
}