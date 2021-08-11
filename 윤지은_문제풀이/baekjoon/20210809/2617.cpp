#include <iostream>
#include <vector>

using namespace std;

vector<int> heavy[101];
vector<int> light[101];
int visited[101];
int cnt = 0, result = 0;

void dfs(int gu, vector<int> arr[101]) {
	visited[gu] = 1;
	for (int i = 0; i < arr[gu].size(); i++) {
		int nextGu = arr[gu][i];
		if (visited[nextGu] == 1) continue;
		cnt++;
		dfs(nextGu, arr);
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	int standard = (N + 1) / 2; // 기준점
	int gu1, gu2;
	for (int i = 0; i < M; i++) {
		cin >> gu1 >> gu2;
		heavy[gu1].push_back(gu2);
		light[gu2].push_back(gu1);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int i = 1; i <= N; i++) visited[i] = 0;
		cnt = 0;
		dfs(i, heavy);
		if (cnt >= standard) result++;

		for (int i = 1; i <= N; i++) visited[i] = 0;
		cnt = 0;
		dfs(i, light);
		if (cnt >= standard) result++;
	}
	cout << result;


	return 0;
}