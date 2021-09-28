#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
int map[21][21];
int visited[21][21];
int sharkX, sharkY, sharkSize = 2;
int miniX, miniY, miniDist;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int result, cnt;

void init() {
	miniY = 22;
	miniX = 22;
	miniDist = 21e8;
	for (int y = 0; y < 21; y++) {
		for (int x = 0; x < 21; x++) {
			visited[y][x] = -1;
		}
	}
}

void BFS(int sharkY, int sharkX) {
	queue<pair<int, int>> q;
	q.push({ sharkY, sharkX });
	visited[sharkY][sharkX] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		// 상하좌우
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			// 범위 밖
			if (ny < 0 || ny >= N || nx<0 || nx >= N) continue; 

			// 이미 방문 or 상어보다 물고기가 더 클 때
			if (visited[ny][nx] != -1 || map[ny][nx] > sharkSize) continue; 

			// 물고기 이동거리
			visited[ny][nx] = visited[y][x] + 1;

			// 먹을 수 있는 물고기
			if (map[ny][nx] != 0 && map[ny][nx] < sharkSize) {
				if (miniDist > visited[ny][nx]) {
					miniY = ny;
					miniX = nx;
					miniDist = visited[ny][nx];
				}
				else if (miniDist == visited[ny][nx]) { // 여러 마리 -> 가장 위 & 가장 왼쪽
					if (miniY == ny) { 
						if (miniX > nx) {
							miniX = nx;
							miniY = ny;
						}
					}
					else if (miniY > ny) {
						miniY = ny;
						miniX = nx;
					}
				}
			}
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				sharkX = x;
				sharkY = y;
				map[y][x] = 0;
			}
		}
	}
	while (1) {
		init();
		BFS(sharkY, sharkX);
		// 먹을 수 있는 물고기 o
		if (miniY != 22 && miniX != 22) {
			result += visited[miniY][miniX]; // 이동시간
			cnt++; // 물고기 먹은 수 증가
			if (cnt == sharkSize) {
				sharkSize++;
				cnt = 0;
			}
			map[miniY][miniX] = 0;

			sharkY = miniY;
			sharkX = miniX;
		}
		// 먹을 수 있는 물고기 x
		else break;
	}
	cout << result;
	return 0;
}