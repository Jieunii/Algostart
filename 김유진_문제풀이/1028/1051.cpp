//숫자 정사각형

#include <iostream>
#include <string>
using namespace std;

int map[51][51];
int res = 1; //두칸 넘어가지 않을 때

int main() {
	int n = 0, m = 0;
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int first = map[i][j];
			
			for (int x = j + 1; x < m; x++) {
				if (first == map[i][x]) {
					int second = map[i][x];

					int len = x - j;
					if (i + len < n) {
						int third = map[i + len][j];
						int fourth = map[i + len][x];
						if (second == third && third == fourth) {
							if(res < (len+1)*(len+1)) res = (len+1) * (len+1);
						}
					}
				}
			}
		}
	}

	cout << res;

	return 0;
}