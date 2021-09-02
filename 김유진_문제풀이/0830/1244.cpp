#include <iostream>
#include <vector>
using namespace std;

struct info {
	int gender;
	int num;
};

int led[101];
int led_n;
int std_n;
vector<info> v;

void on(int gender, int num) {
	if (gender == 1) {
		for (int i = num; i <= led_n; i += num) {
			if (led[i] == 0) led[i] = 1;
			else led[i] = 0;
		}
	}
	else {
		int i = 0;
		for (i = 1; i <= led_n; i++) {
			if (num - i <= 0) break;
			if (num + i > led_n) break;
			if (led[num - i] != led[num + i]) {
				break;
			}
		}
		i--;
		for (int j = num - i; j <= num + i; j++) {
			if (led[j] == 0) led[j] = 1;
			else led[j] = 0;
		}
	}
}

int main() {
	//input
	cin >> led_n;
	for (int i = 1; i <= led_n; i++) {
		cin >> led[i];
	}
	cin >> std_n;
	for (int i = 0; i < std_n; i++) {
		int gender = 0, num = 0;
		cin >> gender >> num;
		v.push_back({ gender, num });
	}


	//start
	for (int i = 0; i < std_n; i++) {
		on(v[i].gender, v[i].num);
	}

	//output(20°³¾¿ ²÷¾î¼­)
	for (int x = 0; x <= led_n / 20; x++) {
		if (led_n / 20 == x) {
			for (int i = x * 20 + 1; i <= x*20 + (led_n % 20); i++) {
				cout << led[i] << " ";
			}
		}
		else {
			for (int i = x * 20 + 1; i <= x * 20 + 20; i++) {
				cout << led[i] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
