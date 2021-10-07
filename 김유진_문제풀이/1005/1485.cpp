//정사각형

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int path_x[2];
int path_y[2];
int x[4] = { 0, };
int y[4] = { 0, };
vector<long long> v;

void dfs(int depth, int idx) {
	if (depth == 2) {
		long long val = abs(path_x[0] - path_x[1]) * abs(path_x[0] - path_x[1]) + abs(path_y[0] - path_y[1]) * abs(path_y[0] - path_y[1]);
		//cout << path_x[0] << " " << path_y[0] << "," << path_x[1] << " " << path_y[1] << " : " << val << "\n";
		v.push_back(val);
		return;
	}

	for (int i = idx; i < 4; i++) {
		path_x[depth] = x[i];
		path_y[depth] = y[i];
		dfs(depth + 1, i + 1);
	}
}

int main() {
	int test_case = 0;

	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		//input
		v.clear();
		memset(y, 0, sizeof(y));
		memset(x, 0, sizeof(x));
		for (int i = 0; i < 4; i++) {
			cin >> y[i] >> x[i];
		}

		dfs(0, 0);
		sort(v.begin(), v.end());
		int de = -1;
		if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}