// 가로 n* 세로 m 그리고 블럭의 개수 m이 주어지고
// 현재 맵의 높이 상태가 주어질 때
// 평탄화 할 경우 가장 걸리는 시간이 적은 경우와 그때의 높이를 출력
// 땅을 팔 경우 2초가 소요되고, 블럭을 놓을 경우 1초가 소요된다.

/*
h 는 0~ 256 사이, 각 칸의 위치와 h를 비교하여 
블럭을 놓아야하는지 / 혹은 땅을 파야하는지 확인한다.
h 보다 map[y][x]의 위치가 낮다면, 블럭을 놓아야 하므로 place 의 개수를 증가시키고
h 보다 map[y][x]의 위치가 높다면, 땅을 파야하므로 destroy의 개수를 증가시킨다.

이후 맵을 전체 다 돌았다면
걸리는 시간을 계산하고 min_time과 비교하여 최소값이라면 이때의 시간과 높이를 기록해둔다.
*/

#include <iostream>

using namespace std;

int n, m, b; // 가로, 세로, 초기 블럭개수
int map[501][501];

int min_h = 256;
int max_h = 0;

void Input() {
	cin >> n >> m >> b;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			if (map[y][x] < min_h) { min_h = map[y][x]; }
			if (max_h < map[y][x]) { max_h = map[y][x]; }
		}
	}
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	int min_t = 21e8;
	int res_h = 0;
	
	// 각 높이로 평탄화 하는데 걸리는 시간의 최대 최소 구하기
	for (int h = min_h; h <= max_h; h++) {
		int place = 0; // 놓아야 하는 개수
		int destroy = 0; // 파야 하는 개수
		
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				int diff = map[y][x] - h;
				if (diff < 0) place += (-diff); // 음수라면 배치해야함
				else destroy += diff; // 양수라면 파야함
			}
		}
		// 부신 아이템만큼 추가됨
		if (destroy + b >= place) {
			int sec = place + 2 * destroy;
			if (min_t >= sec) { // 답이 같다면 그중 가장 높은걸 출력(높은쪽이 나중에 시도되므로)
				min_t = sec;
				res_h = h;
			}
		}
	}
	
	cout << min_t << " " << res_h;

	return 0;
}