#include <iostream>
using namespace std;

int h, w, res;
int tmp_h;
int map[501][501];

int main() {

	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> tmp_h;
		for (int j = 0; j < tmp_h; j++) {
			map[j][i] = 1;
		}
	}

	for (int i = 0; i < h; i++) {
		int flag = 0;
		int cnt = 0;
		for (int j = 0; j < w; j++) {
			if (flag == 0 && map[i][j] == 1) { //¿­¸°
				flag = 1;
			}
			else if (flag == 1 && map[i][j] == 0) { //ºóÄ­
				cnt++;
			}
			else if (flag == 1 && map[i][j] == 1) {//´ÝÈù
				res += cnt;
				cnt = 0;
			}
		}
	}

	cout << res;
	return 0;
}