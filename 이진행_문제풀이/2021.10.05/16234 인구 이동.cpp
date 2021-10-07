/*
매일 y,x에서 dfs를 통해 인구 이동이 가능한지 확인
dfs에 변경된 값들을 map에 저장.
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, L, R;
int map[52][52];
int visited[52][52];
int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };
int cnt, sum;
int day = 0;
vector< pair<int, int> > vect;

void Input() {
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void DFS(int y, int x) {
	for (int t = 0; t < 4; t++) {
		int dy = y + direct[t][0];
		int dx = x + direct[t][1];

		if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue; // 경계 처리
		if (visited[dy][dx] == 1) continue; // 이미 방문한곳
        // 두 지점의 차이가 L<=x <=R이 아닌경우 패스
		if (abs(map[y][x] - map[dy][dx]) < L || R < abs(map[y][x] - map[dy][dx])) continue; 

        // 연합에 추가하고 그 지점으로부터 다시 DFS
		visited[dy][dx] = 1;
		cnt++;
		sum += map[dy][dx];
		vect.push_back({ dy,dx });
		DFS(dy, dx); 
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();
	
	while (1) {
		bool flag = false; // 종료 플래그
		memset(visited, 0, sizeof(visited));

        // 매일 전체 맵을 돌면서 확인한다
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (visited[y][x] == 1) continue;

				vect.clear();

				// y,x 
				cnt = 1;
				sum = map[y][x];
				visited[y][x] = 1;

				vect.push_back({ y, x });
				DFS(y, x);

				// cnt가 2 이상이라면 연합의 크기가 2 이상이므로, 이주가 발생함
				if (cnt >= 2) { 
					flag = true;
					int avg = sum / cnt;
					for (int i = 0; i < vect.size(); i++) {
						int dy = vect[i].first;
						int dx = vect[i].second;
						map[dy][dx] = avg;
					}
				}
			}
		}
		if (flag == false) break;
		else day++;
	}
	cout << day;
	return 0;
}