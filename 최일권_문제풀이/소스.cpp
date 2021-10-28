//#include <iostream>
//#include <queue>
//using namespace std;
//
//int map[51][51] = {};
//int visited[51][51] = {};
//int caught[3] = {};
//int N;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//struct Node {
//	int y, x;
//	int cnt;
//};
//
//int isInside(int y, int x) {
//	if (y < 0 || y >= N || x < 0 || x >= N) return 0;
//	return 1;
//}
//
//void move(int y, int x) {
//
//	queue<Node> que;
//	que.push({ y,x,0 });
//	
//	while (!que.empty()) {
//		memset(visited, 0, sizeof(visited));
//		y = que.front().y;
//		x = que.front().x;
//		int cnt = que.front().cnt;
//		visited[y][x] = 1;
//		que.pop();
//
//		if (cnt == 3) break;
//
//		for (int i = 0; i < 4; i++) {
//			int ny = y + dir[i][0];
//			int nx = x + dir[i][1];
//
//			if (!isInside(ny, nx) || visited[ny][nx]==1) continue;
//			int c_flag = 0;
//			int cant = 0;
//			while (1) {
//				int flag = 0;
//				if (c_flag == 1) break;
//				if (cant == 1) break;
//				if (!isInside(ny, nx)) break;
//				if (map[ny][nx] != 0) flag = 1;
//
//				if (flag) {
//					while (1) {
//						ny += dir[i][0];
//						nx += dir[i][1];
//
//						if (c_flag) break;
//						if (!isInside(ny, nx)) break;
//						if (map[ny][nx] == cnt+4) {
//							cant = 1;
//							break;
//						}
//						if (map[ny][nx] == 1) {
//							caught[cnt]++; 
//							map[ny][nx] = cnt+5;
//							c_flag = 1;
//						}
//						que.push({ ny,nx,cnt+1 });
//					}
//				}
//				else {
//					ny += dir[i][0];
//					nx += dir[i][1];
//				}
//			}
//		}
//	}
//}
//
//
//int main() {
//	
//	freopen("sample_input.txt", "r", stdin);
//	int tc;
//	cin >> tc;
//	
//	int k = 1;
//
//	while (tc--) {
//
//		int p_y, p_x;
//		cin >> N;
//
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> map[i][j];
//
//				if (map[i][j] == 2) {
//					p_y = i;
//					p_x = j;
//				}
//			}
//		}
//		memset(visited, 0, sizeof(visited));
//		memset(caught, 0, sizeof(caught));
//
//		move(p_y, p_x);
//
//		int ans = 0;
//		for (int i = 0; i < 3; i++) {
//			ans += caught[i];
//		}
//	
//
//		printf("#%d %d\n",k++,ans);
//	}
//
//	
//
//	return 0;
//}