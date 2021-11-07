#include <deque>
#include <iostream>
using namespace std;

int main() {

	deque<pair<int,int>> dq;

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		dq.push_back({ a,i + 1 });
	}

	int cur = dq.front().second;
	int idx = dq.front().first;

	dq.pop_front();
	//����� ���� �տ� ���� ���� �ڿ��� �����ϰ� front ���� �о����
	//������ ���� �ڿ� ���� ���� �տ��� �����ϰ� back ���� �о����
	while (!dq.empty()) {
		cout << cur<< " ";

		if (idx > 0) {
			for (int i = 0; i < idx - 1; i++) {
				int temp_idx = dq.front().first;
				int temp_cur = dq.front().second;
				dq.pop_front();
				dq.push_back({temp_idx,temp_cur});
			}
			cur = dq.front().second;
			idx = dq.front().first;
			dq.pop_front();
		}
		else if (idx < 0) {
			for (int i = 0; i < -1 * idx - 1; i++) {
				int temp_idx = dq.back().first;
				int temp_cur = dq.back().second;
				dq.pop_back();
				dq.push_front({ temp_idx,temp_cur });
			}
			cur = dq.back().second;
			idx = dq.back().first;
			dq.pop_back();
		}
	}
	cout << cur << endl;
	return 0;
}