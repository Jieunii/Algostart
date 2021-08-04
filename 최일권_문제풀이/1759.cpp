#include <iostream>
#include <algorithm>
using namespace std;

int used[16] = {};
char path[16] = {};
int L, C;
char alp[16] = {};
int mo = 0;
int za = 0;
void run(int level,int start)
{
	if (level == L)
	{
		for (int i = 0; i < level; i++)
		{
			if (path[i] == 'a' || path[i] == 'e' || path[i] == 'i' || path[i] == 'o' || path[i] == 'u')
				mo++;
			else
				za++;
		}
		if (mo < 1 || za < 2) {
			mo = 0;
			za = 0;
			return;
		}
		cout << path << endl;
		mo = 0;
		za = 0;
		return;
	}

	for (int i = start; i < C; i++)
	{
		if (used[i] == 1) continue;
		used[i] = 1;
		path[level] = alp[i];
		run(level + 1, i + 1);
		used[i] = 0;
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> alp[i];

	sort(alp, alp + C);
	run(0, 0);

	return 0;
}