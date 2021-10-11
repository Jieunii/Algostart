/*
N개의 막대 기둥이 좌표L과 높이 H가 주어짐.
이 창고의 지붕을 만들때, 전체 창고의 넓이 구하기

풀이)
최대 높이 H를 구하고, 왼쪽의 넓이, 오른쪽 넓이, 최대높이를 더한다.
-> 최대높이가 여러개면? 제일 마지막에 나온 하나만 선정. 
최대높이는 기준점이므로 하나만 선택하면 됨


*/

#include <iostream>

#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

using namespace std;

int N;
int warehouse[1005];

int start_idx = 1002, end_idx = 0;
int max_height = 0;
int max_height_idx = -1;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		warehouse[L] = H;

		start_idx = MIN(start_idx, L);
		end_idx = MAX(end_idx, L);

		if (max_height <= H) {
			max_height = H;
			max_height_idx = L;
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	int area_size = 0;

	// 최대 높이의 왼쪽 넓이 구하기
	int h = 0;
	for (int i = start_idx; i < max_height_idx; i++) {
		h = MAX(h, warehouse[i]); // h만큼 계속 더해주면서 이동

		area_size += h; 
	}

	// 최대 높이의 오른쪽 넓이 구하기
	h = 0;
	for (int i = end_idx; i > max_height_idx; i--) {
		h = MAX(h, warehouse[i]);
		area_size += h;
	}

	// 최대높이 블럭의 넓이
	area_size += warehouse[max_height_idx];

	cout << area_size;

	return 0;
}