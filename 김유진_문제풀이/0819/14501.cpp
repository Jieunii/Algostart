#include <iostream>
using namespace std;

int n;
int res = -21e8;
int t[16];
int p[16];

void go(int next, int sum) {

	if (next > n){
		res = max(res, sum);
		return;
	}

	if (next + t[next] <= n + 1) {
		//���ó�¥ �����Ѵ�
		go(next + t[next], sum + p[next]);
	}

	//���ó�¥ ���þ��Ѵ�
	go(next+1, sum);
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	go(1, 0);

	cout << res;

	return 0;
}