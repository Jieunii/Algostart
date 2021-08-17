#include <iostream>
#include <cstring>
using namespace std;

int t;
int n;
int student[100001];
int used[100001];
int cnt;
int flag;

void go(int start, int target) {
	if (target == student[start]) {
		flag = 1;
		return;
	}
	if (!used[student[start]]) {
		cnt++;
		used[student[start]] = 1;
		go(student[start], target);
		if (!flag) {
			used[student[start]] = 0;
			cnt--;
		}
	}
}

int main() {

	cin >> t;
	for (int i = 0; i < t; i++) {
		//init
		cnt = 0;
		flag = 0;
		memset(used, false, sizeof(used));

		//input
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> student[j];
		}

		//start
		for (int j = 1; j <= n; j++) {
			flag = 0;

			if (j > student[j]) continue;
			if (j == student[j]) {
				cnt++;
				used[j] = 1;
				continue;
			}

			if (!used[j]) {
				used[j] = 1;
				cnt++;
				go(j, j);
				if (!flag) {
					cnt--;
					used[j] = 0;
				}
			}
		}

		cout << n-cnt << "\n";
	}
	return 0;
}