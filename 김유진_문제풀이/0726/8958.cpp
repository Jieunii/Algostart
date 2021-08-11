#include <iostream>
#include <string.h>
using namespace std;

int n;
string str;
int cnt;
int res;

void calc(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'O') {
			cnt += 1;
		}
		else {
			for (int j = 1; j <= cnt; j++) {
				res += j;
			}
			cnt = 0;
		}
	}
}

void init() {
	res = 0;
	cnt = 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		init();
		cin >> str;
		calc(str);
		for (int i = 1; i <= cnt; i++) {
			res += i;
		}
		cout << res << "\n";
	}
	return 0;
}
