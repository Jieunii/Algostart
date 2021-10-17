#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, M, K;
int dir[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
int cnt[51][51] = {};

struct fire {
	int m, s, d, visited = 0;
};

vector<fire> shark[51][51];

void go_fireball(int y, int x, int s, int m, int d, int k) {
	cnt[y][x]--;
	shark[y][x][k].m = 0;
	shark[y][x][k].s = 0;
	shark[y][x][k].d = -1;

	int ny = y + dir[d][0] * (s%N);
	int nx = x + dir[d][1] * (s%N);

	if (ny > N) ny -= N;
	if (nx > N) nx -= N;
	if (ny < 1) ny += N;
	if (nx < 1) nx += N;

	cnt[ny][nx]++;
	shark[ny][nx].push_back({ m,s,d,1 });
}

int main() {

	cin >> N >> M >> K;
	//d는 방향 s는 속력 m은 질량

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		cnt[r][c] = 1;
		shark[r][c].push_back({ m,s,d,0 });
	}

	while (K--) {

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (shark[i][j].empty()) continue;
				int n = shark[i][j].size();

				for (int k = 0; k < n; k++) {
					if (shark[i][j][k].visited == 1) continue;
					go_fireball(i, j, shark[i][j][k].s, shark[i][j][k].m, shark[i][j][k].d, k);
				}
			}
		}
		

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (shark[y][x].empty()) continue;
				for (int k = 0; k < shark[y][x].size(); k++)
					shark[y][x][k].visited = 0;
				if (cnt[y][x] == 0) shark[y][x].clear();
				else if (cnt[y][x] >= 2) {
					int sum_m = 0;
					int sum_s = 0;
				
					int even = 0;
					int odd = 0;
					for (int k = 0; k < shark[y][x].size(); k++) {
						if (shark[y][x][k].m == 0) continue;
						sum_m += shark[y][x][k].m;
						sum_s += shark[y][x][k].s;
						if (shark[y][x][k].d % 2 == 0 && shark[y][x][k].d>=0) even++;
						else if (shark[y][x][k].d % 2 != 0 && shark[y][x][k].d >= 0) odd++;
					}
					shark[y][x].clear();

					if (sum_m / 5 == 0) {
						cnt[y][x] = 0;
						continue;
					}
					if (even==0 || odd==0) {
						shark[y][x].push_back({ sum_m / 5,sum_s / cnt[y][x],0 ,0 });
						shark[y][x].push_back({ sum_m / 5,sum_s / cnt[y][x],2 ,0 });
						shark[y][x].push_back({ sum_m / 5,sum_s / cnt[y][x],4,0 });
						shark[y][x].push_back({ sum_m / 5,sum_s / cnt[y][x],6 ,0 });
						cnt[y][x] = 4;
					}
					else {
						shark[y][x].push_back({ sum_m / 5,sum_s / cnt[y][x],1,0 });
						shark[y][x].push_back({ sum_m / 5,sum_s / cnt[y][x],3 ,0 });
						shark[y][x].push_back({ sum_m / 5,sum_s / cnt[y][x],5 ,0 });
						shark[y][x].push_back({ sum_m / 5,sum_s / cnt[y][x],7,0 });
						cnt[y][x] = 4;
					}
				}
			}
		}
		vector<fire> temp;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < shark[i][j].size(); k++) {
					int m = shark[i][j][k].m;
					int s = shark[i][j][k].s;
					int d = shark[i][j][k].d;
					if (m == 0) continue;
					temp.push_back({ m, s, d, 0 });
				}
				shark[i][j].clear();
				for (int k = 0; k < temp.size(); k++)
					shark[i][j].push_back(temp[k]);
				temp.clear();
			}
		}

	}

	int ans = 0;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (shark[y][x].empty()) continue;
			for (int k = 0; k < shark[y][x].size(); k++) {
				ans += shark[y][x][k].m;
			}
		}
	}

	cout << ans << endl;

	return 0;
}