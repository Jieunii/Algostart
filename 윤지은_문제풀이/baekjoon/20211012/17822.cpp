#include <iostream>
#include <queue>

using namespace std;

int N, M, T;
int num, dir, k;
int arr[51][51];
int check[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int result;

void rotate(int idx, int dir, int k) {
	for (int i = 0; i < k; i++) {
		int temp = arr[idx][M];
		for (int j = M; j > 1; j--) {
			arr[idx][j] = arr[idx][j - 1];
		}
		arr[idx][1] = temp;
	}
}

void bfs() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			check[y][x] = 0;
		}
	}
	bool flag = false; // 그룹여부
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (!check[y][x] && arr[y][x] > 0) {
				check[y][x] = 1;
				bool same = false;
				queue<pair<int, int>> q;
				q.push({ y, x });
				int val = arr[y][x];
				while (!q.empty()) {
					int yy = q.front().first;
					int xx = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int ny = yy + dy[i];
						int nx = xx + dx[i];
						if (nx > M) nx = 1;
						else if (nx < 1) nx = M;
						if (ny > 0 && ny <= N && !check[ny][nx] && arr[ny][nx] == val) {
							q.push({ ny, nx });
							check[ny][nx] = 1;
							arr[ny][nx] = 0;
							same = 1;
						}
					}
				}
				if (same) {
					arr[y][x] = 0;
					flag = 1;
				}
			}
		}
	}

  // 그룹 없을 때
	if (!flag) {
		int tot = 0;
		int cnt = 0;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				tot += arr[y][x];
				if (arr[y][x] > 0) cnt++;
			}
		}
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				if (arr[y][x] > 0) {
					if (arr[y][x] * cnt > tot) arr[y][x] -= 1; // 평균보다 큰 수는 -1
					else if (arr[y][x] * cnt < tot) arr[y][x] += 1; // 평균보다 작은 수는 +1
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> T;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> arr[y][x];
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> num >> dir >> k;
		if (dir == 1) k = M - k; // 시계방향으로 통일
		int idx = num;
		while (idx <= N) {
			rotate(idx, dir, k);
			idx += num;
		}
		bfs();
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			result += arr[y][x];
		}
	}
	cout << result;
	return 0;
}
