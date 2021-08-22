#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int map[51][51] = {};
int used[51][51] = {};
vector<pair<int, int>> chick;
vector<pair<int, int>> sel;
vector<pair<int, int>> house;
int ans_min_ = 999999999;

void select(int lev, int chk) {
	if (lev == M) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int min_dist = 999999;
			for (int j = 0; j < sel.size(); j++) {
				int dist = abs(house[i].first - sel[j].first) + abs(house[i].second - sel[j].second);
				if (min_dist > dist) {
					min_dist = dist;
				}
			}
			sum += min_dist;
		}
		if (ans_min_ > sum) {
			ans_min_ = sum;
		}
		return;
	}

	for (int i = chk; i < chick.size(); i++) {
		if (used[chick[i].first][chick[i].second] == 1) continue;
		used[chick[i].first][chick[i].second] = 1;
		sel.push_back(chick[i]);
		select(lev + 1, i);
		sel.pop_back();
		used[chick[i].first][chick[i].second] = 0;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back({ i,j });
			}
			if (map[i][j] == 2) {
				chick.push_back({ i,j });
			}
		}
	}

	select(0, 0);

	cout << ans_min_ << endl;

	return 0;
}