#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int coinX1, coinY1, coinX2, coinY2;
char map[21][21];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int result = 21e8;

void dfs(int cnt, int coinY1, int coinX1, int coinY2, int coinX2) {
	if (cnt == 10) return;
	for (int i = 0; i < 4; i++) {
		int nCoinX1 = coinX1 + dx[i];
		int nCoinY1 = coinY1 + dy[i];
		int nCoinX2 = coinX2 + dx[i];
		int nCoinY2 = coinY2 + dy[i];
		if ((nCoinY1 < 0 || nCoinY1 >= N || nCoinX1 < 0 || nCoinX1 >= M) && (nCoinY2 < 0 || nCoinY2 >= N || nCoinX2 < 0 || nCoinX2 >= M)) continue;
		else if (0 <= nCoinY1 && nCoinY1 < N && 0 <= nCoinX1 && nCoinX1 < M && 0 <= nCoinY2 && nCoinY2 < N && 0 <= nCoinX2 && nCoinX2 < M) {
			if (map[nCoinY1][nCoinX1] == '#' && map[nCoinY2][nCoinX2] == '#') continue;
			if (map[nCoinY1][nCoinX1] == '#') {
				nCoinY1 = coinY1;
				nCoinX1 = coinX1;
			}
			if (map[nCoinY2][nCoinX2] == '#') {
				nCoinY2 = coinY1;
				nCoinX2 = coinX1;
			}
			dfs(cnt+1, nCoinY1, nCoinX1, nCoinY2, nCoinX2);
		}
		else {
			if (result > cnt + 1) result = cnt + 1;
			return;
		}
	}
}

int main() {
	cin >> N >> M;
	int check = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'o' && check == 0) {
				coinX1 = x;
				coinY1 = y;
				check++;
			}
			else if(map[y][x] == 'o' && check == 1){
				coinX2 = x;
				coinY2 = y;
			}
		}
	}
	dfs(0, coinY1, coinX1, coinY2, coinX2);
	if (result == 21e8) {
		cout << -1 << endl;
	}
	else {
		cout << result << endl;
	}
	return 0;
}