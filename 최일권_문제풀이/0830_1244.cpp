#include <iostream>
using namespace std;

int N;
int led[101];

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> led[i];

	int k;
	cin >> k;
	for (int j = 0; j < k; j++) {
		int g, num;
		cin >> g >> num;
		int start_idx = num;
		int end_idx = num;
		if (g == 1) {
			for (int i = 1; i <= N; i++) {
				if (i%num == 0) {
					led[i] = !led[i];
				}
			}
		}
		else {
			int k = 0;
			while (1) {
				if (num + k >= N || num - k <= 1) break;
				if (led[num + k + 1] == led[num - (k + 1)]) {
					start_idx = num - (k + 1);
					end_idx = num + (k + 1);
				}
				else break;
				k++;
			}
			for (int i = start_idx; i <= end_idx; i++) {
				led[i] = !led[i];
			}
		}
	}

	if (N <= 20) {
		for (int i = 1; i <= N; i++)
			cout << led[i] << " ";
		cout << endl;
	}
	else {
		for (int i = 1; i <= N; i++) {
			cout << led[i] << " ";
			if (i % 20 == 0) cout << endl;
		}
		cout << endl;
	}

	return 0;
}