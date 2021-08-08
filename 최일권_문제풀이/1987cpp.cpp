#include <iostream>
using namespace std;

int N, M;
char map[21][21] = {};
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int visited[21][21] = {};
int ans = 1;
int dat[26] = {};
int flag = 1;
int max = -999999;
int isInside(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return 0;
	return 1;
}
void dfs(int y, int x)
{
	if (max < ans)
		max = ans;
	dat[map[y][x] - 65]++;
	for (int i = 0; i < 4; i++)
	{
		int new_y = y + dir[i][0];
		int new_x = x + dir[i][1];

		if (isInside(new_y, new_x) && !visited[new_y][new_x])
		{
			if (dat[map[new_y][new_x] - 65] != 0) continue;
			visited[new_y][new_x] = 1;
			ans++;
			dfs(new_y, new_x);
			ans--;
			dat[map[new_y][new_x] - 65] = 0;
			visited[new_y][new_x] = 0;
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	dfs(0, 0);

	cout << max << endl;

	return 0;
}