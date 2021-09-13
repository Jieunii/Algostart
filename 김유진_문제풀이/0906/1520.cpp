//내리막길

#include<iostream>
using namespace std;

int n, m;
int map[501][501];
int dp[501][501];
int res = 1;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


int dfs(int y, int x)
{
	if (y == n - 1 && x == m - 1) return 1;
	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && ny < n && nx < m)
		{
			if (map[ny][nx] < map[y][x])
			{
				dp[y][x] += dfs(ny, nx);
			}
		}
	}
	return dp[y][x];
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			//dp -1 : 아직 탐색하지 않았을 때
			//dp 0 : 탐색후 경로가 0일때
			dp[i][j] = -1;
		}
	}

	res = dfs(0, 0);

	cout << res << "\n";

	return 0;
}