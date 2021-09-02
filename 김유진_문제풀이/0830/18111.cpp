
#include <iostream>
using namespace std;

int n, m, b;
int dat[257];
int front = 21e8;
int back = -21e8;
int res;

int main() {

	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = 0;
			cin >> x;
			dat[x]++;
			if (front > x) front = x;
			if (back < x) back = x;
		}
	}

	while (front != back) {

		// 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오.
		if (dat[front] <= (dat[back] * 2) && dat[front] <= b) {
			res += dat[front];
			b -= dat[front];
			dat[front + 1] += dat[front];
			dat[front] = 0;
			front++;
		}
		else {
			res += dat[back] * 2;
			b += dat[back];
			dat[back-1] += dat[back];
			dat[back] = 0;
			back--;
		}
	}

	cout << res << " " << front;
	return 0;
}