//회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int start;
	int end;
};
vector<info> v;
int n;

bool compare(info front, info back){
	if (front.end < back.end) return true;
	if (front.end > back.end) return false;
	return front.start < back.start;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), compare);
	
	int idx = 0;
	int end_time = 0;
	int res = 0;
	while (idx < n) {
		if (end_time <= v[idx].start) {
			end_time = v[idx].end;
			res++;
		}
		idx++;
	}
	cout << res << endl;
	return 0;
}