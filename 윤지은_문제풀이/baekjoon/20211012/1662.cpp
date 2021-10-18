#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str; // 압축된 문자열
stack<pair<char, int>> st; // <문자, 길이> 정보 담는 stack

int main() {
	cin >> str;
	int Qcnt = 0;

	for (char c : str) {
		if (c == ')') {
			while (1) {
				if (st.top().first == '(') {
					st.pop();
					int K = st.top().first - '0'; // 반복 횟수
					st.top().second = K * Qcnt; // 길이 갱신
					Qcnt = 0;
					break;
				}
				Qcnt += st.top().second;
				st.pop();
			}
		}
		else st.push({ c, 1 });
	}

	int answer = 0;
	while (!st.empty()) {
		answer += st.top().second;
		st.pop();
	}

	cout << answer;
	return 0;
}
