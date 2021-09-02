#include <iostream>

using namespace std;

int switchNum;
int switchStatus[101];

void switchToggle(int n) {
	if (switchStatus[n] == 0) switchStatus[n] = 1;
	else switchStatus[n] = 0;
}

void man(int number) {
	for (int i = number; i <= switchNum; i += number) {
		switchToggle(i);
	}
}

void woman(int number) {
	switchToggle(number);

	// 양 옆
	int r = number + 1;
	int l = number - 1;
	while (1 <= l && r <= switchNum) {
		if (switchStatus[r] == switchStatus[l]) {
			switchToggle(r);
			switchToggle(l);
		}
		else break; // return으로 하니까 x, 왜...?
		r++;
		l--;
	}
}

int main() {
	cin >> switchNum;
	for (int i = 1; i <= switchNum; i++) {
		cin >> switchStatus[i];
	}
	int studentNum;
	cin >> studentNum;
	for (int i = 0; i < studentNum; i++) {
		int gender, number;
		cin >> gender >> number;
		// 남자
		if (gender == 1) {
			man(number);
		}
		// 여자
		else {
			woman(number);
		}
	}
	for (int i = 1; i <= switchNum; i++) {
		cout << switchStatus[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
	return 0;
}