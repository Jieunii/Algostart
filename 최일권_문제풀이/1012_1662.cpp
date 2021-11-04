#include <iostream>
#include <stack>
#include <string>
using namespace std;

int visited[51] = {};
string zip = "";
int unzip(int index){
	int cnt = 0;

	for (int i = index; i < zip.length(); i++) {
		if (zip[i] == '(' && !visited[i]) {
			visited[i] = 1;
			int mul = zip[i - 1] - '0';
			cnt--;//곱해주는 수 빼주기
			cnt += mul * unzip(i + 1); //재귀 호출로 괄호 안의 수 세기
		}
		else if (zip[i] == ')' && !visited[i]) {
			visited[i] = 1;
			return cnt;//닫힌 괄호로 위의 식 계산
		}
		else if ((zip[i] >= '0' && zip[i] <= '9' )&& !visited[i]) {
			visited[i] = 1;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	
	int ans = 0;
	int temp = 0;
	cin >> zip;

	int ret = unzip(0);
	
	cout << ret << endl;

	return 0;
}
