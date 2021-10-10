//마법사상어와 파이어스톰
#include <iostream>
#include <vector>
#include <queue>
#include <math.h> //pow
using namespace std;

int n, q;
int s; //pow(2, n) 시간 오래걸림
int ice[65][65];
queue<int> lev;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt, max_cnt = 0;
int visited[65][65] = { 0, };

void rotation(int y, int x, int l) {
	int tmp[65][65] = { 0, };
	int size = pow(2, l);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tmp[j+y][size - 1 - i + x] = ice[i+y][j+x];
		}
	}

	//ice <- tmp 복사
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			ice[i][j] = tmp[i][j];
		}
	}
}

void divide() {
	int l = lev.front();
	lev.pop();
	int size = pow(2, l);
	for (int y = 0; y < s; y += size) {
		for (int x = 0; x < s; x += size) {
			rotation(y, x, l);
		}
	}
}

void melting() {
	int tmp[65][65] = { 0, };
	for (int y = 0; y < s; y++) {
		for (int x = 0; x < s; x++) {
			int ice_cnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= s || nx >= s) continue;
				if (ice[ny][nx] > 0) ice_cnt++;
			}
			if (ice_cnt < 3 && ice[y][x] != 0) tmp[y][x] = ice[y][x] - 1;
			else tmp[y][x] = ice[y][x];
		}
	}

	for (int y = 0; y < s; y++) {
		for (int x = 0; x < s; x++) {
			ice[y][x] = tmp[y][x];
		}
	}
}

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= s || nx >= s) continue;
		if (visited[ny][nx] == 1) continue;
		if (ice[ny][nx] <= 0) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
		cnt++;
	}
	
}

int main() {

	cin >> n >> q;
	s = pow(2, n);
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			cin >> ice[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		int level = 0;
		cin >> level;
		lev.push(level);
	}

	for (int i = 0; i < q; i++) {
		divide();
		melting();
	}

	//남아있는 얼음합
	int ice_sum = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (ice[i][j] > 0) ice_sum += ice[i][j];
		}
	}

	//남은 얼음중 가장 큰 덩어리
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (!visited[i][j] && ice[i][j] != 0) {
				cnt = 1;
				visited[i][j] = 1;
				dfs(i ,j);
			}

			if (max_cnt < cnt) max_cnt = cnt;
		}
	}
	

	cout << ice_sum << "\n";
	cout << max_cnt << "\n";

	return 0;
}