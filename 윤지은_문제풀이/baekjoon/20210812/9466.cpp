#include <iostream>
#define MAX 100001

using namespace std;

int arr[MAX];
int visited[MAX];
int finished[MAX];
int cnt;

void DFS(int cur) {
	int next = arr[cur];
	visited[cur] = 1;

	if (visited[next] == 0) {
		DFS(next);
	}
	else if (finished[next] == 0) {
		for (int i = next; i != cur; i = arr[i]) {
			cnt++;
		}
		cnt++;
	}
	finished[cur] = 1;
}

int main() {
	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
			visited[j] = 0;
			finished[j] = 0;
		}
		for (int j = 1; j <= n; j++) {
			if (visited[j] == 0) DFS(j);
		}
		cout << n - cnt << endl;
	}

	return 0;
}