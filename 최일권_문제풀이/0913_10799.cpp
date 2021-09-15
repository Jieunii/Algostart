#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	//( 이 들어오면 )를 찾는다
	//) 앞에 (이 있으면 레이저
	//쇠막대기는 자신보다 긴 막대기 위에서만 존재

	//()레이저  ( ( ( () () ) ( () ) () ) )  ( () )
	//stack에 ( 들어올 때마다 ( 추가 )들어오면 stack size 만큼 추가

	string razor;
	int ans = 0;
	stack<char> bracket;
	cin >> razor;

	for (int i = 0; i < razor.length(); i++) {
		if (razor[i] == '(') {
			bracket.push(razor[i]);
		}
		else if (razor[i] == ')') {
			if (razor[i - 1] == '(') {
				//레이저로 자르기
				//막대기... 자른 조각 어떻게 세지...
				bracket.pop();
				ans += bracket.size();

			}
			else if (razor[i - 1] == ')') {
				bracket.pop();
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}