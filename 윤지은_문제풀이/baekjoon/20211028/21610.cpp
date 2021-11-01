#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int answer = 0;
queue<pair<int, int>> q;
vector<vector<int>> board(51, vector<int>(51, 0));
int directX[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int directY[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int main(void) {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	q.push(make_pair(N, 1));
	q.push(make_pair(N, 2));
	q.push(make_pair(N - 1, 1));
	q.push(make_pair(N - 1, 2));

	while (M--) {
		int d, s, size;
		vector<vector<bool>> visited(51, vector<bool>(51, false)); // 방문 여부
		vector<pair<int, int>> v; // 비가 내린 곳 위치
		cin >> d >> s;
		size = q.size();

		//구름 이동(d의 방향으로 s만큼)
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int j = 0; j < s; j++) {
				x += directX[d];
				y += directY[d];

				if (x == 0) x = N;
				else if (x > N) x = 1;

				if (y == 0) y = N;
				else if (y > N) y = 1;
			}

			board[x][y]++;
			visited[x][y] = true;
			v.push_back(make_pair(x, y));
		}

		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;

			//물복사버그 시전
			for (int j = 2; j <= 8; j += 2) {
				int nx = x + directX[j];
				int ny = y + directY[j];

				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && board[nx][ny] >= 1) {
					board[x][y]++;
				}
			}
		}

		//구름 생성
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] >= 2 && !visited[i][j]) {
					q.push(make_pair(i, j));
					board[i][j] -= 2;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] > 0) {
				answer += board[i][j];
			}
		}
	}

	cout << answer;

	return 0;
}