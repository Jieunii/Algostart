//압축 : k(q) 형식 문자열 개수 구하기
// - 스택에 복사된 문자열 하나씩 다 저장하려고 하니까 메모리 초과됨
// - 문자열 ,개수를 따로 저장하는 방식으로 변경

#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
using namespace std;

string str;
stack<char> s;
stack<int> len;

int main() {

	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		s.push(str[i]);
		if (str[i] == ')') {
			s.pop();
			int tmp = 0;
			while (1) {
				if (s.top() == '(') {
					s.pop();
					break;
				}
				if (s.top() == 's') {
					tmp += len.top();
					len.pop();
				}
				else tmp++;
				s.pop();
			}
			
			//문자열 k번 반복
			int k = s.top() - '0';
			s.pop();
			tmp = tmp * k;
			len.push(tmp);
			s.push('s');
		}
	}
	
	int s_cnt = 0;
	while (!s.empty()) {
		if (s.top() != 's') s_cnt++;
		s.pop();
	}
	int str_cnt = 0;
	while (!len.empty()) {
		str_cnt += len.top();
		len.pop();
	}
	cout << s_cnt + str_cnt << "\n";
	return 0;
}