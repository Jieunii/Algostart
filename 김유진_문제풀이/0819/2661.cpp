#include <iostream>
#include <string>
using namespace std;

int n;
string res;
char arr[4] = { '0','1','2','3' };

void bfs(int cnt, string s) {

	for (int i = 1; i <= s.size() / 2; i++) {
		int flag = 0;
		for (int j = 0; j < i; j++) {
			if (s[s.size() - 1 - j - i] != s[s.size() - 1 - j]){
				//부분수열이 동일하지 않으면
				flag = 1;
			}
		}
		if (flag == 0){
			return;
		}
	}

	if (cnt == n) {
		cout << s << "\n";
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		bfs(cnt + 1, s + arr[i]);
	}
}


int main() {

	cin >> n;
	bfs(0, "");

	return 0;
}