/*
N*N 사이즈 격자판에 
M가지 색상의 블럭과, 검은색, 무지개 블럭이 존재.
'블록 그룹'은 연결된 블록의 집합. 
- 그룹에는 검은색은 포함되지 않고, 
- 무지개는 어느 그룹에나 속할 수 있음. 
- 일반 블럭은 하나이상 포함되어야하고, 색이 같아야한다. 
- 그룹은 모두 연결되어있어야한다.
- 기준 블록 : 무지개블럭이 아닌 블럭중, 행의 번호가 가장 작은 블럭, 
			그런 블럭이 여러개라면 열의 번호가 가장 작은 블럭.
*/

/*
1. 터트릴 블럭 그룹 선정하기
	1-1. 크기가 가장 큰 블럭 그룹 터트리기 
	1-2. 블럭 그룹들의 크기가 같을 경우, 무지개 블럭 그룹이 많은 그룹
	1-3. 2번 조건을 만족하는 그룹이 여러개일 경우, '기준 블럭'의 행이 가장 큰 블럭 선정
	1-4. 3번 조건을 만족하는 그룹이 여러개일 경우. '기준 블럭'의 열이 가장 큰 블럭 선정.
2. 터트리기
3. 중력 
4. 반시계 90도 회전
5. 중력
6. 1~5를 터트릴 수 없을때 까지 반복하기

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define BLANK -2
#define BLACK -1
#define RAINBOW 0

#define DEBUG
#ifdef DEBUG
#include <Windows.h>
#endif

using namespace std;

int N, M;
int map[21][21];
int visited[21][21]; // 전체에 대한 중복체크
int r_visited[21][21]; // BFS 함수 내에서 무지개 블럭에 대한 중복 체크
int answer = 0;

int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };

struct BLOCK {			// 블럭 그룹 구조체
	int size;			// 그룹의 크기
	int rainbow_cnt;	// 무지개 블럭의 개수 
	int y;				// 기준 블럭의 위치 저장
	int x;
	vector< pair<int, int> > block_pos;		// 터트릴 블록 그룹에 속해 있는 데이터들을 저장하는 벡터
};

void Input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

#ifdef DEBUG
void ShowMap() {
	system("cls");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == -2) {
				cout << " ";
			}
			else if (map[y][x] == -1) {
				cout << "■";
			}
			else if (map[y][x] == 0) {
				cout << "▨";
			}
			else {
				cout << map[y][x] << " ";
			}
		}
		cout << endl;
	}
	Sleep(1000);
}
#endif 

// 좌표 비교
bool Compare(pair<int, int> front, pair<int, int> back) {
	if (front.first <= back.first)
	{
		if (front.first == back.first)
		{
			if (front.second < back.second)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

// 구조체 그룹의 비교
bool CompareBlock(BLOCK front, BLOCK back) {
	if (front.size >= back.size)
	{
		if (front.size == back.size)
		{
			if (front.rainbow_cnt >= back.rainbow_cnt)
			{
				if (front.rainbow_cnt == back.rainbow_cnt)
				{
					if (front.x >= back.x)
					{
						if (front.x == back.x)
						{
							if (front.y > back.y)
							{
								return true;
							}
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

// BFS
// 현재 좌표 y,x의 color와 연결된 그룹 구조체를 리턴하는 함수
BLOCK BFS(int y, int x, int color) {
	memset(r_visited, false, sizeof(r_visited));
	vector< pair<int, int> > block; // 블럭 그룹 저장용
	vector< pair<int, int> > except_rainbow_block; // 일반 그룹 저장용
	queue< pair<int, int> > qu;

	block.push_back(make_pair(y, x)); 
	except_rainbow_block.push_back(make_pair(y, x));

	visited[y][x] = 1;
	qu.push(make_pair(y, x));

	int rainbow = 0; // 무지개블럭 개수 

	while (qu.empty() == false) {
		pair<int, int> now = qu.front();
		qu.pop();

		for (int t = 0; t < 4; t++) {
			int dy = now.first + direct[t][0];
			int dx = now.second + direct[t][1];

			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue; // 경계 처리
			if (r_visited[dy][dx] == 1) continue; // 이미 방문
			if (map[dy][dx] == 0) { // 무지개인 경우
				rainbow++; // 무지개 개수 증가
				r_visited[dy][dx] = 1;
				block.push_back(make_pair(dy, dx));
				qu.push(make_pair(dy, dx));
			}
			else if(map[dy][dx] == color) { // BFS 탐색용 color인 경우
				except_rainbow_block.push_back(make_pair(dy, dx));
				r_visited[dy][dx] = 1;
				block.push_back(make_pair(dy, dx));
				qu.push(make_pair(dy, dx));
			}
			
		}
	}

	sort(except_rainbow_block.begin(), except_rainbow_block.end(), Compare);

	BLOCK r_block;
	r_block.size = block.size();
	r_block.rainbow_cnt = rainbow;
	r_block.x = except_rainbow_block[0].first;
	r_block.y = except_rainbow_block[0].second;
	r_block.block_pos = block;

	return r_block;
}

// 가장 큰 블럭 그룹을 찾는 함수
BLOCK FindBiggestBlock() {
	memset(visited, false, sizeof(visited));
	BLOCK result;
	result.size = -1;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == 1) continue; // 이미 방문한곳
			if (map[y][x] == BLACK || map[y][x] == BLANK || map[y][x] == RAINBOW) continue; // 검은색, 빈칸, 무지개
			 
			BLOCK temp_result = BFS(y, x, map[y][x]); // 현재 컬러를 바탕으로 BFS탐색

			if (result.size == -1) {
				result = temp_result;
			}
			else {
				if (CompareBlock(temp_result, result) == true) {
					result = temp_result;
				}
			}
			
		}
	}

	return result;
}

void DeleteBlock(BLOCK result) {
	vector<pair<int, int>> V = result.block_pos;
	for (int i = 0; i < V.size(); i++)
	{
		int x = V[i].first;
		int y = V[i].second;
		map[x][y] = -2;
	}
	answer += (V.size() * V.size());
}

void Gravity() {
	for (int x = 0; x < N; x++) {
		for (int y = N - 1; y >= 0; y--) {
			if (map[y][x] == BLANK) { // 현재 칸이 빈공간이라면
				// 위칸을 탐색하며 누가 떨어질 것인지 확인
				int dy = y;
				int dx = x;
				while (dy > 0 && map[dy][dx] == BLANK)
					dy--;
				if (map[dy][dx] == BLACK) continue; // 검은색 블록은 중력에 영향을 받지 않으므로 패스
				map[y][x] = map[dy][dx];
				map[dy][dx] = BLANK;
			}
		}
	}
}

void TurnLeft() {
	int backup[21][21];
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			backup[y][x] = map[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] = backup[x][(N-1)-y];
		}
	}

	int de = -1;
	return;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	// 가장 큰 블록 그룹 찾기
	while (1) {

#ifdef DEBUG
		ShowMap();
#endif

		BLOCK result = FindBiggestBlock();
		if (result.size < 2) break; // 더이상 터트릴 블럭이 없으면 종료
		DeleteBlock(result); // 1. 가장 큰 블럭 터트림

#ifdef DEBUG
		ShowMap();
#endif

		Gravity();

#ifdef DEBUG
		ShowMap();
#endif

		TurnLeft();

#ifdef DEBUG
		ShowMap();
#endif

		Gravity();

#ifdef DEBUG
		ShowMap();
#endif
	}

	cout << answer;

	return 0;
}