/*
map[12][6]이 주어질 때,
몇개의 연쇄가 일어나는가?

풀이)
	연쇄체크->중력->연쇄체크-> ... 연쇄가 일어나지 않을때 까지 반복

	연쇄)
	  BFS를 돌려서 같은 원소가 4개 이상 연결되어있는지 체크 -> 연결되어있으면 0으로 바꿈
	  연쇄가 일어났으면 플래그 체크 -> 이후 반복문 탈출

	중력) <- 문제에 자주 쓰이는 알고리즘
	  밑에서부터 위로 확인하면서 빈 공간이면 위에 원소가 있는지 확인.
	  원소가 있으면 현재 위치로 옮기고 빈공간으로 바꿈


** 동시에 여러 그룹이 터져도 한번의 연쇄로 취급한다 **

*/

#include <iostream>
#include <vector>
#include <queue>

#define H 12
#define W 6

using namespace std;

char board[H][W]; 
int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };
bool chain_flag = false;
int answer = 0;

void Input() {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> board[y][x];
		}
	}

}

// 4개 이상이 연속으로 붙어있으면 터트림
void Chaining() {
	chain_flag = false;
	int map[H][W];
	// char map -> int map으로 변환
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (board[y][x] == '.') { map[y][x] = 0; }
			else if (board[y][x] == 'R') { map[y][x] = 1; }
			else if (board[y][x] == 'G') { map[y][x] = 2; }
			else if (board[y][x] == 'B') { map[y][x] = 3; }
			else if (board[y][x] == 'P') { map[y][x] = 4; }
			else if (board[y][x] == 'Y') { map[y][x] = 5; }
		}
	}

	int visited[H][W] = { 0 }; // 방문체크용
	vector< pair<int, int> > puyo_link; // 터트릴 뿌요들을 저장하는 벡터

	// 전체 map을 확인하면서 BFS 탐색을 통해 같은 색상의 원소가 4개 이상 연결되어있는지 확인한다
	for (int y = H-1; y > 0; y--) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] == 0) continue; // 빈곳 패스
			if (visited[y][x] == 1) continue; // 이미 확인한곳은 패스
			
			// BFS 시작
			int cur_puyo_color = map[y][x]; // 현재 뿌요 색상 체크
			queue< pair<int, int> > qu;
			puyo_link.clear(); 

			visited[y][x] = 1; 
			qu.push({ y, x });
			puyo_link.push_back({ y, x });

			while (!qu.empty()) {
				pair<int, int> now = qu.front();
				qu.pop();

				for (int t = 0; t < 4; t++) {
					int dy = now.first + direct[t][0];
					int dx = now.second + direct[t][1];

					if (dy < 0 || dx < 0 || dy >= H || dx >= W) continue; // 경계처리
					if (visited[dy][dx] == 1) continue; // 방문한 곳
					if (map[dy][dx] != cur_puyo_color) continue; // 현재 뿌요와 다른 색이라면 패스

					visited[dy][dx] = 1;
					qu.push({ dy, dx });
					puyo_link.push_back({ dy, dx });
				}
			}

			if (puyo_link.size() >= 4) {
				chain_flag = true; // 연쇄 발생함

				for (int i = 0; i < puyo_link.size(); i++) {
					int y = puyo_link[i].first;
					int x = puyo_link[i].second;

					// 터져서 없어짐
					map[y][x] = 0; 
					board[y][x] = '.'; 
				}
			}
		}
	}
}

void Gravity() {
	for (int x = 0; x < W; x++) {
		for (int y = H - 1; y >= 0; y--) {
			if (board[y][x] == '.') {
				int dy = y;
				while (dy > 0 && board[dy][x] == '.') { dy--; }
				board[y][x] = board[dy][x];
				board[dy][x] = '.';
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	
	while (1) {
		Chaining();

		if (chain_flag == false) break; // 체인이 발생하지 않으면 종료
		else { answer++; } // 여러 그룹이 터지더라도 하나의 연쇄로 취급

		Gravity();
	}

	cout << answer;

	return 0;
}