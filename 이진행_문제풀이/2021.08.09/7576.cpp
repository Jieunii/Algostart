// BFS 문제

#include <iostream>
#include <queue>

using namespace std;

int map[1010][1010]; // 최대 1000개이므로 10개 더줌
int dis[1010][1010]; // 숙성거리를 저장

//←↑→↓
int directY[4] = { 0,-1,0,1};
int directX[4] = { -1,0,1,0 };

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	int m, n;
	queue< pair<int,int> > qu;

	cin >> m >> n;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				qu.push(make_pair(y, x));	// 시작시 익은 토마토의 좌표를 저장
			}
		}
	}

	// BFS
	while (!qu.empty()) {
		pair<int, int> now = qu.front();
		qu.pop();

		// 4방향으로 시도
		for (int i = 0; i < 4; i++) {
			int dy = now.first + directY[i];
			int dx = now.second + directX[i];

			if (dy < 1 || dx < 1 || dy > n || dx > m) continue;
			if (map[dy][dx] == -1) continue; // 토마토가 없는칸은 패스
			else if (map[dy][dx] == 0) { 
				qu.push(make_pair(dy, dx)); // 큐에 다음 위치를 넣고

				map[dy][dx] = 1; // 숙성 시킨다.
				dis[dy][dx] = dis[now.first][now.second] + 1; // 거리를 저장
			}
		}
	}

	// 모든 맵을 다 돌았는데 안익은 토마토가 남아있는 경우
	bool flag = 0;
	int max = 0;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (map[y][x] == 0) {
				flag = 1;
				break;
			}
			if (dis[y][x] > max) {
				max = dis[y][x];
			}
		}
	}

	if (flag == true) cout << -1;
	else {
		cout << max;
	}
	

	return 0;
}