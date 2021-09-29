#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
char map[101][101] = {};
int visited[101][101] = {};
int ans = 1;
int Max = -999999999;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int isInside(int y, int x) {
	if (y < 0 || y > N || x < 0 || x > M)
		return 0;
	return 1;
}

void find_trash(int y, int x) {

	visited[y][x] = 1;

	if (Max < ans)
		Max = ans;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (isInside(ny, nx) && !visited[ny][nx] && map[ny][nx]=='#') {
			ans++;
			find_trash(ny, nx);
		}
	}
}

int main() {
	
	vector<pair<int, int>> axis;
	scanf_s("%d %d %d", &N, &M, &K);


	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		axis.push_back({ r,c });
		map[r][c] = '#';
	}


	for (int i = 0; i < axis.size(); i++) {
		ans = 1;
		find_trash(axis[i].first, axis[i].second);
	}
	ans = Max;

	printf_s("%d\n", ans);

	return 0;
}