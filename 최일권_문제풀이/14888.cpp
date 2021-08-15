#include <iostream>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int N;
queue<int> num;
int used[12] = {};
int oper[4] = {};//0 -> +, 1 -> -, 2 -> X, 3 -> /
//음수를 양수로 나눌 때는 음수를 양수로 바꾸고 나눈 뒤, 그 값에 음수를 취한다.
int max_ = -99999999999;
int min_ = 9999999999;
int path[12] = {};
void calculate(int level) {
	if (level == N - 1) {
		int sum = 0;
		sum = num.front();
		num.push(num.front());
		num.pop();

		for (int i = 0; i < N - 1; i++) {
			switch (path[i]) {
			case 0:
				sum += num.front();
				num.push(num.front());
				num.pop();
				break;
			case 1:
				sum -= num.front();
				num.push(num.front());
				num.pop();
				break;
			case 2:
				sum *= num.front();
				num.push(num.front());
				num.pop();
				break;
			case 3:
				if (sum < 0) {
					int ans = abs(sum) / num.front();
					sum = -1 * ans;
					num.push(num.front());
					num.pop();
					break;
				}
				else {
					sum /= num.front();
					num.push(num.front());
					num.pop();
					break;
				}
			}

		}
		if (max_ < sum) {
			max_ = sum;
		}
		if (min_ > sum) {
			min_ = sum;
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] == 0) continue;
		if (used[i] == oper[i]) continue;
		used[i]++;
		path[level] = i;
		calculate(level + 1);
		used[i]--;
	}
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		num.push(n);
	}

	for (int i = 0; i < 4; i++)
	{
		int op;
		cin >> op;
		oper[i] = op;
	}

	calculate(0);

	cout << max_ << endl;
	cout << min_ << endl;

	return 0;
}