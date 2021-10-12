#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>

#define MAX 64

using namespace std;

int N, Q;
int map[MAX][MAX], temp[MAX][MAX];
bool melt[MAX][MAX], visited[MAX][MAX];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dfs(int y, int x) {
	visited[y][x] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (!visited[ny][nx] && map[ny][nx] > 0)
			ret += dfs(ny, nx);
	}
	return ret;
}

// 가장 큰 덩어리 찾기
int getBiggest() {
	int ret = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (map[y][x] > 0 && !visited[y][x])
				ret = max(ret, dfs(y, x));
	return ret;
}

// 얼음 합 반환
int getSum() {
	int ret = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			ret += map[y][x];
	return ret;
}

// 격자 시계방향 회전
void rotate(int y, int x, int L) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			temp[i][j] = map[y + L - 1 - j][x + i];
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			map[y + i][x + j] = temp[i][j];
}

void melting() {
	memset(melt, false, sizeof(melt));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (map[ny][nx] > 0) cnt++;
			}
			if (cnt < 3) melt[i][j] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (melt[i][j]) map[i][j]--;
		}
	}
}

int main() {
	cin >> N >> Q;
	N = pow(2, N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}			

	while (Q--) {
		int L; cin >> L;
		L = pow(2, L);

		// 회전
		for (int y = 0; y < N; y += L)
			for (int x = 0; x < N; x += L)
				rotate(y, x, L);

		// 얼음 융해
		melting();
	}

	cout << getSum() << '\n';
	cout << getBiggest() << '\n';

	return 0;
}