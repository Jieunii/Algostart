/*
가로 세로 N, M 과 전체 음식물 쓰레기 개수 K가 주어짐
이후 차례로 K개의 음식물 쓰레기의 좌표가 주어질 때
가장 큰 음식물 쓰레기의 크기르 구하라

=>
BFS 가장 큰 섬 구하기 문제
1. (0,0)부터 (N-1,M-1)까지 탐색하면서, 쓰레기가 있다면 BFS를 시작한다.

	2. BFS에서 현재 위치의 쓰레기를 지우고 (map[y][x] = 0), 현재 좌표를 큐에 넣는다
	3. 4방향으로 탐색하면서 맵 내부에 있고, 방문하지 않았고, 쓰레기가 있다면 쓰레기 크기를 1 증가시킨 뒤 그 위치도 큐에 넣는다.
	4. 큐가 빌때까지 2~3을 반복하고 BFS탈출

5. 현재 저장된 최대 쓰레기 크기와 BFS에서 얻은 최대 쓰레기 크기를 비교한다.

6. 1~5를 끝까지 탐색 후 최대 쓰레기 출력
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K;
int map[101][101];
int visited[101][101];

int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };

struct node {
	int y;
	int x;
};

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1; // 0부터 사용
	}
}

int BFS(int y, int x) {
	memset(visited, 0, sizeof(visited));
	
	queue<node> qu;
	
	map[y][x] = 0;
	qu.push({ y,x });
	visited[y][x] = 1;
	int res = 0;

	while (!qu.empty()) {
		node now = qu.front();
		qu.pop();
		res++;

		for (int t = 0; t < 4; t++) {
			int dy = now.y + direct[t][0];
			int dx = now.x + direct[t][1];

			if (dy < 1 || dx < 1 || dy > N || dx > M) continue;
			if (visited[dy][dx] == 1) continue; // 이미 방문
			if (map[dy][dx] == 0) continue; // 쓰레기가 아님
			visited[dy][dx] = 1;

			map[dy][dx] = 0;
			
			qu.push({ dy,dx });
		}
	}
	return res;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	int max_trash_size = 0;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (map[y][x] == 1) {
				int tmp;
				tmp = BFS(y, x); // 쓰레기가 있다면 얘랑 연결된 쓰레기들 찾기
				if (max_trash_size < tmp) {
					max_trash_size = tmp;
				}
			}
		}
	}
	cout << max_trash_size;
	return 0;
}