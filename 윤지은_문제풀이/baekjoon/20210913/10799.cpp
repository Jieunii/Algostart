#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> stick;

int main() {
	int result = 0;
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			stick.push(input[i]);
		}
		else if(input[i-1] == '(' && input[i] == ')') { // 레이저
			stick.pop();
			result += stick.size();
		}
		else { // 쇠막대기 마무리
			stick.pop();
			result++;
		}
	}
	cout << result;
	return 0;
}