#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int L_map[100][100] = {};
int H_map[100][100] = {};
int h_visited[100]= {};
int l_visited[100]= {};
int h_cnt = 0;
int l_cnt = 0;
int ans = 0;
void dfs(int start)
{

	h_visited[start] = 1;
	for (int i = 1; i <= N; i++)
	{
		int next_node = L_map[start][i];
		if (!h_visited[next_node])
		{
			h_cnt++;
			dfs(next_node);
		}
	}
	
}
void h_dfs(int start)
{

	l_visited[start] = 1;
	for (int i = 1; i <= N; i++)
	{
		int next_node = H_map[start][i];
		if (!l_visited[next_node])
		{
			l_cnt++;
			h_dfs(next_node);
		}
	}
	
}

int main()
{
	int y, x;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> y >> x;
		L_map[y][x] = x; //나보다 가벼운 구슬만 저장
		H_map[x][y] = y;// 나보다 무거운 구슬만 저장
	}



	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) {
			h_visited[j] = 0;
			l_visited[j] = 0;
		}
		l_cnt = 0;
		h_cnt = 0;

		dfs(i);
		h_dfs(i);


		if (h_cnt >= (N + 1) / 2 || l_cnt >= (N + 1) / 2)
			ans++;

	}

	cout << ans << endl;
	return 0;
}