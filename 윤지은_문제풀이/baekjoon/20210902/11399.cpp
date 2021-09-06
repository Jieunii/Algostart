#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if(a.second > b.second) return false;
	return a.first < b.first;
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> ATM(N); // 사람 번호, 걸리는 시간
	for (int i = 0; i < N; i++) {
		ATM[i].first = i;
		cin >> ATM[i].second;
	}
	sort(ATM.begin(), ATM.end(), cmp);

	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i+1; j++) {
			time += ATM[j].second;
		}
	}
	cout << time;
	return 0;
}