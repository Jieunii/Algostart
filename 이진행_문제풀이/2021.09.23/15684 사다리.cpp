#include <iostream>

using namespace std;

int N, M, H;
int ladder[31][11]; // 가로선의 정보를 저장. 
int answer = 21e8;

void Input() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int y, x;
		cin >> y >> x;
		ladder[y][x] = 1;
	}
}

bool check() {
	for (int x = 1; x <= N; x++) {
		int row = x;

		for (int y = 1; y <= H; y++) {
			if (ladder[y][row] == 1) row++; // 오른쪽으로
			else if (row > 1 && ladder[y][row - 1] == 1) row--; // 왼쪽으로
		}

		if (row != x) {
			return false;
		}
	}
	
	return true;
}

void DFS(int Lv, int start) {
	if (Lv > 3) return; // 가지치기 2 Lv이 3 넘어갈 경우

	if (check() == true) { // 바닥조건 : 정답 찾은경우
		if (Lv < answer) answer = Lv;
		return;
	}
	
	// 빈자리에 사다리 놓기
	for (int y = start; y <= H; y++) {
		for (int x = 1; x < N; x++) {
			if (ladder[y][x] == 1) continue; // 이미 있는경우
			if (ladder[y][x - 1] == 1 || ladder[y][x + 1] == 1) continue; // 좌우에 사다리 연속으로 배치불가

			ladder[y][x] = 1;
			DFS(Lv + 1, y);
			ladder[y][x] = 0;
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	Input();

	DFS(0, 1);

	if (answer == 21e8) {
		cout << -1;
	}
	else {
		cout << answer;
	}

	return 0;
}