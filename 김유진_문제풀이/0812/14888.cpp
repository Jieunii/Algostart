#include <iostream>
#include <vector>
using namespace std;

int n;
int num[101];
int sort[101];
vector<int> op;
int max_res = -21e8;
int min_res = 21e8;
int visited[101];

void cal() {
	int res = num[0];
	for (int i = 0; i < n-1; i++) {
		if (sort[i] == 0) res += num[i + 1];
		else if (sort[i] == 1) res -= num[i + 1];
		else if (sort[i] == 2) res *= num[i + 1];
		else res /= num[i + 1];
	}
	for (int i = 0; i < n-1; i++) {
		cout << sort[i] << " ";
	}
	cout << "\n";
	cout <<  res << "\n";
	max_res = max(max_res, res);
	min_res = min(min_res, res);
}

void go(int depth) {
	if (depth == n - 1) {
		cal();
		return;
	}

	for (int i = 0; i < n-1; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			sort[depth] = op[i];
			go(depth + 1);
			visited[i] = 0;
		}
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		int x = 0;
		cin >> x;
		for (int j = 0; j < x; j++) {
			if (i == 0) op.push_back(0);
			else if (i == 1) op.push_back(1);
			else if (i == 2) op.push_back(2);
			else op.push_back(3);
		}
	}

	go(0);

	cout << max_res << "\n";
	cout << min_res;

	return 0;
}
