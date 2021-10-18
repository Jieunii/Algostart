//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <queue>
//#include <string>
//using namespace std;
//
//char map[5][5] = {};
//int visited[5][5] = {};
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//struct Node {
//	int y, x;
//};
//
//int isInside(int y, int x) {
//	if (y < 0 || y >= 5 || x < 0 || x >= 5) return 0;
//	return 1;
//}
//int bfs(int start_y, int start_x, int des_y, int des_x, int r ) {
//	queue<Node> que;
//	que.push({ start_y,start_x });
//	visited[start_y][start_x] = 1;
//	
//	int flag = 0;
//	while (!que.empty()) {
//		start_y = que.front().y;
//		start_x = que.front().x;
//		que.pop();
//
//		if (start_y == des_y && start_x == des_x) {
//			flag = 1;
//			break;
//		}
//		for (int i = 0; i < 4; i++) {
//			int ny = start_y + dir[i][0];
//			int nx = start_x + dir[i][1];
//
//			if (visited[ny][nx] != 0 || !isInside(ny, nx)) continue;
//			if (map[ny][nx] != 'X') {
//				visited[ny][nx] = visited[start_y][start_x] + 1;
//				que.push({ ny,nx });
//			}
//		}
//	}
//
/	if (visited[des_y][des_x]==r+1)
		return 1;
	else if(visited[des_y][des_x] == 0 || visited[des_y][des_x] > r+1)
		return 0;
//}
//
//int main() {
//
//	vector<vector<string>> places =
//	{ {"PXOOO", "OOOOO", "PXOOO", "OOOOO", "OOOPO"},
//	{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
//	{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
//	{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
//	{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
//
//	vector<int> answer;
//	vector<Node> vec;
//	// °¡´Â ±æ¿¡ X°¡ ÀÖÀ¸¸é ±¦Âú
//	for (int i = 0; i < places.size(); i++) {
//		vec.clear();
//		for (int j = 0; j < places[i].size(); j++) {
//			for (int k = 0; k < places[i][j].length(); k++) {
//				if (places[i][j][k] == 'P') vec.push_back({ j,k });
//				map[j][k] = places[i][j][k];
//			}
//		}
//		int flag = 0;
//
//		if (!vec.empty()) {
//			for (int j = 0; j < vec.size() - 1; j++) {
//				if (flag) break;
//				int start_y = vec[j].y;
//				int start_x = vec[j].x;
//				for (int k = j + 1; k < vec.size(); k++) {
//					int des_y = vec[k].y;
//					int des_x = vec[k].x;
//					memset(visited, 0, sizeof(visited));
//					int r = abs(start_y - des_y) + abs(start_x - des_x);
//					if (r <= 2) {
//						int ret = bfs(start_y, start_x, des_y, des_x, r);
//						if (ret) flag = 1;
//					}
//				}
//			}
//
//			if (flag) answer.push_back(0);
//			else answer.push_back(1);
//		}
//		else answer.push_back(1);
//	}
//	for (int x : answer) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
