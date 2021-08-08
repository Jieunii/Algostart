#include <stdio.h>

int card[9];
int N, M;
int used[9];

void dfs(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", card[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		card[level] = i + 1;
		dfs(level + 1);
		used[i] = 0;
	}
}

int main() {
	scanf("%d %d", &N, &M);

	dfs(0);
	return 0;
}
