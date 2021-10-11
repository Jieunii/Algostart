/*
N, Q가 주어지고
2^N * 2^N개의 각 칸에 있는 얼음의 양이 주어짐.
Q개의 파이어스톰 단계 L이 주어질 때,

마지막 스펠을 시전한 뒤 얼음 전체 합과 가장 큰 얼음의 크기 구하기.

풀이)

1. 격자로 나누어 회전 -> 구현
2. 인접칸 얼음이 3개 이하라면 얼음의 양이 1 줄어듬 -> 4방향 체크 
3. 1-2를 Q번 반복  
4. 전체 얼음 크기와 가장 큰 얼음 덩어리 크기 -> BFS 
*/

#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>

using namespace std;

int N, Q;
int map[64][64];
int temp[64][64], temp2[64][64];
int casting[1005];

int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };

void Input() {
	int size;
	cin >> size >> Q;
	N = pow(2, size);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	
	for (int i = 0; i < Q; i++) {
		cin >> casting[i];
	}

}

// 시작지점 (yy,xx)과 격자 크기를 받아 회전
void Rotate(int yy, int xx, int grid_size) {
	memset(temp, 0, sizeof(temp));
	memset(temp2, 0, sizeof(temp));
	// 원본 복사
	for (int y = 0; y < grid_size; y++) {
		for (int x = 0; x < grid_size; x++) {
			temp[y][x] = map[yy + y][xx + x];
		}
	}
	// temp2에 90도 회전 저장
	for (int y = 0; y < grid_size; y++) {
		for (int x = 0; x < grid_size; x++) {
			temp2[y][x] = temp[(grid_size-1) - x][y];
		}
	}
	// map에 덮어쓰기
	for (int y = 0; y < grid_size; y++) {
		for (int x = 0; x < grid_size; x++) {
			map[yy + y][xx + x] = temp2[y][x];
		}
	}
}

// 토네이도
void Tornado(int Lv) {
	int grid_size = pow(2, Lv);
	for (int y = 0; y < N - Lv; y = y + grid_size) {
		for (int x = 0; x < N - Lv; x = x + grid_size) {

			Rotate(y, x, grid_size);

		}
	}
}

// 녹이기
void Melting() {
	memset(temp, 0, sizeof(temp));
	for (int y = 0; y < N; y++) {
		for(int x=0; x<N; x++){
			if (map[y][x] == 0) continue;
			

			int cnt = 0;
			for (int t = 0; t < 4; t++) {
				int dy = y + direct[t][0];
				int dx = x + direct[t][1];

				if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue; // 경계 처리
				if (map[dy][dx] == 0) continue;

				// map[dy][dx]에 얼음이 있는 경우
				cnt++;
			}

			if (cnt < 3) { // 주위의 얼음이 3개보다 적은경우 녹음.
				// 다른칸도 계산을 위해 일단 temp에 복사해놓고, 끝에 map에 일괄적용함
				temp[y][x] = -1;
			}
		}
	}

	// map에 덮어쓰기
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] += temp[y][x];
		}
	}
}

// 가장 큰 얼음찾기(BFS)
int FindIceBlock() {
	memset(temp, 0, sizeof(temp)); // visited로 사용

	int max_block_size = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 0) continue;

			int block_size = 0;
			queue< pair<int, int> > qu;
			qu.push({ y,x });
			temp[y][x] = 1;

			while (!qu.empty()) {
				pair<int, int> now = qu.front();
				qu.pop();

				block_size++;

				for (int t = 0; t < 4; t++) {
					int dy = now.first + direct[t][0];
					int dx = now.second + direct[t][1];

					if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
					if (map[dy][dx] == 0) continue;
					if (temp[dy][dx] == 1) continue;

					temp[dy][dx] = 1;
					qu.push({ dy, dx });
				}
			}

			if (block_size > max_block_size) max_block_size = block_size;
		}
	}

	return max_block_size;
}

// 남은 얼음 카운팅
int CountIce() {
	int ret = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			ret += map[y][x];
		}
	}
	return ret;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	
	Input();

	for (int i = 0; i < Q; i++) {
		int casting_level = casting[i];
		Tornado(casting_level);

		Melting();
	}

	cout << CountIce() << endl;
	cout << FindIceBlock() << endl;
	
	return 0;
}