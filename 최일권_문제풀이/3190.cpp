#include <iostream>
#include <queue>
#include <deque>
using namespace std;

struct moving {
	int aft;
	char direction;
};
//바라보는 방향도 생각해 줘야한다~
//0,1,2,3 오른쪽, 아래, 왼쪽, 위
int map[101][101] = {};
int visited[101][101] = {};
int N, K, L;
queue<moving>move_;
deque<pair<pair<int,int>,int>> snake; //y,x,dir
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//오른쪽,아래, 왼쪽, 위
int sec = 0;
int isInside(int y, int x) {
	if (y<=0 || y>N || x<=0 || x>N)
		return 0;
	return 1;
}
// direct가 0 일 때 D => dir[1],1  L => dir[3],3
// 1일 때 D=>dir[2],2  L => dir[0],0
//2일 때 D => dir[3],3  L => dir[1],1
//3일 때 D => dir[0],0  L => dir[2],2
//정리하자면 
// D => 
// L => 
int D_move[4] = { 1,2,3,0 };//뒤에는 보는 방향
int L_move[4] = { 3,0,1,2 };

int main() {

	cin >> N;

	cin >> K;
	for (int i = 1; i <= K; i++) {
		int y, x;

		cin >> y >> x;

		map[y][x] = 99;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int x;
		char c;
		cin >> x >> c;

		moving temp = { x,c };
		move_.push(temp);
	}
	snake.push_back({ {1,1},0});
	int new_y = 0, new_x = 0;
	int flag = 0;

	while (1)
	{
		int y = snake.front().first.first;
		int x = snake.front().first.second;
		int direct = snake.front().second;
		visited[y][x] = 1;
		++sec;

		if (!move_.empty()) {
			if (sec - 1== move_.front().aft)
			{
				if (move_.front().direction == 'D')
				{
					new_y = y + dir[D_move[direct]][0];
					new_x = x + dir[D_move[direct]][1];
					snake.push_front({ {new_y,new_x},D_move[direct] });
				}
				else if (move_.front().direction == 'L')
				{
					new_y = y + dir[L_move[direct]][0];
					new_x = x + dir[L_move[direct]][1];
					snake.push_front({ {new_y,new_x},L_move[direct] });
				}
				move_.pop();
			}
			else {
				new_y = y + dir[direct][0];
				new_x = x + dir[direct][1];
				snake.push_front({ {new_y,new_x},direct });
			}
		}
		else {
			flag = 1;
		}
		if (flag) {
			new_y = y + dir[direct][0];
			new_x = x + dir[direct][1];
			snake.push_front({ {new_y,new_x},direct });
		}
		if (!isInside(new_y, new_x) || map[new_y][new_x] == -1) {
			break;
		}
		if (map[new_y][new_x] == 99) {
			visited[new_y][new_x] = 1;
			map[snake.back().first.first][snake.back().first.second] = -1;
			map[new_y][new_x] = -1;
		}
		else {
			visited[new_y][new_x] = 1;
			map[new_y][new_x] = -1;
			map[snake.back().first.first][snake.back().first.second] = 0;
			snake.pop_back();
		}
	}

	cout << sec << endl;

	return 0;
}