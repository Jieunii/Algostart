#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
#define MAX_ 51
//행과 열이 시작과 끝이 서로 연결되어 있음
//비바라기를 시전하면 N,1 N,2 N-1,1 N-1,2에 
//모든 구름이 di 방향으로 si만큼 이동
//각 구름에서 비가 내려서 칸에 저장된 물의 양 1 증가
//구름이 모두 소멸
//물이 증가한 칸에 물복사 마법 실행 
//대각선 방향에 있는 바구니 수만큼 r,c에 물양 증가
// => 대각선 방향으로 경계를 벗어나면 포함 X
// 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
// 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.

int N, M;
int dir[8][2] = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
int dia_dir[4][2] = { {-1,-1},{-1,1},{1,-1},{1,1} };
struct info {
	int d, s;
};
struct Node {
	int y, x;
};
int water[MAX_][MAX_] = {}; 
int tp_save[MAX_][MAX_] = {};
vector<info> direc;
queue<Node> que;
int visited[MAX_][MAX_] = {};

int isInside(int y, int x) {
	if (y<1 || y>N || x<1 || x>N)
		return 0;
	return 1;
}
int main() {

	cin >> N >> M;

	que.push({ N,1 });
	que.push({ N,2 });
	que.push({ N-1,1 });
	que.push({ N-1,2 });

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> water[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int s, d;
		cin >> d >> s;
		direc.push_back({ d - 1,s });
	}

	for (int i = 0; i < M; i++) {
		int d = direc[i].d;
		int s = direc[i].s;

		queue<Node> temp;
		memset(visited, 0, sizeof(visited));
		memset(tp_save, 0, sizeof(tp_save));

		while (!que.empty()) {
			int y = que.front().y;
			int x = que.front().x;
			que.pop();

			int ny = y + dir[d][0] * (s%N);
			int nx = x + dir[d][1] * (s%N);

			if (ny > N) ny -= N;
			if (nx > N) nx -= N;
			if (ny < 1) ny += N;
			if (nx < 1) nx += N;

			visited[ny][nx] = 1;
			water[ny][nx]++;
		}
			for (int yy = 1; yy <= N; yy++) {
				for (int xx = 1; xx <= N; xx++) {
					if (visited[yy][xx] != 0) {
						for (int k = 0; k < 4; k++) {
							int nny = yy + dia_dir[k][0];
							int nnx = xx + dia_dir[k][1];

							if (isInside(nny, nnx) && water[nny][nnx] != 0)
								tp_save[yy][xx]++;
						}
					}
				}
			}

		for (int k = 1; k <= N; k++) {
			for (int j = 1; j <= N; j++) {
				if (tp_save[k][j] != 0) {
					water[k][j] += tp_save[k][j];
				}
			}
		}

		for (int k = 1; k <= N; k++) {
			for (int j = 1; j <= N; j++) {
				if (water[k][j] >= 2 && visited[k][j]==0) {
					water[k][j] -= 2;
					temp.push({ k,j });
				}
			}
		}

		while (!temp.empty()) {
			int ty = temp.front().y;
			int tx = temp.front().x;

			que.push({ ty,tx });
			temp.pop();
		}

	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += water[i][j];
		}
	}
	
	cout << ans << endl;

	return 0;
}