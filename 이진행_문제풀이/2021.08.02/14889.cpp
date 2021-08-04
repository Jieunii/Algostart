#include <iostream>
#include <vector>

using namespace std;

int path[21];
int used[21];

// nC(n-2)까지는 만들어냈음..
// 이후에 이걸 사용해서 어떻게 최소값을 계산??
void make_team(int Lv, int br, int start, int max) {

	if (Lv == max) {
		
		for (int i = 0; i < Lv; i++) {
			cout << path[i] << " ";
		}
		cout << endl;

		return;
	}

	for (int x = start; x < br; x++) {
		if (used[x] == 1)continue;

		used[x] = 1;
		path[Lv] = x;

		make_team(Lv + 1, br, x + 1 , max);

		used[x] = 0;
		path[Lv] = 0;
	}
}


int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	int n;

	cin >> n;

	vector< vector<int> > synergy(n + 1, vector<int>(n + 1));

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> synergy[y][x];
		}
	}

	make_team(0, n, 0, n/2);

	return 0;
}