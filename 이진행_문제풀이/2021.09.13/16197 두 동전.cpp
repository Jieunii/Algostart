#include <iostream>
#include <vector>

using namespace std;

int N, M;
char map[21][21]; 
int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };

vector < pair<int, int> > coins;

int min_res = 21e8;

void Input() {
	cin >> N >> M;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'o') {
				coins.push_back(make_pair(y, x));
			}
		}
	}
}

// 동전이 맵 밖으로 떨어졌는지 확인
bool OutOfMap(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return true;
	}
	return false;
}

// 코인1, 2의 좌표와 버튼 횟수, 방향이 주어짐
void DFS(int coin1_y, int coin1_x, int coin2_y, int coin2_x, int btn_cnt, int dir) {
	// 백트래킹 1. 10번 넘어가면 패스
	if (btn_cnt > 10) return;

	int dy1 = coin1_y + direct[dir][0];
	int dx1 = coin1_x + direct[dir][1];

	int dy2 = coin2_y + direct[dir][0];
	int dx2 = coin2_x + direct[dir][1];

	bool isFirstCoinDead = OutOfMap(dy1, dx1);
	bool isSecondCoinDead = OutOfMap(dy2, dx2);

	if (isFirstCoinDead == true && isSecondCoinDead == true) { return; } // 둘다 떨어진 경우
	else if (isFirstCoinDead == true && isSecondCoinDead == false) { // 1번만 떨어진 경우
		if (btn_cnt < min_res) min_res = btn_cnt; // 정답 갱신
	}
	else if (isFirstCoinDead == false && isSecondCoinDead == true) { // 2번만 떨어진 경우
		if (btn_cnt < min_res) min_res = btn_cnt;
	}

	// 벽에 막혀 못움직이는 경우
	if (map[dy1][dx1] == '#') {
		dy1 = coin1_y;
		dx1 = coin1_x;
	}
	if (map[dy2][dx2] == '#') {
		dy2 = coin2_y;
		dx2 = coin2_x;
	}
	for (int i = 0; i < 4; i++) {
		DFS(dy1, dx1, dy2, dx2, btn_cnt + 1, i);
	}
}


int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	// 여기서부터 1번 이동으로 침
	for (int i = 0; i < 4; i++) {
		DFS(coins[0].first, coins[0].second, coins[1].first, coins[1].second, 1, i); 
	}
	
	if (min_res > 10) {
		min_res = -1;
	};
	cout << min_res;

	return 0;
}