#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int arr[51][51] = {};

int main() {

	cin >> N >> M;

	int ans = 1;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < M; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}


	for (int y = 0; y < N; y++) {

		for (int x = 0; x < M; x++) {

			for (int k = 1; k < min(N, M); k++) {
				if (x + k >= M || y + k >= N) continue;
				if (arr[y][x] == arr[y][x + k] && arr[y][x]==arr[y+k][x] && arr[y][x+k] == arr[y+k][x+k] &&arr[y+k][x]==arr[y+k][x+k]) {
					if (ans < (k + 1) *(k + 1)) ans = ((k+1) * (k+1));
				}
			}
			
		}
		
	}

	cout << ans << endl;
	return 0;
}