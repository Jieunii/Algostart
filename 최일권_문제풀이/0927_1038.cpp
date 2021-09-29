#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int N;
vector<char> path;
queue<string> num[11];
string ans = "";
int k = 9;
void count_num(int start) {

	if (start > 1) {
		string temp = "";
		for (int i = 0; i < start; i++) {
			temp += path[i];
		}
		num[start].push(temp);
	}

	for (char i = '0'; i <= '9'; i++) {
		if (path.size()>=1 && path.back() <= i) continue;
		path.push_back(i);
		count_num(start + 1);
		path.pop_back();
	}
}

int main() {

	//음이 아닌 정수 X의 자릿수가 가장 큰 자릿수부터 작은 자릿수까지 감소한다면, 그 수를 감소하는 수라고 한다. 예를 들어, 
	//321과 950은 감소하는 수지만, 322와 958은 아니다. N번째 감소하는 수를 출력하는 프로그램을 작성하시오. 
	//0은 0번째 감소하는 수이고, 1은 1번째 감소하는 수이다. 만약 N번째 감소하는 수가 없다면 -1을 출력한다.

	//0 1 2 3 4 5 6 7 8 9
	//10 20 21 30 31 32 40 41 42 43 

	cin >> N;
	if (N < 10)
	{
		printf("%d\n", N);
		return 0;
	}
	if (N > 1022) {
		cout << -1 << endl;
		return 0;
	}
	count_num(0);

	for (int i = 2; i <= 10; i++) {
		if (ans != "") break;

		while (!num[i].empty()) {
			k++;
			if (k == N) {
				
				ans = num[i].front();
				break;
			}
			num[i].pop();
		}
	}
	cout << ans << endl;
	return 0;
}