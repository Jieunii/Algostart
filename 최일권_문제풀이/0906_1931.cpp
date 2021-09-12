#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int>a, pair<int, int> b) {
	if (a.second < b.second) return true;
	if (a.second > b.second)return false;
	return a.first < b.first;
}

int main() {
	int N;
	int ans = 1;
	vector<pair<int, int>> office;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		office.push_back({ a,b });
	}

	sort(office.begin(), office.end(), compare);

	int end = office{0}.second;

	for (int i = 1; i < N; i++) {
		if (end <= office{i}.first) {
			end = office{i}.second;
			ans++;
		}
	}
	cout << ans << endl;



	return 0;
}