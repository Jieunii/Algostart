#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[101][101] = {};
char str[101];
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };
int N, M;
int visited[101][101] = {};
int cnt = 1;

bool isInside(int x, int y)
{
	return ((x >= 1 && x <= N) && (y >= 1 && y <= M));
}
int maze(int x, int y)
{
	queue<pair<int, int>> que;
	que.push(pair<int, int>(x, y));
	visited[x][y] = 1;

	while (!que.empty())
	{
		x = que.front().first;
		y = que.front().second;
		que.pop();

		if (x == N && y == M)
			break;

		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			if (isInside(new_x, new_y) && map[new_x][new_y] == 1 && visited[new_x][new_y] == 0)
			{
				que.push(pair<int, int>(new_x, new_y));
				visited[new_x][new_y] = visited[x][y] + 1;

			}
		}

	}
	return visited[N][M];
}


int main()
{

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = static_cast<int>(str[j - 1] - '0');
		}
	}


	cnt = maze(1, 1);


	cout << cnt << endl;

	return 0;
}