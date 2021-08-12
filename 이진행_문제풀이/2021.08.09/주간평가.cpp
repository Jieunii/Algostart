#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, k;
int map[17][17];
int cnt = 0;

// 8방향 대신 →,↘,↓,↙만 체크한다
// 어짜피 중복되기 때문
int directY[4] = { 0, 1, 1, 1 };
int directX[4] = { 1, 1, 0,-1 };

// y,x에 돌을 놓음
void placeStone(int y, int x, int stone) {
	map[y][x] = stone;
	cnt++;
}


// 전체 맵을 돌며 k개가 이어져있는지 확인
bool checkWin(int stone) {

	for (int y = 0; y < 17; y++) {
		for (int x = 0; x < 17; x++) {
			
			// 현재위치부터 연결된 k개가 있는지 확인
			if (map[y][x] == stone) {

				bool flag = 0;
				for (int i = 0; i < 4; i++) {
					int dy = y + directY[i];
					int dx = x + directX[i];

					if (dy < 0 || dx < 0 || dy >= 17 || dx >= 17) continue;

					if(map[dy][dx] == stone){
						int combo = 1;
						while (1) {
							if (map[dy][dx] == stone) {
								combo++;
								if (combo == k) { return true; }

								dy = dy + directY[i];
								dx = dx + directX[i];

								if (dy < 0 || dx < 0 || dy >= 17 || dx >= 17) break;
							}
							else {
								break;
							}
						}
					}
				}
			}
		}
	}

	return false;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> m >> k;

	queue< pair<int, int> > sedol;
	int y, x;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		sedol.push(make_pair(y, x));
	}

	queue< pair<int, int> > gamma;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		gamma.push(make_pair(y, x));
	}

	int flag = 0;
	while (!sedol.empty() && !gamma.empty()) {
		pair<int,int> now = sedol.front();
		sedol.pop();

		placeStone(now.first, now.second, 1);

		if (checkWin(1)) {
			flag = 1;
			break;
		};

		now = gamma.front();
		gamma.pop();

		placeStone(now.first, now.second, 2);

		if (checkWin(2)) {
			flag = 2;
			break;
		};
	}

	if (flag == 1) {
		cout << cnt << endl << "세돌" << endl;
	}
	else if (flag == 2){
		cout << cnt << endl << "감마고" << endl;
	}
	else {
		cout << 0 << endl;
	}
	
	return 0;
}

/*
7 4
1 2
2 3
2 4
2 2
4 2
3 3
5 1
1 4
3 4
2 5
2 1
3 2
1 5
9 9
*/