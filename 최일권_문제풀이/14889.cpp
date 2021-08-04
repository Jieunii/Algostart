#include <iostream>
#include <math.h>
using namespace std;

int used[21] = {  };
int N;
int map[21][21];
int path[21] = {  };
int ans = 99999999;

void back(int level,int cnt)
{
	if (level == N / 2)
	{
		int start = 0;
		int link = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (used[i] == 1 && used[j]==1)
				{
					start += map[i][j];
				}
				else if(used[i]==0 && used[j]==0)
				{
					link += map[i][j];
				}
			}
		}
		int sub = abs(start - link);
		if (ans > sub)
			ans = sub;
		return;
	}

	for (int i = cnt; i < N; i++)
	{
		used[i] = 1;
		back(level + 1, cnt + 1);
		used[i] = 0;
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	back(0, 0);

	printf("%d\n", ans);

	return 0;
}