#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isVPS(string str) {
	stack<char> s;
	int i = 0;

	while (i != str.size()) {
		char ps = str[i];
		// '('면 스택에 push
		if (ps == '(') {
			s.push(ps);
		}
		// ')'면
		else {
			if (!s.empty()) { // 스택에 '(' 있다면 pop
				s.pop();
			}
			else {						// 스택이 비어있으면 false -> 올바른 괄호 문자열 아님
				return false;
			}
		}
		i++;
	}
	return s.empty();
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (isVPS(str)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}