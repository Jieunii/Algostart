#include <iostream>

using namespace std;

int t, cnt;
int arr[100001];		// 연결리스트
bool visit[100001];		// 단순 방문 배열
bool check[100001];		// 

void DFS(int index) {
	int next_num = arr[index]; 
	visit[index] = true;	

	if (!visit[next_num]) {
		DFS(next_num);
	}

	else {
		if (!check[next_num]) {
			for (int i = next_num; i != index; i = arr[i]) cnt++;
			cnt++;
		}
	}
	check[index] = true;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		cnt = 0;

		for (int i = 1; i <= n; i++) {
			if (!visit[i]) { 
				DFS(i);
			}
		}
		cout << n - cnt << endl;
	}

	return 0;
}