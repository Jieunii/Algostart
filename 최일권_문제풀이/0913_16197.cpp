#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int y;
	int x;
};

int N, M;
int cnt = 0;
char map[21][21] = {};
int visited[2][21][21] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ans = 999999999;

int isInside(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return 0;
	return 1;
}
queue<node> circle;

void coin(int y1, int x1, int y2, int x2, int cnt, int d) {
	if (ans < cnt) return;
	if (cnt > 10) {
		ans = min(ans, cnt);
		return;
	}

	int ny1 = y1 + dir[d][0];
	int nx1 = x1 + dir[d][1];
	int ny2 = y2 + dir[d][0];
	int nx2 = x2 + dir[d][1];

	if (!isInside(ny1, nx1) && !isInside(ny2, nx2)) return;
	if (!isInside(ny1, nx1)) ans = cnt;
	else if (!isInside(ny2, nx2)) ans = cnt;

	if (map[ny1][nx1] == '#') {
		ny1 = y1;
		nx1 = x1;
	}
	if (map[ny2][nx2] == '#') {
		ny2 = y2;
		nx2 = x2;
	}

	for (int i = 0; i < 4; i++) {
		coin(ny1, nx1, ny2, nx2, cnt + 1, i);
	}

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') {
				node temp;
				temp.y = i;
				temp.x = j;
				circle.push(temp);
			}
		}
	}
	node temp1 = circle.front();
	circle.pop();
	node temp2 = circle.front();
	circle.pop();

	for(int i=0;i<4;i++)
		coin(temp1.y,temp1.x,temp2.y,temp2.x,1,i);

	cout << ans << endl;

	return 0;
}