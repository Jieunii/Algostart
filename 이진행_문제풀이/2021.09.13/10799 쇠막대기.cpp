#include <iostream>
#include <stack>

using namespace std;

int main(){
	string input;
	stack<char> st;
	
	cin >> input;

	int answer = 0;

	for (int i = 0; i < input.length(); i++) {
		char now = input[i];

		if (now == '(') {
			st.push(now);
		}
		else{
			st.pop();
			if (input[i - 1] == '(') { // '()' 레이저인 경우
				answer += st.size();
			}
			else { // 파이프인경우 
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}
