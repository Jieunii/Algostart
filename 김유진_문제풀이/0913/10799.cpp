//�踷���
#include <iostream>
#include <string>
using namespace std;

string bar;

int main() {

	cin >> bar;

	int bar_cnt = 0;
	int res = 0;
	for (int i = 0; i < bar.size() - 1; i++) {
		if (bar[i] == '(') {
			if (bar[i + 1] == ')') {// ������
				res += bar_cnt;
			}
			else {// ����� ����
				bar_cnt++;
				res++;
			}
		}
		else {
			if (bar[i - 1] == ')') {// ����� ��
				bar_cnt--;
			}
		}
	}

	cout << res << "\n";

	return 0;
}