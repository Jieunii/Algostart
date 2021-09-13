/*
* n, m크기의 지도가 주어질 때,
* (0,0) -> (n-1,m-1)까지 도달. 가능한 힘을 적게 들이고 도달하는 방법
* 항상 내리막길로만 이동하는 경로 구하기 
*/

/*
* 1. DFS로 가지치기 이용 -> 시간초과
* 2. DFS + DP 이용: dp배열을 visited 배열용도로 사용하면서, 
*					dp[y][x]에 (y,x)부터 (n-1,m-1)까지 도달할 수 있는 '경로의 개수'를 저장한다.
 */

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[501][501];

int dp[501][501]; // dp + visited 배열
int direct[4][2] = { 1,0, 0,1, -1,0, 0,-1 };

void Input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			dp[y][x] = -1; // 아직 방문하지 않은 경우 -1임. 0은 경로가 없는것!
		}
	}
}

// (y,x)에서 (n-1, m-1)까지 갈 수 있는 경로의 개수를 반환하는 DFS
int DFS(int y, int x) {

	if (y == N - 1 && x == M - 1) { // 바닥조건 : map[N-1][M-1]에 도착시 종료
		return 1;
	}

	if (dp[y][x] != -1) return dp[y][x]; // 이미 방문한 적 있는 경우 <- 메모이제이션 사용

	// 첫 방문시 
	dp[y][x] = 0; 
	for (int t = 0; t < 4; t++) {
		int dy = y + direct[t][0];
		int dx = x + direct[t][1];

		if (dy < 0 || dx < 0 || dy > N - 1 || dx > M - 1) continue; // 배열 밖 처리
		if (map[y][x] <= map[dy][dx]) continue; // 가지치기 : 오르막길만 이동 가능

		dp[y][x] = dp[y][x] + DFS(dy, dx);

	}
	return dp[y][x];
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	cout << DFS(0, 0);

	return 0;
}