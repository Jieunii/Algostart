#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int map[1001][1001];
int N, M;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int visited[1001][1001] = {};
int day = 0;
queue<pair<int, int>> start;
int isInside(int y, int x)
{
	if (y<0 || y>=N || x<0 || x>=M)
		return 0;
	return 1;
}

void bfs()
{
	while (!start.empty()) {
		int y = start.front().first;
		int x = start.front().second;
		start.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_y = y + dir[i][0];
			int new_x = x + dir[i][1];

			if (isInside(new_y, new_x) && map[new_y][new_x] == 0 && map[new_y][new_x] != -1)
			{
				start.push(pair<int, int>(new_y, new_x));
				map[new_y][new_x] = map[y][x] + 1;
			}
		}
	}
}

//0 안익은 토마토, -1 썩은 토마토 , 1 익은 토마토
int main()
{
	int start_y, start_x;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1) {
				start.push(pair<int, int>(i, j));//두개 저장
			}
		}
	}
	int flag = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
				cnt++;
		}
	}
	if (cnt == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	bfs();
	int ans = -99999999;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ans < map[i][j])
				ans = map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				flag = 1;
				break;
			}
		}
	}

	if (flag)
		cout << -1 << endl;
	else
		cout << ans-1 << endl;

	return 0;
}