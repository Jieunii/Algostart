//구현

#include <iostream>
using namespace std;

int n, k, cnt;
int arr[1001];

int main() {

	cin >> n >> k;

	//1.
	for (int i = 2; i <= n; i++) {
		arr[i] = 1;
	}

	int cnt = 0;
	int start = 2;
	while (1) {
		if (arr[start] == 0) {
			start++;
			continue;
		}
		
		for (int i = 1; i < 1000; i++) {
			int idx = start * i;
			if (idx <= n && arr[idx] ==1) {
				arr[idx] = 0;
				cnt++;

				//cnt올라갈때마다 체크
				if (cnt == k) {
					cout << idx;
					return 0;
				}
			}
			else if(idx > n){
				break;
			}
		}
		start++;
	}
	return 0;
}