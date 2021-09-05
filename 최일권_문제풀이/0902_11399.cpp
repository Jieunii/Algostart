#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;

	vector<int> t;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int tm;
		cin >> tm;
		t.push_back(tm);
	}

	sort(t.begin(), t.end());

	int ans = t[0];
	vector<int> sum;
	sum.push_back(ans);
	for (int i = 1; i < t.size(); i++) {
		ans += t[i];
		sum.push_back(ans);
	}
	ans = 0;
	for (int i = 0; i < sum.size(); i++)
		ans += sum[i];

	cout << ans << endl;

	return 0;
 }