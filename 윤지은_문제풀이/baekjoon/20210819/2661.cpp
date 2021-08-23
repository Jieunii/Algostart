#include <iostream>
#include <algorithm>

using namespace std;

int N;
int path[81];

void DFS(int level) {
	for (int i = 1; i <= level/2; i++) {
		// 배열 구간 비교
		if (equal(path + level - i, path + level, path + level - i * 2))
			return;
	}

	if (level == N) {
		for (int i = 0; i < N; i++) {
			cout << path[i];
		}
		// 가장 먼저 출력 후 종료
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		path[level] = i;
		DFS(level + 1);
	}
}

int main()
{
	cin >> N;
	DFS(0);
	
	return 0;
}