#include <iostream>
#include <queue>
using namespace std;

int N, M;
int r, c, d;
int map[51][51] = {};
int visited[51][51] = {};
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
// d = 0,1,2,3(��,��,��,��)
queue<pair<pair<int, int>, int>> robot;
//�������� ���� �̵�
// 0 �� �� => 3
// 1 �� �� => 0
// 2 �� �� => 1
// 3 �� �� => 2
int rotate_[4] = { 3,0,1,2 };
int back_[4] = { 2,3,0,1 };
int cnt = 0;
int isInside(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)
		return 0;
	return 1;
}
//1.���� ��ġ�� û���Ѵ�.
//2.���� ��ġ���� ���� ������ �������� ���� ������� ���ʴ�� ������ ĭ�� Ž���Ѵ�.
//	a.���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
//	b.���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
//	c.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
//	d.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.

int main() {

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j]; //1�� ��, 0�� û���� ��
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