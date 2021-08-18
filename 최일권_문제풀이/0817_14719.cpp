#include <iostream>

using namespace std;

int map[501][501] = {};
int H, W;
int water = 0;


int main() {

	cin >> H >> W;

	for (int i = 1; i <= W; i++) {
		int high;
		int k = H;
		cin >> high;

		for (int j = 0; j < high; j++)
		{
			map[k--][i] = 1;
		}
	}

	
	for (int i = 1; i <= H; i++) {
		int st_idx = -1;
		int en_idx = -1;
		for (int j = 1; j <= W; j++) {
			if (map[i][j] == 1) {
				if (st_idx != -1) {
					en_idx = j;
				}
				else {
					st_idx = j;
				}
			}
			if (st_idx == en_idx) {
				continue;
			}
			for (int j = st_idx; j <= en_idx; j++) {
				if(map[i][j]!=1)
					map[i][j] = 2;
			}
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] == 2)
				water++;
		}	
	}

	cout << water << endl;

	return 0;
}