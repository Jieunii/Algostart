#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int N;
int gp = 0;
int val[100001] = {};
int visited[100001] = {};
int finished[100001] = {};
void dfs(int node) {

	visited[node] = 1;

	int next = val[node];

	if (visited[next] == 0)
		dfs(next);

	else {
		if (!finished[next]) {
			for (int i = next; i != node; i = val[i])
				gp++;
			gp++;
		}
	}
	finished[node] = 1;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {

		cin >> N;

		gp = 0;

		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		for (int i = 1; i <= N; i++) {
			scanf("%d", &val[i]);
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				dfs(i);
			}
		}

		printf("%d\n", N - gp);

	}

	return 0;
}