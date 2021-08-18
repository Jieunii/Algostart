#include <iostream>
#include <queue>
#include <memory.h> // memset을 이용하기 위한

using namespace std;

int h, w;
int map[101][101];
int check[101][101] = { 0 };

// ←,↑,→,↓
int directY[4] = { 0, -1, 0, 1 };
int directX[4] = { -1, 0, 1, 0 };

void init() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> h >> w;
	for (int y = 1; y <= h; y++) {
		for (int x = 1; x <= w; x++) {
			cin >> map[y][x];
		}
	}
}

// 현재 시간에 남은 치즈 칸 수를 세는 함수
int countCheese() {
	int cnt = 0;

	for (int y = 1; y <= h; y++) {
		for (int x = 1; x <= w; x++) {
			if (map[y][x] == 1) {
				cnt++;
			}
		}
	}

	return cnt;
}

// 1,1과 닿아있는 부분은 모두 외부공간으로 체크해놓고
// 아닌 부분들은 치즈의 내부 구멍들로 판정. 
// 이후, 외부와 닿아있는 부분들을 녹인다
void spendHour() {

	// BFS 
	memset(check, 0, sizeof(check)); // 배열을 0으로 초기화
	queue< pair<int, int> > qu;
	qu.push(make_pair(1, 1));
	
	while (!qu.empty()) {
		pair<int, int> tmp = qu.front();
		qu.pop();

		// 4방향 체크하면서 외부 공기를 찾는다
		for (int i = 0; i < 4; i++) {
			int dy = tmp.first + directY[i];
			int dx = tmp.second + directX[i];

			if (dy < 1 || dx < 1 || dy > h || dx > w) continue; // 범위 벗어난 경우
			if (check[dy][dx] == true) continue; // 이미 확인 한 경우
			if (map[dy][dx] == 1) continue; // 치즈인 경우 

			qu.push(make_pair(dy, dx));
			check[dy][dx] = true;
		}
	}

	// 치즈 녹이기
	for (int y = 1; y <= h; y++) {
		for (int x = 1; x <= w; x++) {
			if (map[y][x] == 0) continue; // 공기라면 패스

			// 4면 중 하나라도 외부랑 닿는다면
			for (int i = 0; i < 4; i++) {
				int dy = y + directY[i];
				int dx = x + directX[i];
				
				if (check[dy][dx] == 1) {
					map[y][x] = 0; // 치즈를 녹임
					break;
				}
			}
		}
	}

}

int main() {

	init();

	int cheeseCnt = 0; 
	int time = 0;
	int lastCnt = 0;

	while (1) {
		int tmp = countCheese();

		if (tmp == 0) break; // 치즈가 다 녹으면 종료

		lastCnt = tmp; // 마지막 녹기 한시간 전 치즈

		spendHour();
		
		time++;
	}

	cout << time << endl << lastCnt;

	return 0;
}