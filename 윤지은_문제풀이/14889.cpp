#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int capacity[21][21];
int visited[21];
int mini = 21e8;

void startlink(int lev, int st) {
	if (lev == N / 2) {
		// start팀, link팀
		vector<int> start, link;
		for (int i = 0; i < N; i++) {
			if (visited[i]) start.push_back(i);
			else link.push_back(i);
		}
		// 능력차
		int start_ca = 0, link_ca = 0;
		for (int y = 0; y < lev; y++) {
			for (int x = y + 1; x < lev; x++) {
				int startY = start[y], startX = start[x];
				int linkY = link[y], linkX = link[x];
				start_ca += capacity[startY][startX] + capacity[startX][startY];
				link_ca += capacity[linkY][linkX] + capacity[linkX][linkY];
			}
		}
		mini = min(mini, abs(start_ca - link_ca));
		return;
	}
	for (int i = st; i < N; i++) {
		visited[i] = 1;
		startlink(lev + 1, i + 1);
		visited[i] = 0;
	}

}
int main()
{

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> capacity[y][x];
		}
	}
	// 팀조합
	startlink(0, 0);

	cout << mini;
	return 0;
}