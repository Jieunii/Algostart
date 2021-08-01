#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isVPS(string str) {
	stack<char> s;
	int i = 0;
	while (i != str.size()) {
		char ps = str[i];
		if (ps == '(') {
			s.push(ps);
		}
		else {
			if (!s.empty()) {
				s.pop();
			}
			else {
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