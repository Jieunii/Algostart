#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct info {
	int m;
	int s;
	int d;
};

int N, M, K;
vector<info> map[51][51];
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int main() {

	//input
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int y = 0, x = 0, m = 0, s = 0, d = 0;
		cin >> y >> x >> m >> s >> d;
		map[y][x].push_back({ m, s, d });
	}

	for (int k = 0; k < K; k++) {
		//1. move
		vector<info> tmp[51][51];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int l = 0; l < map[i][j].size(); l++) {
					int y = i;
					int x = j;
					for (int s = 0; s < map[i][j][l].s; s++) {
						y += dy[map[i][j][l].d];
						x += dx[map[i][j][l].d];
						if (y == 0) y = N;
						else if (y == N + 1) y = 1;
						if (x == 0) x = N;
						else if (x == N + 1) x = 1;
					}
					tmp[y][x].push_back({ map[i][j][l].m , map[i][j][l].s , map[i][j][l].d });
				}
			}
		}

		//2. 2개 이상의 파이어볼
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tmp[i][j].size() >= 2) {
					int even = 0;
					int odd = 0;
					int total_m = 0;
					int total_s = 0;
					int cnt = tmp[i][j].size();
					for (int l = 0; l < cnt; l++) {
						if (tmp[i][j][l].d % 2 == 0) even++;
						else odd++;
						total_m += tmp[i][j][l].m;
						total_s += tmp[i][j][l].s;
					}
					tmp[i][j].clear();
					total_m /= 5;
					total_s /= cnt;
					if (total_m == 0) continue;
					if (odd == cnt || even == cnt) {
						tmp[i][j].push_back({ total_m, total_s, 0 });
						tmp[i][j].push_back({ total_m, total_s, 2 });
						tmp[i][j].push_back({ total_m, total_s, 4 });
						tmp[i][j].push_back({ total_m, total_s, 6 });
					}
					else {
						tmp[i][j].push_back({ total_m, total_s, 1 });
						tmp[i][j].push_back({ total_m, total_s, 3 });
						tmp[i][j].push_back({ total_m, total_s, 5 });
						tmp[i][j].push_back({ total_m, total_s, 7 });
					}
				}
			}
		}

		//tmp -> map으로 복사
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j].clear();
				for (int l = 0; l < tmp[i][j].size(); l++) {
					map[i][j].push_back({ tmp[i][j][l].m , tmp[i][j][l].s ,tmp[i][j][l].d });
				}
			}
		}
	}

	//output
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int l = 0; l < map[i][j].size(); l++) {
				res += map[i][j][l].m;
			}
		}
	}

	cout << res << "\n";
	
	return 0;
}