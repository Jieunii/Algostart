//창고 다각형 : 지붕구하기

#include <iostream>
using namespace std;

int n;
int arr[1001];
int start = 9999;
int eend = 0;
int max_h;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0, h = 0;
		cin >> x >> h;
		arr[x] = h;
		if (x < start) start = x;
		if (x > eend) eend = x;
		if (max_h < h) max_h = h;
	}

	int res = 0;
	int height = 0;
	int flag = 0;

	for (int i = start; i <= eend; i++) {
		if (arr[i] == max_h) {
			flag = 1;
			height = max_h;
			res += height;
		}
		else if (flag == 0) {
			if (height < arr[i]) {
				height = arr[i];
			}
			res += height;
		}
		else if (flag == 1) {
			int mmax = 0;
			for (int j = i; j <= eend; j++) {
				if (arr[j] > mmax) mmax = arr[j];
			}
			res += mmax;
		}
	}

	cout << res << "\n";

	return 0;
}