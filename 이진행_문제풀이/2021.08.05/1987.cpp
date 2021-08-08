/*
DFS.
alphabet 배열을 이용하여 방문한 칸 체크
*/
#include <iostream>

using namespace std;

int r, c;
int ans = 0;
char map[20][20];
int alphabet[26] = { 0 };

// ←↑→↓
int directY[4] = {0,-1,0,1};
int directX[4] = {-1,0,1,0};

void dfs(int y, int x, int cnt) {

	// 최대 칸수 저장
	ans = max(ans, cnt);

	// 4방향으로 시도
	for (int i = 0; i < 4; i++) {
		int dy = y + directY[i];
		int dx = x + directX[i];

		if (dy < 0 || dx < 0 || dy >= r || dx >= c) continue; // 범위 바깥이라면 패스

		// 이미 방문한 알파벳이라면 패스
		int idx = map[dy][dx] - 'A';
		if (alphabet[idx] == 1) continue; 

        // DFS
		alphabet[idx]++;
		dfs(dy, dx, cnt+1);
		alphabet[idx]--;
	}

}

int main() {

	cin >> r >> c;

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> map[y][x];
		}
	}

	// 0, 0 부터 방문
	int idx = map[0][0] - 'A';
	alphabet[idx] = 1;
	
	dfs(0, 0, 1);

	cout << ans << endl;

	return 0;
}