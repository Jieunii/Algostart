#include <iostream>
#include <vector>

using namespace std;

int N, x, y, d, g;
int map[102][102];
int directY[4] = {0,-1,  0, 1};
int directX[4] = {1, 0, -1, 0};

vector<int> dir_info;

// 드래곤 커브 함수
// 끝점을 기준으로 계속 그린다
void DragonCurve() {
	int size = dir_info.size();

	for (int i = size - 1; i >= 0; i--)
	{
		int nd = (dir_info[i] + 1) % 4;
		y += directY[nd];
		x += directX[nd];
		map[y][x] = 1;
		dir_info.push_back(nd);
	}
}

int CountSquare() {
	int cnt = 0;
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (map[y][x] == 0) continue;
			if (map[y][x] && map[y+1][x] && map[y][x+1] && map[y+1][x+1] ) {
				cnt++;
			}
		}
	}
	return cnt++;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> x >> y >> d >> g;

		dir_info.clear();

		// 0세대
		map[y][x] = 1;
		
		// 끝점을 기준으로 계속 그린다
		y = y + directY[d];
		x = x + directX[d];

		map[y][x] = 1;

		// 이후 g세대까지 반복
		dir_info.push_back(d); 
		for (int i = 0; i < g; i++) {
			DragonCurve();
		}
	}
	cout << CountSquare();

	return 0;
}