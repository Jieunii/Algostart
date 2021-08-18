#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, M;
int result = 21e8;
int map[9][9];
int rotation[6] = { 0, 4, 2, 4, 4, 1 };
// y, x, type
vector<pair<pair<int, int>, int>> v;

// 북 : 0, 동 : 1, 남 : 2, 서 : 3
void dir_cctv(int dir, int y, int x) {
	dir = dir % 4;
	if (dir == 0) {
		for (int i = y - 1; i >= 0; i--) {
			if (map[i][x] == 6) break;
			map[i][x] = -1;
		}
	}
	else if (dir == 1) {
		for (int i = x + 1; i < M; i++) {
			if (map[y][i] == 6) break;
			map[y][i] = -1;
		}
	}
	else if (dir == 2) {
		for (int i = y + 1; i < N; i++) {
			if (map[i][x] == 6) break;
			map[i][x] = -1;
		}
	}
	else if (dir == 3) {
		for (int i = x - 1; i >= 0; i--) {
			if (map[y][i] == 6) break;
			map[y][i] = -1;
		}
	}
}

void CCTV(int cnt) {
	int map_copy[9][9]; // 단계마다 복사
	if (cnt == v.size()) {
    // 사각지대 개수
		int blind_spot = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] == 0) blind_spot++;
			}
		}
		if (blind_spot < result) result = blind_spot;
		return;
	}
  
	memcpy(map_copy, map, sizeof(map));
	int y = v[cnt].first.first;
	int x = v[cnt].first.second;
	int type = v[cnt].second;
	for (int i = 0; i < rotation[type]; i++) {
		if (type == 1) {
			dir_cctv(i, y, x);
		}
		else if (type == 2) {
			dir_cctv(i, y, x);
			dir_cctv(i + 2, y, x);
		}
		else if (type == 3) {
			dir_cctv(i, y, x);
			dir_cctv(i + 1, y, x);
		}
		else if (type == 4) {
			dir_cctv(i, y, x);
			dir_cctv(i + 1, y, x);
			dir_cctv(i + 3, y, x);
		}
		else if (type == 5) {
			dir_cctv(i, y, x);
			dir_cctv(i + 1, y, x);
			dir_cctv(i + 2, y, x);
			dir_cctv(i + 3, y, x);
		}
		CCTV(cnt + 1);
		memcpy(map, map_copy, sizeof(map));
	}
}
int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (1 <= map[y][x] && map[y][x] <= 5) v.push_back(make_pair(make_pair(y, x), map[y][x]));
		}
	}

	CCTV(0);
	cout << result;
	return 0;
}