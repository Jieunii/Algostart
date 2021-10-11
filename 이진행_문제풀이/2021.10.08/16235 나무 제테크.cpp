/*
비료맵 N*N
M개의 나무개수
K년도가 주어짐
이후 봄, 여름, 가을, 겨울을 반복하며 나무의 생명주기가 반복됨
K 년이 지났을 때, 나무의 개수를 구하는 문제

봄 - 양분을 먹고 나무 크기 증가
여름 - 죽은 나무가 양분이됨
가을 - 8방향으로 씨 뿌림
겨울 - 비료뿌림

풀이)
구현문제?
배열을 쓸지 벡터를 쓸지, 언제 정렬을 할 것인지 중요
x,y좌표로 주어지는지 y,x좌표로 주어지는지 잘 볼것!

가을 겨울은 쉽지만,
봄 여름이 어려움
따로 death를 계산해서 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int farm[11][11]; // 현재 농장에 뿌려진 양분 상태를 저장하는 배열
int fertilizer[11][11]; // 매년 뿌릴 양분의 정보
vector<int> tree[11][11]; // 나무 정보를 저장하는 벡터 

int direct[8][2] = { -1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1 };

void Input() {
	cin >> N >> M >> K;

    // 매년 뿌릴 양분 정보 저장
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> fertilizer[y][x];
		}
	}

	for (int i = 0; i < M; i++) {
		int y, x, age;
		cin >> y >> x >> age;
		tree[y-1][x-1].push_back(age);
	}
}

// 자신의 나이만큼 양분을 먹고 나이가 1증가.
// 자신의 칸에 있는 양분만 먹을 수 있음.
// 여러개의 나무가 있따면 어린 나무부터 양분을 먹는다
// 양분이 부족해 먹을 수 없으면 나무는 죽는다
// 
// 봄에 죽은 나무가 양분이 된다. 
// 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다
void SpringAndSummer() {

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (tree[y][x].size() == 0) continue;

			sort(tree[y][x].begin(), tree[y][x].end(), less<int>());

			vector<int> temp;
			int death = 0;

			for (int i = 0; i < tree[y][x].size(); i++) {
				int cur_tree = tree[y][x][i];

				// 현재 양분이 있다면
				if (farm[y][x] >= cur_tree) { // 양분을 먹고 성장
					temp.push_back(cur_tree + 1);  
					farm[y][x] -= cur_tree; 
				}
				// 양분이 없다면 죽음
				else {
					death += cur_tree / 2;
				}
			}

			farm[y][x] += death; // 여름이 되어 양분을 추가한다
			tree[y][x].clear();
			
			tree[y][x].assign(temp.begin(), temp.end()); // temp 내용을 tree[y][x]에 덮어쓰기
		}
	}
}

// 나무가 번식한다. 
// 나이가 5의 배수이고, 인접한 칸에 나이가 1인 나무가 생긴다. 
void Fall() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (tree[y][x].size() == 0) continue;			
			for (int i = 0; i < tree[y][x].size(); i++) {
				if ((tree[y][x][i] % 5) == 0) { // 5배수면
					// 8방향으로 나무 심기 
					for (int t = 0; t < 8; t++) {
						int dy = y + direct[t][0];
						int dx = x + direct[t][1];

						if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;

						tree[dy][dx].push_back(1); 
					}
				}
			}

		}
	}
}

// 땅을 돌아다니며 양분을 다시 추가한다
void Winter() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			farm[y][x] += fertilizer[y][x];
		}
	}
}

// 전체 나무 세기
int CountingTrees() {
	int ret = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			ret += tree[y][x].size();
		}
	}

	return ret;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	Input();

	// 첫 양분 공급 및 나무 오름차순 
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			farm[y][x] = 5;
		}
	}

	while (K--) {
		SpringAndSummer();

		Fall();

		Winter();
	}
	
	cout << CountingTrees();

	return 0;
}