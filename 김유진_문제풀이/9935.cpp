#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	deque<char> result;
	string str, bombStr;
	cin >> str >> bombStr;
	
	for (char s : str) {
		bool check = true;

		result.push_back(s);

		// ���� ���ڿ��� �˻��� ������ ���� ������ ���
		if (result.size() < bombStr.size() || s != result.back()) continue;

		// ���� ���ڿ� �˻�
		for (size_t i = 0; i < bombStr.size(); i++) {
			if (result[result.size() - i - 1] != bombStr[bombStr.size() - i - 1]) {
				check = false;
				break;
			}
		}

		// ���� ���ڿ��̸� ����
		if (check) {
			for (size_t i = 0; i < bombStr.size(); i++) result.pop_back();
		}
	}

	if (result.size() == 0) {
		cout << "FRULA";
	}
	else {
		for (size_t i = 0; i < result.size(); i++) {
			cout << result[i];
		}
	}
	cout << "\n";

	return 0;
}