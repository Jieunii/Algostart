#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vect;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else return false;
}

int main() {
	int N;
	int L, H;
	int result = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L >> H;
		vect.push_back({ L, H });
	}
	sort(vect.begin(), vect.end(), cmp);

	int left_width = vect[0].first;
	int left_height = vect[0].second;
	for (int i = 1; i < vect.size(); i++) {
		if (left_height <= vect[i].second) {
			result += (vect[i].first - left_width) * left_height;
			left_width = vect[i].first;
			left_height = vect[i].second;
		}
	}
	
	int right_width = vect.back().first;
	int right_height = vect.back().second;
	for (int i = vect.size()-2; i >= 0; i--) {
		if (right_height < vect[i].second) {
			result += (right_width - vect[i].first) * right_height;
			right_width = vect[i].first;
			right_height = vect[i].second;
		}
	}

	cout << result + left_height;
	return 0;
}