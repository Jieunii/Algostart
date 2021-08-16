#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n, k;
int map[101][101]; // 1<= y,x <= 100 이용, 0: 비어있음, 1: 뱀, 2: 사과

// →, ←, ↑, ↓
int directY[4] = {0, 0, -1, 1};
int directX[4] = {1, -1, 0, 0};

vector< pair<int, char> > cmd;

void input() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 2;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cnt;
		char ch;
		cin >> cnt >> ch;
		cmd.push_back(make_pair(cnt, ch));
	}
}


// 현재 어느 방향을 보고있는지 보고, ch에 따라 고개를 돌리는 함수
int turn_direction(int face, char ch) {
	if (ch == 'L') {
		if (face == 0) return 2;
		else if (face == 1) return 3;
		else if (face == 2) return 1;
		else if (face == 3) return 0;
	}
	else if (ch == 'D') {
		if (face == 0) return 3;
		else if (face == 1) return 2;
		else if (face == 2) return 0;
		else if (face == 3) return 1;
	}

}


int main() {
	
	input();

	deque< pair<int, int> > snake; // 뱀의 현재 위치를 저장하는 덱

	int sec = 0;
	int cnt = 0;

	// 뱀 (1,1) 에서 시작	
	int y = 1;
	int x = 1;
	int face = 0; // 뱀이 보는 방향 // →, ←, ↑, ↓
	map[y][x] = 1;
	snake.push_back(make_pair(y, x)); 


	while (1) {
		sec++;

		int dy = y + directY[face];
		int dx = x + directX[face];

		if (dy < 1 || dx < 1 || dy > n || dx > n) break; // 1. 벽에 닿은 경우
		else if (map[dy][dx] == 1) break; // 2. 자기 몸과 닿은경우
		else if (map[dy][dx] == 0) { // 3. 비어있는 경우

			map[dy][dx] = 1; // 머리이동
			pair<int, int> tail = snake.back();
			snake.pop_back();
			
			map[tail.first][tail.second] = 0; // 꼬리 땡기기
			snake.push_front(make_pair(dy, dx)); // 머리를 큐에 삽입

		}
		else if (map[dy][dx] == 2) { // 4. 사과가 있는 경우

			map[dy][dx] = 1; // 머리이동

			snake.push_front(make_pair(dy, dx)); // 머리를 큐에 삽입

		}

		// 명령어가 남아있는지 확인
		if (cnt < cmd.size()) {
			if (sec == cmd[cnt].first) {

				if (cmd[cnt].second == 'D') {
					face = turn_direction(face, 'D');
				}

				else if (cmd[cnt].second == 'L') {
					face = turn_direction(face, 'L');
				}

				cnt++;
			}
		}
		y = dy;
		x = dx;
	}

	cout << sec << endl;

	return 0;
}