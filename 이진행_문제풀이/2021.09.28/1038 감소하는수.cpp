/* 감소하는수 : 987654321 처럼 가장 큰 자릿수부터 작은 자릿수까지 감소하는 수
n 번쨰 감소하는 수를 구하는 문제

=> 
한자리수 : 0 1 2 3 4 5 6 7 8 9 (0번째, 1번째 ,... , 9번째)
두자리수 : 10 21 20 32 31 30 ... 95 94 93 92 91 90 (10번째, 11번째, ... ,55번째)
...

문자열을 이용해 str[i] > str[i-1]일때만 DFS를 계속 들어가게 한다
DFS(LV, 자리수, "")로 한자리수일때, 두자리수일때, ... 최대 열자리수일때까지 구해봄


*/

#include <iostream>
#include <string>

using namespace std;

int n;
int cnt = 0;
bool answer_found = false;

// Lv : 7, br: 10인 DFS
void DFS(int Lv, int MAX, string str) {
	if (answer_found == true) return;
	if (Lv == MAX) {
		if (cnt == n) {
			cout << str << endl;
			answer_found = true;
		}
		cnt++;
		
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (str != "" && str[str.length() - 1] <= i + '0')	continue;

		str += (i + '0');

		DFS(Lv + 1, MAX, str);

		str.erase(str.length() - 1);
	}

}

int main() {
	cin >> n;
	for (int i = 1; i <= 10; i++) {
		DFS(0, i, "");
	}
	if (answer_found == false) {
		cout << -1;
	}

	return 0;
}