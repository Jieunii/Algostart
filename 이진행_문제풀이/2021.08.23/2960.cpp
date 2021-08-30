#include <iostream>

using namespace std;

int n, k;
int prime[1001];

int main() {
	cin >> n >> k;

	prime[1] = 1;
	
	int cnt = 0;
	int last_deleted = 1;
	for (int i = 2; i <= n; i++) {
		if (prime[i] == 0) {
			prime[i] = 1; // 소수는 1로 표시
			last_deleted = i;
			cnt++; 

			int prod = 2; // p의 2배수 부터 지워나감
			while (i * prod <= n) {
				if (prime[i * prod] == 0) {
					prime[i * prod] = i;
					last_deleted = i * prod;
					cnt++;
					if (cnt == k) { break; }
				}
				prod++;
			}

			if (cnt == k) {
				cout << last_deleted << endl;
				return 0;
			}
		}
	}

	return 0;
}