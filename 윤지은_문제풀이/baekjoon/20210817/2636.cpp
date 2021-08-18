#include <iostream>
#include <queue>

using namespace std;
int sero, garo;
int time, result;
int map[101][101];
int visited[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool cheese() {
	visited[0][0] = 1;
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	time++;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= garo || ny >= sero || visited[ny][nx] == 1) continue;
			if (map[ny][nx] == 0) q.push({ ny, nx });
			else {
				map[ny][nx] = 0;
				cnt++;
			}
			visited[ny][nx] = 1;
		}
	}

	// 이 전 치즈개수랑 시간
	if (cnt == 0) {
		cout << time - 1 << "\n" << result;
		return true;
	}
	// 치즈 개수
	else {
		result = cnt;
		return false;
	}

}
int main()
{
	cin >> sero >> garo;
	for (int y = 0; y < sero; y++) {
		for (int x = 0; x < garo; x++) {
			cin >> map[y][x];
		}
	}
	while (1) {
		if (cheese()) break;
		//// map 변화과정 확인
		//for (int y = 0; y < sero; y++) {
		//	for (int x = 0; x < garo; x++) {
		//		cout << map[y][x] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;

		// 다시 방문하기 위해
		for (int y = 0; y < sero; y++) {
			for (int x = 0; x < garo; x++) {
				visited[y][x] = 0;
			}
		}
	}
	
	return 0;
}