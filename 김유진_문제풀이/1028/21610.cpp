//마법사 상어와 비바라기

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct cinfo {
	int y;
	int x;
};

struct info {
	int d;
	int s;
};

int A[51][51];
int c[51][51];
vector<cinfo> cloud;
vector<info> inst;
vector<cinfo> change;
int n, m;

int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int d = 0;
		int s = 0;
		cin >> d >> s;
		inst.push_back({ d,s });
	}
}

void cloud_move(int d, int s) {
	for (int i = 0; i < cloud.size(); i++) {
		int ny = cloud[i].y;
		int nx = cloud[i].x;

		//d방향으로 s칸이동
		for (int j = 1; j <= s; j++) {
			ny = ny + dy[d];
			nx = nx + dx[d];

			if (ny == n + 1) ny = 1;
			else if (ny == 0) ny = n;
			if (nx == n + 1) nx = 1;
			else if (nx == 0) nx = n;
		}

		//비 내리기
		c[ny][nx] = 1;
		A[ny][nx]++;
		change.push_back({ ny, nx });
	}

	//구름 사라지기
	cloud.clear();
}

void copy_bug() {
	//물이 증가한 칸 -> 물복사버그
	for (int i = 0; i < change.size(); i++) {
		int y = change[i].y;
		int x = change[i].x;

		//대각선에 물이있는 바구니수 cnt
		int cnt = 0;
		for (int j = 2; j <= 8; j += 2) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny <= 0 || nx <= 0 || ny > n || nx > n) continue;
			if (A[ny][nx] != 0) cnt++;
		}
		A[y][x] += cnt;
	}

	change.clear();
}

void cloud_create() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i][j] >= 2 && c[i][j] != 1) {
				cloud.push_back({ i, j });
				A[i][j] -= 2;
			}
		}
	}

	memset(c, 0, sizeof(c));
}

void move() {
	for (int i = 0; i < m; i++) {
		int d = inst[i].d;
		int s = inst[i].s;

		cloud_move(d, s);
		copy_bug();
		cloud_create();

	}
}

int main() {

	input();

	//비바라기 시전
	cloud.push_back({ n,1 });
	cloud.push_back({ n,2 });
	cloud.push_back({ n - 1,1 });
	cloud.push_back({ n - 1,2 });

	move();

	//output
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res += A[i][j];
		}
	}
	cout << res << "\n";
	return 0;
}