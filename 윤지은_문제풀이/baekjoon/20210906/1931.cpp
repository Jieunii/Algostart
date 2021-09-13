#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> room(N);
	for (int i = 0; i < N; i++) {
		cin >> room[i].first >> room[i].second;
	}
	sort(room.begin(), room.end(), cmp);
	int compare = 0;
	int result = 0;
	for (int i = 0; i < room.size(); i++) {
		if (compare <= room[i].first) {
			result++;
			compare = room[i].second;
		}
	}
	cout << result;
	return 0;
}