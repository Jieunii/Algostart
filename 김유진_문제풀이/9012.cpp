#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		//���� �ʱ�ȭ
		while(!s.empty()) {
			s.pop();
		}

		//���ڿ� �Է�
		string str = "";
		cin >> str;


		//���ڿ� ���̸�ŭ �ݺ�
		for (int i = 0; i < str.size(); i++) {
			char now = str[i];

			//������ ���� �ֱ� ���� ���� ���� �¹����� ���� �ֱ� �� pop
			//�� �ܿ��� ���� �� ���ÿ� push
			if (s.empty()) s.push(now);
			else if (s.top() == '(' && now == ')') s.pop();
			else s.push(now);
		}

		if (s.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}