#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, temp;
	int mini = 21e8, maxi = -21e8;
	vector<int> num, op;
  
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	// 덧셈(0), 뺼셈(1), 곱셈(2), 나눗셈(3)
	// ex) 2 1 1 1 -> 0 0 1 2 3
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		while (temp) {
			op.push_back(i);
			temp--;
		}
	}

	do {
		int result = num[0];
		for (int i = 0; i < N - 1; i++) {
			if (op[i] == 0)
				result += num[i + 1];
			else if (op[i] == 1)
				result -= num[i + 1];
			else if (op[i] == 2)
				result *= num[i + 1];
			else if (op[i] == 3)
				result /= num[i + 1];
		}
		mini = min(mini, result);
		maxi = max(maxi, result);
	} while (next_permutation(op.begin(), op.end()));

	cout << maxi << '\n' << mini;

	return 0;
}