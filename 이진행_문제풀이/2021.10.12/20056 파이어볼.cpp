/*
N*N개의 격자에 M개의 파이어볼 위치가 주어짐
K번의 이동 이후의 파이어볼의 질량을 구하는 문제

파이어볼은 y,x좌표, 질량 m, 방향 d, 속도 s를 가진다
한번의 이동으로 (y,x)의 좌표에서 d방향으로 s만큼 움직인다. 

d의 방향 ind
7 0 1
6 d 2
5 4 3

한 좌표에 두개 이상의 파이어볼이 있을 경우

질량은 floor(전체 질량의 합 / 5)
속력은 floor(전체 속력의 합 / 합쳐진 파이어볼의 개수)
방향은 모두 홀수이거나, 모두 짝수이면 0, 2, 4, 6 그렇지 않으면 1, 3, 5, 7이 된다

풀이)
파이어볼 구조체{질량, 속도, 무게}
vector<Fireball> 2차원 배열 생성 후, (y,x)에 d,m,s를 놓음

파이어볼 움직이는 함수()
    
    2차원 배열 새로 생성 후, 
    (0,0)~(N-1, N-1)까지 확인하면서 
        파이어볼이 있으면
            temp의 이동할 위치에 파이어볼 구조체를 저장한다

        주의) 1번열과 N번열, 1번행과 N번행은 연결되어있으므로, 
            경계 밖으로 나갈 경우 다시 안으로 넣어준다

    이동이 끝나면 다시 map에 temp를 덮어씌운다      

파이어볼 나누는 함수
 
    2차원 배열 새로 생성 후, 
    (0,0)~(N-1, N-1)까지 확인하면서 
        파이어볼이 하나라면 그냥 temp[y][x]에 덮어씌운다
        2개 이상이라면 분할이 일어나는데,
            질량, 속도, 방향 조건에 맞춰서 파이어볼을 생성한다
                주의) 질량이 0이라면 파이어볼은 그냥 삭제된다
                4개씩 생성되므로 현재 temp[y][x]에 4개를 push_back한다 

*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M, K; 

int direct[8][2] = { -1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1 }; 

struct Fireball {
	int m;
	int s;
	int d;
};

vector<Fireball> map[52][52]; 
vector<Fireball> temp[52][52];

void Input() {
	cin >> N >> M >> K;

	// 파이어볼 M개 입력
	for (int i = 0; i < M; i++) {
		int y, x, m, s, d;
		cin >> y >> x >> m >> s >> d; // 파이어볼의 정보는 r, c m, s, d 로 주어짐
		map[y-1][x-1].push_back({ m,s,d });
	}
}

// 파이어볼 이동 함수
void MoveFireballs() {
	memset(temp, 0, sizeof(temp));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x].size() == 0) continue;

			// 파이어볼 위치 이동
			for (int i = 0; i < map[y][x].size(); i++) {
				int dd = map[y][x][i].d;
				int ds = map[y][x][i].s;

				// 0번행과 N-1행, 0번열과 N-1열은 연결되어있음
				int dy = (y + direct[dd][0] * ds) % N;
				int dx = (x + direct[dd][1] * ds) % N;

				if (dy < 0) dy = N + dy;
				if (dx < 0) dx = N + dx;

				temp[dy][dx].push_back(map[y][x][i]);
			}
		}
	}
	//map에 다시 덮어쓰기
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x].clear();
			map[y][x] = temp[y][x];
		}
	}

	return;
}

void SplitFireballs() {
	memset(temp, 0, sizeof(temp));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x].size() == 0) continue;
			if (map[y][x].size() == 1) {
				temp[y][x] = map[y][x];
				continue;
			}
			// 현재 한칸에 두개 이상 있음

			int dm = 0, ds = 0, dd = 0;
			bool is_even = true, is_odd = true; // 홀짝 판별

			int cnt = map[y][x].size();
			for (int i = 0; i < cnt; i++) {
				dm += map[y][x][i].m;
				ds += map[y][x][i].s;
				// 모두 홀수이거나 모두 짝수이면 0,2,4,6방향 아니면 1,3,5,7
				if (map[y][x][i].d % 2 == 0) { is_odd = false; }
				else { is_even = false; }
			}

			dm = dm / 5; // 질량은 floor(합쳐진 파이어볼의 질량의 합 / 5)
			if (dm == 0) continue; // 질량이 0이면 소멸
			ds = ds / cnt; // 속도는 floor(합쳐진 파이어볼 속력의 합 / 합쳐진 파이어볼 개수)
			// 모두 홀수이거나 모두 짝수이면 0,2,4,6방향 아니면 1,3,5,7
			if (is_even == true || is_odd == true) {
				temp[y][x].push_back({ dm,ds,0 });
				temp[y][x].push_back({ dm,ds,2 });
				temp[y][x].push_back({ dm,ds,4 });
				temp[y][x].push_back({ dm,ds,6 });
			}
			else {
				temp[y][x].push_back({ dm,ds,1 });
				temp[y][x].push_back({ dm,ds,3 });
				temp[y][x].push_back({ dm,ds,5 });
				temp[y][x].push_back({ dm,ds,7 });
			}
		}
	}
	// map에 다시 덮어쓰기
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x].clear();
			map[y][x] = temp[y][x];
		}
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	Input();
	
	// K번 움직임
	for (int i = 1; i <= K; i++) {
		MoveFireballs();
		SplitFireballs();
	}

	// 질량확인
	int total = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x].size() == 0) continue;
			for (int i = 0; i < map[y][x].size(); i++) {
				total += map[y][x][i].m;
			}
		}
	}

	cout << total;

	return 0;
}