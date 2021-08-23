// 시간초과 
// m개의 치킨집 뽑기 : DFS 조합 이용

#include <iostream>
#include <vector>

using namespace std;

int n; // n*n 맵크기
int m; // 치킨집 개수
int map[51][51]; // 0: 빈칸, 1: 집, 2: 치킨집

vector< pair<int, int> > hs, ck; 

int path[15]; // 선택한 치킨집들이 저장된 배열

int res = 21e8; 

void Init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	//freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> n >> m;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> map[y][x];

			if (map[y][x] == 1) hs.push_back(make_pair(y, x));
			else if (map[y][x] == 2) ck.push_back(make_pair(y, x));
		}
	}
}

void DFS(int lv, int ck_cnt) {

	if (lv == m) { // 바닥조건 1. m개의 치킨집 선택되면, 도시의 치킨거리를 구한다
		int city_dis = 0;

		for (int i = 0; i < hs.size(); i++) {
			// 각 집의 치킨거리 구하기
			int dis = 21e8;

			for (int j = 0; j < m; j++) {

				int tmp_dis = abs(hs[i].first - ck[path[j]].first) + abs(hs[i].second - ck[path[j]].second);

				if (tmp_dis < dis) dis = tmp_dis;
			}

			// 도시의 치킨거리
			city_dis += dis;
		}

		if (city_dis < res) res = city_dis;

		return;
	}

	// m개의 치킨집 뽑기 -> 조합
	for (int i = ck_cnt; i < ck.size(); i++) {
		path[lv] = i;
		DFS(lv + 1, ck_cnt + 1);
		path[lv] = 0;
	}

}

int main() {

	Init();

	// m개의 치킨집만 선택 후, 도시의 치킨거리 비교 후 최소값 구하기 -> DFS
	DFS(0, 0);

	cout << res;

	return 0;
}