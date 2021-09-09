//��Ƽ�� �����ٸ�

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
		//�ܼ�Ʈ�� �����ϸ� continue
		if (exist(val)) {
			continue;
		}

		//��ĭ�� ������ ����ְ� continue
		if (empty(val)) {
			continue;
		}

		//1. �ٽ� ������ �ʴ� ��� ���� : far_cnt�� ���� ũ��
		//2. now�� �ִ� ���߿� ���� �������� ���õ� ��� : far_cnt�� ���� ū�� ����
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

		//�����Ƽ���� ���� �ε����� �ֱ�
		now[remove_idx] = ord[i];
		res++;
	}

	cout << res;
	return 0;
}