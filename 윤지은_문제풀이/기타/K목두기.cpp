#include <iostream>
#include <vector>

using namespace std;

int M, K, cnt;
int flag; // win
int game; // 회차
vector<pair<int, int>> saedol;
vector<pair<int, int>> gamma;
int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };
char map[18][18]; // saedol : O, gamma : X
char stone;

void initial() {
	for (int y = 0; y < 17; y++) {
		for (int x = 0; x < 17; x++) {
			map[y][x] = '_';
		}
	}
}

// 이겼는지 판단
void win(int y, int x, char s) {
	char bande;
	if (s == 'O') bande = 'X';
	else bande = 'O';

	cnt = 1;
	for (int i = 0; i < 8; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= 18 || ny >= 18 || map[ny][nx] == '_') continue;
		if (map[ny][nx] != bande) {
      // 한방향으로 쭉
      // ___OX__
      // _X_O___ 현 위치
      // __XO___ 아래쪽으로 쭉
			while (1) {
				cnt++;
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || ny < 0 || nx >= 18 || ny >= 18 || map[ny][nx] == '_' || map[ny][nx] == bande) break;
			}
      // 역방향으로 쭉
      // ___OX__ 위쪽으로 쭉
      // _X_O___ 현 위치
      // __XO___ 
			nx = x;
			ny = y;
			while (1) {
				nx -= dx[i];
				ny -= dy[i];
				if (nx < 0 || ny < 0 || nx >= 17 || ny >= 17 || map[ny][nx] == '_' || map[ny][nx] == bande) break;
				cnt++;
			}
      // win
			if (cnt == K) {
				flag = 1;
				return;
			}
		}
		cnt = 1;
	}
}

// 바둑돌 놓기
void kmok() {
	for (int i = 0; i < M; i++) {
		game += 2;

		// saedol
		int sy = saedol[i].first;
		int sx = saedol[i].second;
		stone = 'O';
		flag = 0;
		map[sy][sx] = stone;
		win(sy, sx, stone);
		if (flag == 1) {
			cout << game - 1 << endl;
			cout << "세돌이\n";
			return;
		}

		// gamma
		int gy = gamma[i].first;
		int gx = gamma[i].second;
		stone = 'X';
		flag = 0;
		map[gy][gx] = stone;
		win(gy, gx, stone);
		if (flag == 1) {
			cout << game << endl;
			cout << "감마고\n";
			return;
		}
	}
}
int main() {
	int R, C;
	cin >> M >> K;
	initial();
	for (int i = 0; i < M; i++) {
		cin >> R >> C;
		saedol.push_back({ R, C });
	}
	for (int i = 0; i < M; i++) {
		cin >> R >> C;
		gamma.push_back({ R, C });
	}
	kmok();
	//승자가 없을 때
	if (flag == 0) {
		cout << 0;
	}

	return 0;
}