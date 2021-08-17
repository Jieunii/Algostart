#include <iostream>
#define MAX 50

using namespace std;

int N, M;
int MAP[MAX][MAX];

pair<pair<int, int>, int> robot;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int direction[4] = { 3, 0, 1, 2 };

int main(void)
{
	cin >> N >> M;
	cin >> robot.first.first >> robot.first.second >> robot.second;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}

	int x = robot.first.first;
	int y = robot.first.second;
	int d = robot.second;
	int cnt = 0;

  // 현재 위치 청소
	MAP[x][y] = 2;
	cnt++;

	int nx, ny, nd;
	while (1)
	{
		int Tmp_d = d;
		bool cleanO = false;
		int cleanX = 0;
		for (int i = 0; i < 4; i++)
		{
			nd = direction[d];
			nx = x + dx[nd];
			ny = y + dy[nd];

			// 청소 할 수 O
			if (MAP[nx][ny] == 0)
			{
				cleanO = true;
				break;
			}
			// 청소 할 수 X
			else if (MAP[nx][ny] == 1 || MAP[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= N || ny >= M))
			{
				d = nd;
				cleanX++;
			}
		}

    // 청소하기
		if (cleanO == true)
		{
			MAP[nx][ny] = 2;
			cnt++;
			d = nd;
		}

    // 청소기 멈춤 조건(후진 못하면 끝)
		if (cleanX == 4)
		{
			nx = x - dx[Tmp_d];
			ny = y - dy[Tmp_d];
			d = Tmp_d;
			if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || MAP[nx][ny] == 1)
			{
				break;
			}
		}
		x = nx;
		y = ny;
	}
	cout << cnt << endl;
	return 0;
}
