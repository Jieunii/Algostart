#include <iostream>
#include <queue>
using namespace std;

int N, M;
int r, c, d;
int map[51][51] = {};
int visited[51][51] = {};
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
// d = 0,1,2,3(북,동,남,서)
queue<pair<pair<int, int>, int>> robot;
//왼쪽으로 방향 이동
// 0 일 때 => 3
// 1 일 때 => 0
// 2 일 때 => 1
// 3 일 때 => 2
int rotate_[4] = { 3,0,1,2 };
int back_[4] = { 2,3,0,1 };
int cnt = 0;
int isInside(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)
		return 0;
	return 1;
}
//1.현재 위치를 청소한다.
//2.현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
//	a.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
//	b.왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
//	c.네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
//	d.네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

int main() {

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j]; //1은 벽, 0은 청소할 곳
		}
	}
	robot.push({ {r,c},d });

	while (1) {
		int d_cnt = 0;
		int flag = 0;
		int y = robot.front().first.first;
		int x = robot.front().first.second;
		int direct = robot.front().second;
		robot.pop();

		visited[y][x] = 1;
		cnt++;
		
		for (int i = 0; i < 4; i++)
		{
			d_cnt++;

			direct = rotate_[direct];

			int new_y = y + dir[direct][0];
			int new_x = x + dir[direct][1];

			if (map[new_y][new_x] == 0 && !visited[new_y][new_x])
			{
				robot.push({ {new_y,new_x},direct });
				break;
			}
			if (d_cnt == 4)
			{
				int b_y = y + dir[back_[direct]][0];
				int b_x = x + dir[back_[direct]][1];

				if (map[b_y][b_x] == 0) {
					cnt--;
					robot.push({ {b_y,b_x},direct });
					continue;
				}
				flag = 1;
				break;
				
			}
		}

		if (flag)
			break;
	}

	cout << cnt << endl;

	return 0;
}