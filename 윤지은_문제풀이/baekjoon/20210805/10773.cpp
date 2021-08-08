#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> note;
	int K, num;
	int sum = 0;
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num != 0) note.push(num);
		else note.pop();
	}

	while (!note.empty()) {
		int n = note.top();
		note.pop();
		sum += n;
	}
	cout << sum;
}