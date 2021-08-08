#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;
	string result;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> result;
		int score = 0;
		int cnt = 1;
		for (int j = 0; j < result.length(); j++) {
			if (result[j] == 'O') {
				score += cnt;
				cnt++;
			}
			else {
				cnt = 1;
			}
		}
		cout << score << endl;
	}
}