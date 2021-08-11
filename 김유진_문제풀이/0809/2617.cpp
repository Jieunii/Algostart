#include <iostream>
#include <vector>
using namespace std;

int n;
int m;
int cnt;
int res;
int h,l;
vector<int> h_start;
vector<int> l_start;
vector<int> heavy[100];
vector<int> light[100];
bool hused[100];
bool lused[100];
int visited[100];

void lgo(int start) {

	for (int i = 0; i < light[start].size(); i++) {
		int val = light[start][i];
		if (visited[val]) continue;
		visited[val] = 1;
		cnt++;
		lgo(val);
	}
}

void hgo(int start) {

	for (int i = 0; i < heavy[start].size(); i++) {
		int val = heavy[start][i];
		if (visited[val]) continue;
		visited[val] = 1;
		cnt++;
		hgo(val);
	}
}

void visited_init() {
	for (int i = 0; i < 100; i++) visited[i] = 0;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int h = 0;
		int l = 0;
		cin >> h >> l;
		if (!hused[l]) {
			hused[l] = true;
			h_start.push_back(l);
		}
		if (!lused[h]) {
			lused[h] = true;
			l_start.push_back(h);
		}
		heavy[l].push_back(h);
		light[h].push_back(l);
	}

	for (int i = 0; i < l_start.size(); i++) {
		visited_init();
		cnt = 0;
		int start = l_start[i];
		lgo(start);
		if (cnt >= (n + 1) / 2) {
			res++;
		}
	}

	for (int i = 0; i < h_start.size(); i++) {
		visited_init();
		cnt = 0;
		int start = h_start[i];
		hgo(start);
		if (cnt >= (n + 1) / 2) {
			res++;
		}
	}

	cout << res;

	return 0;
}