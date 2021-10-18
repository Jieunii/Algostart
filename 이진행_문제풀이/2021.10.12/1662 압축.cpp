/* 
압축된 문자열 S를 받고, 이를 압축 해제해서 원래 문자열의 길이를 구하는 문제
K(Q) : Q라는 문자열이 K번 반복된다. (K는 한자리수)

ex) 33(562(71(9)))
= 3 3(56 2(7 1(9) ) ) )
= 3 3(56 2(7 9) ) )
= 3 3(56 79 79)
= 3 567979 567979 567979 => 19글자

풀이)
{문자, 길이}를 가지는 구조체와 스택 사용.
스택을 이용해 여는 괄호가 나오면 글자수 카운트를 시작하고, 
닫는 괄호가 나오면 반복횟수 * 글자수 만큼 길이를 추가한다

*/
#include <iostream>
#include <string>
#include <stack>

struct node {
	char ch; // 문자 
	int len; // 길이
};

using namespace std;

int main() {
	string str = "33(562(71(9)))";
	stack<node> st;
	int strSize = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ')') {
			while (1) {
				if (st.top().ch == '(') {
					st.pop();
					int num = st.top().ch - '0'; // 몇번 반복할건지
					st.top().len = num * strSize;
					strSize = 0;
					break;
				}
				strSize += st.top().len;
				st.pop();
			}
		}
		else {
			st.push({ str[i], 1 });
		}
	}
	int answer = 0;
	while (!st.empty()) {
		answer += st.top().len;
		st.pop();
	}

	cout << answer;

	return 0;
}