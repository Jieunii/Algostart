#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<pair<int, int>> station;
vector<pair<int, int>> path(4);
int checked[21];
int maxi;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	return false;
}

void dfs(int lev, int start) {
	if (lev == 4) {
		// 양끝 연결 x
		if (path[3].second == N - 1) { 
			if(path[0].second == 0) return; 
		}
		// 인접한 두 역 연결 x
		for (int i = 0; i < 3; i++) {
			if (path[i].second + 1 == path[i + 1].second) return;
		}
		
    // 타당도
		int tmp;
		tmp = pow(path[0].first + path[1].first, 2) + pow(path[2].first + path[3].first, 2);
		if (tmp > maxi) maxi = tmp;
		tmp = pow(path[0].first + path[3].first, 2) + pow(path[1].first + path[2].first, 2);
		if (tmp > maxi) maxi = tmp;
		return;
	}

	for (int i = start; i < N; i++) {
		if (checked[station[i].second] == 1) continue;
		path[lev] = { station[i].first, station[i].second };
		checked[station[i].second] = 1;
		dfs(lev + 1, i + 1);
		checked[station[i].second] = 0;
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		station.clear();
		maxi = 0;
		for (int j = 0; j < N; j++) {
			int people;
			cin >> people;
			station.push_back({ people, j });
		}
		dfs(0, 0);
		cout << "#" << i + 1 << " " << maxi << endl;
	}

	return 0;
}
