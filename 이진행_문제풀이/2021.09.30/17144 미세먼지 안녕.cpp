/*
R(행 개수), C(열 개수(, T(시간)이 주어지고
현재 좌표에 미세먼지가 주어짐
T시간동안 확산과 공기청정기 가동이 반복될 때,
T초가 지난 후, 방에 남아있는 미세먼지 양 구하는 문제
*/


/*
확산)
ex)
0  30 7
-1 10 0
-1 0  20
"동시에" 일어나는 것이므로, 따로 갱신값을 저장할 배열을 만들어 저장
	temp
=> 1) 6 -18 6  2) 6 (-18+1) -2 ... map[R-1][C-1]까지 확인 후, 이를 map에 다시 더해줌
	  0  6  0     0    6     1
	  0  0  0     0    0     0 

공기청정기 위쪽은 반시계방향, 아래는 시계방향
미세먼지가 바람 방향대로 모두 한칸씩 이동.
공기청정기에서 부는 바람은 0으로 정화된 바람. 들어간 바람은 모두 정화됨
*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int R, C, T;
int map[52][52];
int temp[52][52] = { 0 };
int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };

void Input() {
	cin >> R >> C >> T;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
		}
	}
}

void SpreadAir() {
	memset(temp, 0, sizeof(temp)); // 갱신값을 저장할 temp 배열
		
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] == -1 || map[y][x] == 0) continue;

			int direct_cnt = 0; // 몇군데로 확산할건지
			for (int t = 0; t < 4; t++) {
				int dy = y + direct[t][0];
				int dx = x + direct[t][1];

				if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue; // 경계 처리
				if (map[dy][dx] == -1) continue; // 공기청정기 있는경우

				// 확산
				temp[dy][dx] += map[y][x] / 5;
				direct_cnt++;
			}
			temp[y][x] += - (map[y][x] / 5) * direct_cnt; // 확산하고 남은 크기
		}
	}
	// map에 저장된 temp 값을 더해줌
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			map[y][x] += temp[y][x];
		}
	}
}

void Purification() {

	// 공기정화기 위치 찾기
	int top_y = 0, bottom_y = 0;
	for (int y = 0; y < R; y++) {
		if (map[y][0] == -1) {
			top_y = y;
			bottom_y = y + 1;
			break;
		}
	}

	// 위쪽은 반시계 방향으로 정화
	for (int y = top_y - 1; y > 0; y--) {
		map[y][0] = map[y-1][0];
	}
	for (int x = 0; x < C-1; x++) {
		map[0][x] = map[0][x + 1];
	}
	for (int y = 0; y < top_y; y++) {
		map[y][C-1] = map[y+1][C-1];
	}
	for (int x = C - 1; x > 1; x--) {
		map[top_y][x] = map[top_y][x - 1];
	}
	map[top_y][1] = 0; // 신선한 공기

	// 아래쪽은 시계 방향으로 정화
	for (int y = bottom_y + 1; y < R - 1; y++) {
		map[y][0] = map[y + 1][0];
	}
	for (int x = 0; x < C - 1; x++) {
		map[R - 1][x] = map[R - 1][x + 1];
	}
	for (int y = R - 1; y >= bottom_y; y--) {
		map[y][C - 1] = map[y-1][C - 1];
	}
	for (int x = C - 1; x > 1; x--) {
		map[bottom_y][x] = map[bottom_y][x - 1];
	}
	map[bottom_y][1] = 0; // 신선한 공기
	
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	while (T--) {

		SpreadAir();

		Purification();

	}

	int pollution_amount = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] != 0 && map[y][x] != -1) {
				pollution_amount += map[y][x];
			}
		}
	}

	cout << pollution_amount;

	return 0;
}