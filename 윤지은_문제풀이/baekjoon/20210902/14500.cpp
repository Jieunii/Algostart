#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[501][501];
int block[19][3][2] = {
	// ㅡ 모양
	{{0, 1}, {0, 2}, {0, 3}},
	{{1, 0}, {2, 0}, {3, 0}},
	// ㅁ 모양
	{{0, 1}, {1, 0}, {1, 1}},
	// ㄴ 모양
	{{0, 1}, {0, 2}, {-1, 2}},
	{{1, 0}, {2, 0}, {2, 1}},
	{{1, 0}, {0, 1}, {0, 2}},
	{{0, 1}, {1, 1}, {2, 1}},
	{{1, 0}, {2, 0}, {2, -1}},
	{{1, 0}, {1, 1}, {1, 2}},
	{{1, 0}, {2, 0}, {0, 1}},
	{{0, 1}, {0, 2}, {1, 2}},
	// ㄱ__ 모양
	{{1, 0}, {1, 1}, {2, 1}},
	{{0, 1}, {-1, 1}, {-1, 2}},
	{{1, 0}, {0, 1}, {-1, 1}},
	{{0, 1}, {1, 1}, {1, 2}},
	// ㅜ 모양
	{{0, 1}, {0, 2}, {1, 1}},
	{{0, 1}, {1, 1}, {-1, 1}},
	{{0, 1}, {0, 2}, {-1, 1}},
	{{1, 0}, {2, 0}, {1, 1}},
};

int main() {
	int N, M;
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	int maxi = -21e8;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			for (int i = 0; i < 19; i++) {
				int flag = 1;
				int sum = map[y][x];
				for (int j = 0; j < 3; j++) {
					int ny = block[i][j][0] + y;
					int nx = block[i][j][1] + x;
					if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
						flag = 0;
						break;
					}
					sum += map[ny][nx];
				}
				if (flag && maxi < sum) maxi = sum;
			}
		}
	}
	cout << maxi;
	return 0;
}