#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
#define MAX_ 51
//��� ���� ���۰� ���� ���� ����Ǿ� ����
//��ٶ�⸦ �����ϸ� N,1 N,2 N-1,1 N-1,2�� 
//��� ������ di �������� si��ŭ �̵�
//�� �������� �� ������ ĭ�� ����� ���� �� 1 ����
//������ ��� �Ҹ�
//���� ������ ĭ�� ������ ���� ���� 
//�밢�� ���⿡ �ִ� �ٱ��� ����ŭ r,c�� ���� ����
// => �밢�� �������� ��踦 ����� ���� X
// �ٱ��Ͽ� ����� ���� ���� 2 �̻��� ��� ĭ�� ������ �����, ���� ���� 2 �پ���.
// �̶� ������ ����� ĭ�� 3���� ������ ����� ĭ�� �ƴϾ�� �Ѵ�.

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