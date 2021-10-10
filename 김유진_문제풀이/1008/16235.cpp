
//나무 재테크
//: 나이대로 정렬하는데, 나이가 제일 작은게 들어오면 deque

#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

struct info {
	int x;
	int y;
	int age;
};

int n, m, k;
int A[11][11];
int map[11][11];
deque<info> q;
queue<info> dead;
bool cmp(info front, info back) {
	return front.age < back.age;
}
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void spring() {
	int len = q.size();
	for (int i = 0; i < len; i++) {
		int x = q.front().x;
		int y = q.front().y;
		int age = q.front().age;
		q.pop_front();

		if (map[x][y] >= age) {
			map[x][y] -= age;
			age += 1;
			q.push_back({ x, y, age });
		}
		else {
			dead.push({ x, y, age });
		}
	}
}

void summer() {
	while (!dead.empty()) {
		int x = dead.front().x;
		int y = dead.front().y;
		int age = dead.front().age;
		map[x][y] += age / 2;
		dead.pop();
	}
}

void fall() {
	queue<info> new_tree;
	int len = q.size();
	for (int i = 0; i < len; i++) {
		int x = q[i].x;
		int y = q[i].y;
		int age = q[i].age;

		if (age % 5 == 0) {
			for (int j = 0; j < 8; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
				new_tree.push({ nx, ny, 1});
			}
		}
	}

	while (!new_tree.empty()) {
		q.push_front({ new_tree.front().x, new_tree.front().y, new_tree.front().age });
		new_tree.pop();
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] += A[i][j];
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x = 0, y = 0, z = 0;
		cin >> x >> y >> z;
		q.push_back({x, y, z });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 5;
		}
	}

	sort(q.begin(), q.end(), cmp);

	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	int res = q.size();

	cout << res << "\n";

	return 0;
}