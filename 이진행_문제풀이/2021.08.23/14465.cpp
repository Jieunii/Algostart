#include <iostream>

using namespace std;

int n, k, b;
int street[100001] = { 0 };// 0: 정상, 1: 고장

void Input() {
	cin >> n >> k >> b;

	for (int i = 1; i <= b; i++) {
		int idx;
		cin >> idx;
		street[idx] = 1;
	}
}

// 연속된 k개의 신호등이 되기 위해 수리해야할 신호등 개수 리턴 
int SlideWindow() {
	int w = k;

	// (1,w)사이에 정상적인 신호등 개수 세기
	int sum = 0;
	for (int i = 1; i <= w; i++) {
		if (street[i] == 0) {
			sum++;
		}
	}

    // street[i]는 빼고, street[i+w]는 더하면서 끝까지 이동. 
    // (i,i+w) 사이에 정상작동하는 신호등 개수의 최대값 구하기
	int max_cnt = sum;
	for (int i = 1; i <= n-w; i++) {
		if (street[i + w] == 0) { sum++; }
		if (street[i] == 0) { sum--; }

		if (max_cnt < sum) {
			max_cnt = sum;
		}
	}

    // 최대 몇개까지 있는지 확인 한 뒤 몇개가 수리가 필요한지 계산한다
	int ret = w - max_cnt;

	return ret;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	
	Input();

	cout << SlideWindow();

	return 0;
}