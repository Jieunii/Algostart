/*
2차원의 배열의 행과 열의개수 N과
2차원배열의 첫번째 행부터 N번째 행까지 순서대로 한 행의 높이정보가 가 주어질 때,
물에 잠기지 않는 안전한 영역의 최대 개수를 구하는 문제

풀이)
비가 최소높이보다 적게오면 섬 하나가 그대로 있으므로, 안전 영역은 최대 한개임
비가 최대높이보다 많이 오면 모두 물에 잠긴다
-> (최소높이,최대높이) 만큼 확인하면서 BFS 섬의 개수가 최대가 되는 경우를 구하는 문제
=> (최소높이 -1, 최소높이) 최소높이 -1부터 시작해야함
(모두 높이가 같은경우, 최소높이부터 시작하면 모두 가라앉은 상태로 시작하므로, 섬의 개수가 0으로 나옴)

*/

#include <iostream>
#include <queue>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int N;
int map[102][102];
int cur_map[102][102];
int visited[102][102];
int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };

int min_height = 21e8;
int max_height = 0;

void Input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			max_height = MAX(map[y][x], max_height);
			min_height = MIN(map[y][x], min_height);
		}
	}
}

// height를 받아, height 이하의 섬들을 모두 가라앉히고
// 떠있는 섬의 개수를 리턴하는 함수
int CountIsland(int height) {
	int res = 0; // 섬의 개수
	// cur_map init
	memset(cur_map, 0, sizeof(map)); 

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			// 가라앉히기
			if (map[y][x] <= height) {
				cur_map[y][x] = 0;
			}
			else {
				cur_map[y][x] = 1;
			}
		}
	}

	queue< pair<int, int> > qu;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			if (cur_map[y][x] == 0) continue;
			// 현재 섬이라면
			// BFS Init
			res++;

			qu.push(make_pair(y, x));
			memset(visited, 0, sizeof(visited));
			visited[y][x] = 1;
			cur_map[y][x] = 0; 

			// BFS // 현재 좌표와 연결된 섬을 모두 0으로 가라앉힌다
			while (!qu.empty()) {
				pair<int, int> now = qu.front();
				qu.pop();

				for (int t = 0; t < 4; t++) {
					int dy = now.first + direct[t][0];
					int dx = now.second + direct[t][1];

					if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue; // 경계처리
					if (cur_map[dy][dx] == 0) continue;	// 물인 경우

					visited[dy][dx] = 1;
					cur_map[dy][dx] = 0;
					qu.push(make_pair(dy, dx));
				}
			}
		}
	}
	return res;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	int island_max = 0;
	for (int i = min_height -1; i <= max_height; i++) { 
		island_max = MAX(island_max, CountIsland(i));
	}

	cout << island_max;
	
	return 0;
}