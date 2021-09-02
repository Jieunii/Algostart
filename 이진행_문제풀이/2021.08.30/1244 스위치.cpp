#include <iostream>

using namespace std;

int n, t;
bool swtch[101];//false: off, ture: on

void Input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> swtch[i];
	}

	cin >> t;
}

// num을 입력받아
// num의 배수들을 모두 토글시킨다
void male_switch(int num) {
	for (int i=1; i * num<= n; i++) {
		swtch[i * num] = !swtch[i * num];
	}
}


void female_switch(int num) {
	int start = num, end = num;

	while (1) {
		start--;
		end++;
		
		if (start < 1 || end > n) {
			start++;
			end--;
			break;
		}

		if (swtch[start] != swtch[end]) {
			start++;
			end--;
			break;
		}
	}

	for (int i = start; i <= end; i++) {
		swtch[i] = !swtch[i];
	}
}


int main() {
	 // freopen_s(new FILE*, "test.txt", "r", stdin);
	 Input();

	while (t--) {
		int type, num;
		cin >> type >> num;
		if (type == 1) {
			male_switch(num);
		}
		else {
			female_switch(num);
		}
	}

	// 한줄에 20개씩 출력하기
	for (int i = 1; i <= n; i++) {
		cout << swtch[i] << " ";
		if (i % 20 == 0) {
			cout << endl;
		}
	}

	return 0;
}