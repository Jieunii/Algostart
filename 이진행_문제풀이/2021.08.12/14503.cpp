#include <iostream>
#include <Windows.h>

using namespace std;

int map[50][50]; // 0 <= map[y][x] <= 50, 0: 방, 1: 벽, 2: 청소됨
int n, m; // r, c

struct Robot {
	int y;
	int x;
	int face = 0; // ↑:0, →:1, ↓:2, ←:3
	int cleanCnt = 0;

	void clean() {
		map[y][x] = 2; // 청소됨
		cleanCnt++;
	}
	
	bool searchTrashOnLeft() {
		int dy = y, dx = x;
		if (face == 0) { dx = x - 1; } // 위를 보고있다면, 왼쪽을 확인한다
		else if (face == 1) { dy = y - 1; } // 오른쪽이라면, 위
		else if (face == 2) { dx = x + 1; } // 아래라면, 오른쪽
		else if (face == 3) { dy = y + 1; } // 왼쪽이라면, 아래

		if (dy < 0 || dx < 0 || dy > n || dx > m) return false; // 벽

		if (map[dy][dx] == 0) return true; 
		else return false;
	}

	void turnLeft() {
		face--;
		if (face < 0) face = 3;
	}

	bool tryMoveFoward() {
		int dy = y, dx = x;
		if (face == 0) { dy--; }
		else if (face == 1) { dx++; }
		else if (face == 2) { dy++; }
		else if (face == 3) { dx--; }

		if (dy < 0 || dx < 0 || dy > n || dx > m) return false;
		if (map[dy][dx] == 1) return false;

		y = dy;
		x = dx;

		return true;
	}

	bool tryMoveBack() {
		int dy = y, dx = x;
		if (face == 0) { dy++; }
		else if (face == 1) { dx--; }
		else if (face == 2) { dy--; }
		else if (face == 3) { dx++; }

		if (dy < 0 || dx < 0 || dy > n || dx > m) return false;
		if (map[dy][dx] == 1) return false;

		y = dy;
		x = dx;

		return true;
	}

} rb;

void init() {
	// freopen_s(new FILE*, "test.txt", "r", stdin); 

	cin >> n >> m;
	
	cin >> rb.y >> rb.x >> rb.face;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
		}
	}
}

void showCurMap() {
	system("cls");

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (rb.y == y && rb.x == x) {
				cout << '@';
			}
			else if(map[y][x] == 0){
				cout << ' ';
			}
			else if (map[y][x] == 1) {
				cout << map[y][x];
			}
			else if (map[y][x] == 2) {
				cout << "_";
			}
		}
		cout << endl;
	}

	Sleep(1000);
}

int main() {

	init();

	while (1) {

		// 1. 현재 위치 청소
		if (map[rb.y][rb.x] == 0) { 
			rb.clean(); 
			showCurMap();
		}

		// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례로 인접한 칸을 탐색한다
		bool flag = 0;
		for (int i = 0; i < 4; i++) {

			// 2.a) 청소하지 않은 공간이 있다면, 그 방향으로 회전한 다음 한칸을 전진하고 그자리에서 1번부터 진행
			if (rb.searchTrashOnLeft() == true) {
				rb.turnLeft();
				rb.tryMoveFoward();
				break;
			}

			// 2.b) 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
			else {
				rb.turnLeft();
			}
			if (i == 3) {
				flag = 1;
			}
		}

		// 2.c) 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 
		// 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		if (flag == 1) {
			if (rb.tryMoveBack() == true) {
				continue;
			}

			// 2.d) 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
			else {
				break;
			}
		}
		
	}
	cout << rb.cleanCnt;

	return 0;
}