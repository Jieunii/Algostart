#include <iostream>
using namespace std;

int N;
int T[16] = {};
int P[16] = {};
int sum = 0;
int max_ = -9999999999;
void dfs(int n, int sum, int pre_p) {
	
	if(n == N + 1) {
		if (max_ < sum) {
			max_ = sum;
		}
		return;
	}
	if (n >= N + 2) {
		if (max_ < sum - pre_p) {
			max_ = sum - pre_p;
		}
		return;
	}

	for (int i = n+T[n]; i <= N+T[n]; i++) {
		dfs(i, sum + P[n], P[n]);
	}

}

int main() {
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int t, p;
		cin >> t >> p;
		T[i] = t;
		P[i] = p;
	}

	for (int i = 1; i <= N; i++) {
		dfs(i,0,0);
	}
	cout << max_<< endl;

	return 0;
}