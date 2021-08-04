#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N, M;
queue<int> car;
int space[101];
int weight[2001];
int flag[101] = {};

int main()
{
	int sum = 0;

	int sp_cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> space[i];
		sp_cnt++;
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> weight[i];
	}

	for (int i = 0; i < 2 * M; i++)
	{
		int num;
		cin >> num;
		if (num < 0)
		{
			int idx = 0;
			for (int j = 1; j <= N; j++)
				if (flag[j] == abs(num)) {
					idx = j;
					break;
				}
			if (!car.empty())
			{
				flag[idx] = car.front();
				sum += (space[idx] * weight[car.front()]);
				car.pop();
			}
			else {
				flag[idx] = 0;
				sp_cnt++;
			}
			continue;
		}
		if (sp_cnt == 0)
		{
			car.push(num);
		}
		else
		{
			int idx = 0;
			for (int i = 1; i <= N; i++)
				if (flag[i] == 0) {
					idx = i;
					break;
				}
			sum += (space[idx] * weight[num]);
			flag[idx] = num;
			sp_cnt--;
		}
	}
	
	cout << sum << endl;

	return 0;
}