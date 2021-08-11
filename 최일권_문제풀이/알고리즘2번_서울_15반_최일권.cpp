#include <iostream>
#include <queue>
using namespace std;
int M, K;
int board[18][18] = {};
queue<pair<int, int>> sedol;
queue<pair<int, int>> gamma;
int flag = 0;
int s_flag = 0;
int g_flag = 0;
int dir[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
int isInside(int y, int x)
{
	if (y <= 0 || y >= 18 || x <= 0 || x >= 18)
		return 0;
	return 1;//유효성 판단
}

void K_mok(int y, int x)
{
	for (int i = 0; i < 8; i++)
	{
		int cnt = 1;
		int new_y = y + dir[i][0];
		int new_x = x + dir[i][1];

		if (!isInside(new_y, new_x)||board[y][x]!=board[new_y][new_x]) continue;

		while (1) {
			cnt++;
			new_y += dir[i][0];
			new_x += dir[i][1];

			if (!isInside(new_y, new_x) || board[y][x] != board[new_y][new_x]) break;

		}
		if (cnt == K) //K번만큼의 같은 바둑알이 있으면
		{
			flag = 1; //flag을 세우고
			if (board[y][x] == 1)
				s_flag = 1;
			else if (board[y][x] == 2)
				g_flag = 1;//바둑알 색을 판단해서 각 색의 flag를 세움
			break;
		}
	}
}

int main()
{	
	int n = 0;
	int y, x;

	cin >> M >> K;

	for (int i = 0; i < M; i++) {
		cin >> y >> x;
		sedol.push(pair<int, int>(y, x));
	}

	for (int i = 0; i < M; i++) {
		cin >> y >> x;
		gamma.push(pair<int, int>(y, x));
	}
	//세돌이는 1, 감마고는 2
	while (n <= 2 * M) {
		n++;
		if (n % 2 != 0)
		{
			board[sedol.front().first][sedol.front().second] = 1;
			K_mok(sedol.front().first, sedol.front().second);
			sedol.pop();
		}
		if (flag)
			break;
		else {
			board[gamma.front().first][gamma.front().second] = 2;
			K_mok(gamma.front().first, gamma.front().second);
			gamma.pop();
		}
		if (flag)
			break;
	}
	if (n > 2 * M)
	{
		cout << 0 << endl;
		return 0;
	}
	else {
		cout << n << endl;
		if (s_flag) {
			cout << "세돌이" << endl;
			return 0;
		}
		else if (g_flag) {
			cout << "감마고" << endl;
			return 0;
		}
	}


	return 0;
}