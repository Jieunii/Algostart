
#include <iostream>
#include <queue>

using namespace std;

// 0 1 2 3 4 5 6 7 8 9
// 10
// 20 21
// 30 31 32
// 40 41 42 43
// ...

queue<long long> q;

int main() {
	int N, idx = 0;
	long long result;
	cin >> N;

	for (int i = 0; i <= 9; i++) {
		q.push(i);
	}
	while (idx <= N) {
		if (q.empty()) {
			result = -1;
			break;
		}
		result = q.front();
		q.pop();
		int tmp = result % 10;
		for (int i = 0; i < tmp; i++) {
			q.push(result * 10 + i);
		}
		idx++;
	}
	cout << result;
	return 0;
}