#include<iostream>
#include<cstdlib>

using namespace std;

int N, M, B;
int map[501][501];
int time, minTime = 21e8, maxHeight = -1;
int main() {
	cin >> N >> M >> B;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	// 모든 높이 탐색
	for (int h = 0; h <= 256; h++) {
		int inventory = 0;
		int remove = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				int diff = map[y][x] - h;
				if (diff < 0) inventory += abs(diff); // inventory에서 꺼내써
				else remove += diff; // 블록 제거
			}
		}
		// 만들 수 O
		if (remove + B >= inventory) {
			int time = remove * 2 + inventory;
			if (minTime >= time) {
				minTime = time;
				maxHeight = h;
			}
		}
	}

	cout << minTime << " " << maxHeight;
	return 0;
}