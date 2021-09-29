#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int N;
int map[101][101] = {};
int ans = 0;
int isInside(int y, int x) {
	if (y < 0 || y>100 || x < 0 || x>100)
		return 0;
	return 1;
}
int main() {

	//0 오른쪽
	//1 위쪽
	//2 왼쪽
	//3 아래

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int x, y, d, g;
		vector<int> ge;

		cin >> x >> y >> d >> g;
		map[y][x] = 1;

		ge.push_back(d);
		for (int j = 1; j <= g; j++) {
			for (int k = ge.size() - 1; k >= 0; k--) {
				ge.push_back((ge[k] + 1) % 4);
			}
		}

		for (int j = 0; j < ge.size(); j++)
		{
			y = y + dir[ge[j]][0];
			x = x + dir[ge[j]][1];
			map[y][x] = 1;
		}


	}
	//오른쪽, 아래, 오른쪽 아래 확인 4개면 ++
	
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1 && isInside(i+1,j+1)) {
				if (map[i + 1][j] && map[i + 1][j + 1] && map[i][j + 1])
					ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}