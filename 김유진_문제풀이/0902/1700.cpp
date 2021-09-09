//멀티탭 스케줄링

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, k;
int now[101];
int dat[101];
int res;
vector<int> ord;

bool exist(int num) {
	for (int i = 0; i < n; i++) {
		if (now[i] == num) return true;
	}
	return false;
}

bool empty(int num) {
	for (int i = 0; i < n; i++) {
		if (now[i] == 0) {
			now[i] = num;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x = 0;
		cin >> x;
		ord.push_back(x);
	}

	for (int i = 0; i < k; i++) {
		int val = ord[i];
		//콘센트에 존재하면 continue
		if (exist(val)) {
			continue;
		}

		//빈칸이 있으면 집어넣고 continue
		if (empty(val)) {
			continue;
		}

		//1. 다시 사용되지 않는 기기 선택 : far_cnt가 가장 크다
		//2. now에 있는 것중에 제일 마지막에 선택될 기기 : far_cnt가 가장 큰거 선택
		int remove_idx, far_cnt = -1;

		for (int j = 0; j < n; j++) {
			int cnt = 0;
			int next = i + 1;

			while (next < k && now[j] != ord[next]) {
				cnt++;
				next++;
			}

			if (cnt > far_cnt) {
				far_cnt = cnt;
				remove_idx = j;
			}
		}

		//현재멀티탭을 지울 인덱스에 넣기
		now[remove_idx] = ord[i];
		res++;
	}

	cout << res;
	return 0;
}