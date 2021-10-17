//거리두기 확인하기
// dfs로 두칸까지만 확인 위위, 아래왼쪽, 왼쪽위 등등
// 사람있으면 flag = 1해서 다종료시키고 answer에 0집어넣음

#include <string>
#include <vector>
#include <string.h>
using namespace std;

vector<string> classs;
int visited[5][5];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { -1,1,0,0 };
int flag = 0;

void dfs(int y, int x, int depth) {
	if (depth == 2) {
		if (classs[y][x] == 'P') {
			flag = 1;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		if (visited[ny][nx] == 1) continue;
		if (classs[ny][nx] == 'X') continue;
		if (classs[ny][nx] == 'P') {
			flag = 1;
			return;
		}
		visited[ny][nx] = 1;
		dfs(ny, nx, depth + 1);
	}
}

void check() {
	flag = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			memset(visited, NULL, sizeof(visited));
			if (classs[y][x] == 'P') {
				visited[y][x] = 1;
				dfs(y, x, 0);
				if (flag == 1) break;
			}
		}
	}
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < places.size(); i++) {
		classs = places[i];
		check();
		if (flag == 1) {
			answer.push_back(0);
		}
		else {
			answer.push_back(1);
		}
	}

	return answer;
}