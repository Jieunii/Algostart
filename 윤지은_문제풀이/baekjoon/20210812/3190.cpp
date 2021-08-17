#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K, L;

	int map[101][101] = { 0, };
	pair<int, char> dir_change[101];
	int cur_change_index = 0;

	int APPLE = 1;
	int SNAKE = -1;

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	//방향 전환 인덱스
	int cur_direction = 0;

	//초기 뱀 위치
	map[0][0] = SNAKE;
	pair<int, int> head = { 0, 0 };
	queue<pair<int, int>> snake;
	snake.push(head);

	cin >> N;
	cin >> K;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = APPLE;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		//방향변환
		cin >> dir_change[i].first >> dir_change[i].second;
	}

	int sec = 0;

	while (1)
	{
		sec++;

		int nx = head.first + dx[cur_direction];
		int ny = head.second + dy[cur_direction];

		//벽이면 게임 끝, 이동할 위치가 뱀의 몸의 일부분이면 게임 끝
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == SNAKE) break;
		//사과가 없으면 꼬리가 이동
		else if (map[nx][ny] != APPLE){
			auto tail = snake.front();
			snake.pop();
			map[tail.first][tail.second] = 0;
		}

		//머리 한칸 이동
		head = { nx, ny };
		snake.push(head);

		map[nx][ny] = SNAKE;

		//진행 방향을 찾음
		int dir_change_sec = dir_change[cur_change_index].first;
		if (cur_change_index < L && dir_change_sec == sec) {
			char dir = dir_change[cur_change_index].second;
			// 좌회전
			if (dir == 'L') cur_direction = (cur_direction + 3) % 4;
			// 우회전
			else if (dir == 'D') cur_direction = (cur_direction + 1) % 4;
			
			cur_change_index++;
		}
	}

	cout << sec << '\n';

	return 0;
}