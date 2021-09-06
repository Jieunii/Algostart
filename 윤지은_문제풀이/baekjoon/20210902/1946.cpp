#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
  int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

    // 1등은 무조건 채용
		int cnt = 1;
		vector<pair<int, int>> rank(N);
		for (int j = 0; j < N; j++) {
			cin >> rank[j].first >> rank[j].second;
		}
    // 성적 순
		sort(rank.begin(), rank.end());

    // 성적 1등 면접 성적보다 높은 사람 채용
		int interview = rank[0].second;
		for (int j = 1; j < N; j++) {
			if (interview > rank[j].second) {
				cnt++;
				interview = rank[j].second;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}