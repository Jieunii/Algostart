#include<iostream>
using namespace std;

int x, y, d, g;
int N;
int answer, curve_size;
int curve[1025];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int map[101][101];

void make_map(int x, int y) {
	for (int i = 0; i < curve_size; i++) {
		x += dx[curve[i]];
		y += dy[curve[i]];
		if (x > -1 && x < 101 && y> -1 && y < 101)
			map[y][x] = 1;
	}

}

void make_curve(int d, int g) {
	curve_size = 0;
	curve[curve_size++] = d;
	for (int i = 0; i < g; i++) {
		for (int j = curve_size - 1; j >= 0; j--) {
			curve[curve_size++] = (curve[j] + 1) % 4; // 역순에 +1
		}
	}
}

int main() {
	cin >> N;

	for (int n = 0; n < N; n++) {
		cin >> x >> y >> d >> g;
		make_curve(d, g);
		make_map(x, y);
		map[y][x] = 1;
	}

	// count curve
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x] == 1 && map[y + 1][x] == 1 && map[y][x + 1] == 1 && map[y + 1][x + 1] == 1)
				answer++;
		}
	}
	cout << answer;
}