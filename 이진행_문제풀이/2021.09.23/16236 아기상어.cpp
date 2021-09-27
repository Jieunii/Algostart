/*
n*n 맵에 상어와 물고기가 주어짐
9는 상어, 1~6은 물고기.
상어의 초기 크기는 2. 상어는 자신보다 작은 크기의 물고기만 먹을 수 있다
상어는 자신의 크기만큼의 물고기를 먹으면 크기가 1 증가한다.
상어가 전체 맵에서 아무것도 먹을 수 없으면 엄마상어를 호출한다.
엄마상어를 호출할 때 까지 걸리는 시간은?

- 같은 크기의 물고기는 통과할 수 있다
- 물고기는 거리 우선, 위쪽 우선, 왼쪽 우선순위를 가진다

풀이 : 
BFS 우선순위 큐 이용
1. 처음 상어 위치를 저장.
2. BFS를 돌리며 먹이 탐색. <- 우선순위 큐에 의해 최단거리의 먹이가 top에 저장됨
3. 그 위치에 도달하면 상어가 먹은 개수 증가.
		-> 레벨업 할 수 있는지 확인
		-> 먹은 잔해 치우고 상어 위치 변경
		-> 이후 우선순위 큐를 초기화 
		-> 현재 위치에서 다시 이동하면서 먹이 탐색

*/

#include <iostream>
#include <queue>

using namespace std;

// 먹이 상태를 저장하는 구조체
struct State{
	int y;
	int x;
	int dis;
	
	bool operator<(const State& b) const {
		if (dis != b.dis) return dis > b.dis;	// 거리 우선
		if (y != b.y) return y > b.y;			// 거리 같으면 위쪽 우선
		else return x > b.x;					// 그것도 같으면 왼쪽 우선
	}
};

// 아기상어 구조체
struct Shark {
	int y;
	int x;
	int size;
	int ate;

	void sizeUp() {
		this->ate = 0;
		this->size++;
	}
} shark;

int N;
int map[21][21];
int visited[21][21];

int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };

void Input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				shark.y = y;
				shark.x = x;
				map[shark.y][shark.x] = 0; // 이동예정이니 빈공간으로 설정하기
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	// Init
	priority_queue<State> pq; // 먹이를 저장하는 우선순위 큐 사용
	int answer = 0;

	shark.size = 2;
	shark.ate = 0;

	visited[shark.y][shark.x] = 1;
	pq.push({ shark.y, shark.x, 0 });

	// BFS
	while (!pq.empty()) {
		State now = pq.top(); // 우선순위 큐에 의해 pq의 top에는 거리순으로 정렬되어 최단거리 먹이가 저장되어있음
		pq.pop();

		// 먹을수 있는 사이즈인지 확인
		if (map[now.y][now.x] != 0 && map[now.y][now.x] < shark.size) {
			shark.y = now.y; // 상어 이동
			shark.x = now.x;
			shark.ate++;

			// 사이즈 증가 확인
			if (shark.size == shark.ate) {
				shark.sizeUp();
			}

			// 먹이 치우기 및 방문배열 초기화
			map[now.y][now.x] = 0;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					visited[y][x] = 0;
				}
			}

			// 큐를 초기화
			while (!pq.empty()) {
				pq.pop();
			}

			answer = now.dis;
		}

		for (int t = 0; t < 4; t++) {
			int dy = now.y + direct[t][0];
			int dx = now.x + direct[t][1];

			if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue; // 경계처리
			if (shark.size < map[dy][dx]) continue; // 상어가 더 작으면 이동불가
			if (visited[dy][dx] == 1) continue; // 방문 확인

			visited[dy][dx] = 1;
			pq.push({ dy, dx, now.dis + 1 });
		}
	}

	cout << answer << endl;

	return 0;
}