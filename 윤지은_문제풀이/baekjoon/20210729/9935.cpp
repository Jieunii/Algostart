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

		// 폭발 문자열을 검색할 조건이 나올 때까지 대기
		if (result.size() < bombStr.size() || s != result.back()) continue;

		// 폭발 문자열 검색
		for (int i = 0; i < bombStr.size(); i++) {
			if (result[result.size() - i - 1] != bombStr[bombStr.size() - i - 1]) {
				check = false;
				break;
			}
		}

		// 폭발 문자열이면 제거
		if (check) {
			for (int i = 0; i < bombStr.size(); i++) result.pop_back();
		}
	}

	if (result.size() == 0) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
		}
	}
	cout << "\n";

	return 0;
}