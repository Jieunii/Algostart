#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

char map[31][31] = {};
int m, n; //m이 높이, n이 폭
int cnt = -1;
int ans = 0;
int visited[31][31] = {};
int dir[4][2] = { {0,0}, {0,1},{1,0},{1,1} };
struct node {
	int y;
	int x;
};
//오른쪽, 아래, 오른쪽 대각선 아래만 확인
int isInside(int y, int x) {
	if (y < 0 || y >= m || x < 0 || x >= n)
		return 0;
	return 1;
}

void gravity() {
	for (int i = 0; i < n; i++) {
		for (int j = m-1; j > 0; j--) {
			if (map[j][i] == ' ') {
				for (int k = j - 1; k >= 0; k--) {
					if (map[k][i] != ' ') {
						map[j][i] = map[k][i];
						map[k][i] = ' ';
						break;
					}
				}
			}
		}
	}
}

void print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

}

int main() {

	vector<string> board = { "HGNHU", "CRSHV", "UKHVL", "MJHQB", "GSHOT", "MQMJJ", "AGJKK", "QULKK" };
	m = 8;
	n = 5;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = board[i][j];
		}
	}

	while (cnt != 0) {
		queue<node> temp;
		print();
		cout << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (isInside(i + 1, j + 1)) {
					if (map[i][j] != ' ') {
						if (map[i][j] == map[i + 1][j] && map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j + 1]) {
							temp.push({ i,j });
							visited[i][j]++;
							visited[i + 1][j]++;
							visited[i][j + 1]++;
							visited[i + 1][j + 1]++;
						}
					}
				}
			}
		}

		if (temp.empty()) cnt = 0;
		while (!temp.empty()) {
			int y = temp.front().y;
			int x = temp.front().x;
			temp.pop();

			for (int i = 0; i < 4; i++) {
				int dy = y + dir[i][0];
				int dx = x + dir[i][1];

				map[dy][dx] = ' ';
				ans++;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] > 1) {
					ans -= (visited[i][j] - 1);
				}
			}
		}

		gravity();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}

	}

	cout << ans << endl;

	
	return 0;
}