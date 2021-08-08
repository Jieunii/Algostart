#include <iostream>

using namespace std;

int R, C, maxi = -21e8;
char map[20][20];
int used[100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };


void run(int y, int x, int cnt) {
	if (maxi < cnt) maxi = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
		if (used[map[ny][nx]] == 1) continue;
		used[map[ny][nx]] = 1;
		run(ny, nx, cnt+1);
		used[map[ny][nx]] = 0;
	}
}

int main() {
	cin >> R >> C;
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> map[y][x];
		}
	}
	used[map[0][0]] = 1;
	run(0, 0, 1);
	
	cout << maxi;
}