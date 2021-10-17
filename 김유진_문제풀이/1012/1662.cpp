//���� : k(q) ���� ���ڿ� ���� ���ϱ�
// - ���ÿ� ����� ���ڿ� �ϳ��� �� �����Ϸ��� �ϴϱ� �޸� �ʰ���
// - ���ڿ� ,������ ���� �����ϴ� ������� ����

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
			
			//���ڿ� k�� �ݺ�
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