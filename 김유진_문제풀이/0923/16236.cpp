/*

//아기상어

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int y;
	int x;
	int cnt;
};
int n;
int baby_x = 0;
int baby_y = 0;
int baby_size = 2;
int eat_cnt = 0;
int result;
int map[21][21];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool cmp(info front, info back){
	if (back.cnt > front.cnt) return true;
	else if (back.cnt < front.cnt) return false;
	else {
		if (back.y > front.y) return true;
		else if (back.y < front.y) return false;
		else {
			return back.x > front.x;
		}
	}
}

vector<info> eat;

void find_near_fish() {
	//eat init
	while (!eat.empty()) {
		eat.pop_back();
	}
	queue<info> q;
	int visited[21][21] = {0,};

	q.push({ baby_y, baby_x, 0 });
	visited[baby_y][baby_x] = 1;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int c = q.front().cnt;
		q.pop();

		//먹을 수 있다면 
		if (map[y][x] != 0 && baby_size > map[y][x]) {
			eat.push_back({ y, x, c});
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//선을 넘는다면 
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			//방문했던곳이면
			if (visited[ny][nx] == 1) continue;
			//아기상어 크기 < 물고기 크기
			if (baby_size < map[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx, c + 1 });

		}
	}
}

int main() {

	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				baby_size = 2;
				baby_y = i;
				baby_x = j;
				map[i][j] = 0;
			}
		}
	}

	while (1) {
		find_near_fish();

		if (eat.empty()) break;
		else {
			//가까운, 위, 왼쪽부터 먹는다 
			sort(eat.begin(), eat.end(), cmp);
			map[eat[0].y][eat[0].x] = 0;
			eat_cnt++;
			if (eat_cnt == baby_size) {
				baby_size++;
				eat_cnt = 0;
			}
			result += eat[0].cnt;
			baby_y = eat[0].y;
			baby_x = eat[0].x;
		}

	}

	cout << result << endl;

	return 0;
}

*/