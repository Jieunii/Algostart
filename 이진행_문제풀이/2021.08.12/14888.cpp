#include <iostream>

using namespace std;

int oper[4];	// +, -, *, /
int num[12];

int min_sum = 21e8;
int max_sum = -21e8;


// Lv : n, branch : 4 재귀함수
void dfs(int lv, int max, int sum) {

	if (lv == max) { 
		if (min_sum > sum) min_sum = sum;
		if (max_sum < sum) max_sum = sum;

		return;
	}

	// '+'
	if (oper[0] > 0) { 
		oper[0]--;

		/*sum = sum + num[lv+1];
		dfs(lv + 1, max, sum);
		sum = sum - num[lv + 1];*/

		dfs(lv + 1, max, sum + num[lv+1]);

		oper[0]++;
	}

	// '-'
	if (oper[1] > 0) {
		oper[1]--;
		dfs(lv + 1, max, sum - num[lv + 1]);

		oper[1]++;
	}

	// '*'
	if (oper[2] > 0) {
		oper[2]--;
		dfs(lv + 1, max, sum * num[lv + 1]);

		oper[2]++;
	}

	// '/'
	if (oper[3] > 0) {
		oper[3]--;
		dfs(lv + 1, max, sum / num[lv + 1]);

		oper[3]++;
	}
	
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	dfs(0, n-1, num[0]); // 

	cout << max_sum << endl << min_sum;

	return 0;
}