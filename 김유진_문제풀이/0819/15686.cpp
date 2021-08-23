#include <iostream>
#include <vector>
using namespace std;

struct info {
	int y;
	int x;
};

int map[51][51];
int n, m, sum;
int res = 21e8;
int min_dis = 21e8;
vector<info> ch;
vector<info> home;
vector<info> selected;


void sel(int cnt, int idx) {
	if (cnt == m) {
		sum = 0;
		//도시의 치킨거리 구하기
		for (int i = 0; i < home.size(); i++) {
			min_dis = 21e8;
			for (int j = 0; j < selected.size(); j++) {
				min_dis = min(min_dis, abs(home[i].y - selected[j].y) + abs(home[i].x - selected[j].x));
			}
			sum += min_dis;
		}
		res = min(sum, res);
		return;
	}

	for (int i = idx; i < ch.size(); i++) {
		selected.push_back({ ch[i].y, ch[i].x });
		sel(cnt + 1, i + 1);
		selected.pop_back();
	}
}

int main() {

	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) home.push_back({ i, j });
			if (map[i][j] == 2) ch.push_back({ i, j });
		}
	}

	//m개의 치킨집 선택하기
	sel(0, 0);

	//output
	cout << res;
	return 0;
}