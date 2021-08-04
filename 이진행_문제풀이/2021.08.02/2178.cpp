/*
몇번만에 도달했는지까지는 출력했는데

최소값 찾는 방법에서 시간초과가 남!!

???
*/


#include <iostream>
#include <vector>

using namespace std;

// ↓, →, ↑, ← 순
int directY[4] = {1,0,-1,0};
int directX[4] = { 0,1,0,-1 };
int n, m;
int cnt = 0;

int used[100][100];

struct pos {
	int y;
	int x;
};

void run(int nowY, int nowX, vector< vector<int> >map) {
	cnt++;
	// 바닥조건 : 목적지에 도착한 경우
	if (nowY == n - 1 && nowX == m - 1) {
		cout << cnt <<"번만에 성공!" << endl;
		return;
	}
	// 4방향으로 시도
	for (int i = 0; i < 4; i++) {
		int yy = nowY + directY[i];
		int xx = nowX + directX[i];

		if (yy < 0 || xx < 0 || yy > n - 1 || xx > m - 1) { continue; } // 맵밖으로 나간경우
		if (map[yy][xx] == 0) continue;	// 벽인경우
		if (used[yy][xx]) continue;	// 이미 방문한경우

		used[yy][xx] = 1;
		
		run(yy, xx, map);

		used[yy][xx] = 0;

	}
}


int main() {

	cin >> n >> m;

	vector< vector<int> > map(n, vector<int>(m));

	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			cin >> map[y][x];
		}
	}
	
	//(0,0)에서 출발하여
	//(N-1,M-1)에 도달할때까지 지나야하는 최소 칸 수를 구하는 프로그램?
	
	used[0][0] = 1;
	run(0, 0, map);

	return 0;
}