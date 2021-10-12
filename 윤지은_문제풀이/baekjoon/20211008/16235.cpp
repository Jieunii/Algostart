#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, K;
int cnt = 0;
int remainNutrient[11][11]; // 초기 양분 5 -> 남은 양분
int addNutrienet[11][11]; // 겨울에 추가되는 양분
int deathTree[11][11]; // 죽은 나무 양분
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<int> tree[11][11];

void spring() {
	memset(deathTree, 0, sizeof(deathTree));
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (tree[y][x].size()) {
				sort(tree[y][x].begin(), tree[y][x].end()); // 나이순 정렬
				vector<int> survivingTree;
				for (int i = 0; i < tree[y][x].size(); i++) {
					int age = tree[y][x][i];
					if (remainNutrient[y][x] >= age) { // 양분 >= 나이
						remainNutrient[y][x] -= age;
						survivingTree.push_back(tree[y][x][i] + 1); // 살아남은 나무
					}
					else { // 양분 < 나이
						deathTree[y][x] += (age / 2); // 죽은 나무
					}
				}
				tree[y][x].clear();
				tree[y][x] = survivingTree;
			}
		}
	}
}

void summer() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			remainNutrient[y][x] += deathTree[y][x];
		}
	}
}

void fall() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			for (int i = 0; i < tree[y][x].size(); i++) {
				if (tree[y][x][i] % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int ny = y + dy[d];
						int nx = x + dx[d];
						if (ny<1 || nx<1 || ny>N || nx>N) continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			remainNutrient[y][x] += addNutrienet[y][x];
		}
	}
}

int main() {
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			remainNutrient[y][x] = 5;
			cin >> addNutrienet[y][x];
		}
	}
	for (int i = 1; i <= M; i++) {
		int y, x, value;
		cin >> y >> x >> value;
		tree[y][x].push_back(value);
	}
	for (int i = 1; i <= K; i++) {
		spring();
		summer();
		fall();
		winter();
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cnt += tree[y][x].size();
		}
	}
	cout << cnt;
	return 0;
}