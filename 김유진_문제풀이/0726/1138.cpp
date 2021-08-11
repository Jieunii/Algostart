#include <iostream>
using namespace std;

int n, x;
int order[11];
bool visited[11];
int arr[11];

bool check() {
	for (int i = 1; i <= n; i++) { //order idx
		int cnt = 0;
		for (int j = 1; j <= n; j++) { // arr idx
			if (i < arr[j]) cnt++;
			else if (i == arr[j]) break;
		}
		if (order[i] != cnt) return 0;
	}
	return 1;
}

void dfs(int num, int idx) {
	if (num == n + 1) {
		if (check()) {
			for (int i = 1; i <= n; i++) {
				cout << arr[i] << ' ';
			}
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		arr[idx] = i;
		dfs(num + 1, idx + 1);
		visited[i] = false;
	}
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> order[i];
	}

	dfs(1, 1);

	return 0;
}
