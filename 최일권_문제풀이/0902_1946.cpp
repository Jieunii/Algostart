#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {

	int tc;
	vector<pair<int, int>> score;
	cin >> tc;

	while (tc--) {
		int N;
		int ans = 0;

		score.clear();

		cin >> N;

		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			score.push_back({ a,b });
		}
		
		sort(score.begin(), score.end(), compare);
		int sec = score[0].second;

		for (int i = 0; i<score.size(); i++) {
			if (sec >= score[i].second) {
				sec = score[i].second;
				ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}