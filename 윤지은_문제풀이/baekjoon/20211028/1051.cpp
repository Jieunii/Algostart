#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int map[51][51];

int square() {
	int result = 1;

	for (int y = 0; y < N; y++)	{
		for (int x = 0; x < M; x++) {
			for (int k = 1; k < min(N, M); k++)	{
				if (y + k < N && x + k < M && map[y + k][x] == map[y][x] && map[y + k][x + k] == map[y][x] && map[y][x + k] == map[y][x]) result = max(result, k + 1);
			}
		}
	}
	return result * result;
}

int main() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		string tmp;
		cin >> tmp;
		for (int x = 0; x < M; x++) {
			map[y][x] = tmp[x] - '0';
		}
	}
	
	cout << square();
	return 0;
}
