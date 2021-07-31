#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		//스택 초기화
		while(!s.empty()) {
			s.pop();
		}

		//문자열 입력
		string str = "";
		cin >> str;


		//문자열 길이만큼 반복
		for (int i = 0; i < str.size(); i++) {
			char now = str[i];

			//스택의 가장 최근 값이 현재 값과 맞물리면 스택 최근 값 pop
			//그 외에는 현재 값 스택에 push
			if (s.empty()) s.push(now);
			else if (s.top() == '(' && now == ')') s.pop();
			else s.push(now);
		}

		if (s.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}