#include <iostream>

using namespace std;

int map[501];
int h, w;

void init() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		cin >> map[i];
	}
}

// 현재 칸에 저장될 물을 구하는 함수
// 제일 왼쪽과 오른쪽에는 물이 고일 수 없으므로, 
// idx : (1, w-1)
int water(int idx) {
	int leftIdx = 0, rightIdx = w - 1;

	// 왼쪽에서 가장 큰 기둥 탐색 (0~idx)
	for (int i = 0; i < idx; i++) {
		if (map[i] > map[leftIdx]) {
			leftIdx = i;
		}
	}

	// 오른쪽에서 가장 큰 기둥 탐색 (idx~w-1)
	for (int i = idx; i < w - 1; i++) {
		if (map[i] > map[rightIdx]) {
			rightIdx = i;
		}
	}

	// 둘 중 작은 기둥 선택
	int k = min(map[leftIdx], map[rightIdx]);
	
	// 현재 칸에 물이 얼마나 저장될지 계산
	int res = k - map[idx];
	if (res < 0) res = 0;	// 자기보다 큰 기둥이 없어서 음수가 나오는 경우 0으로 처리

	return res;
}

int main() {

	init();

	int res = 0;
	for (int i = 1; i < w-1; i++) {
		res += water(i);
	}

	cout << res;

	return 0;
}