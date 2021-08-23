#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

deque<int> numbers;
int flag = 0; // 역순 체크
int error = 0; // 에러 체크

void AC(string func) {
	for (int i = 0; i < func.size(); i++) {
		// R : 숫자 뒤집기
		if (func[i] == 'R') {
			if (flag) flag = 0;
			else flag = 1;
		}
		// D : 첫번째 숫자 버리기
		else {
			if (numbers.empty()) {
				error = 1;
				break;
			}
			// 역순으로
			if (flag) numbers.pop_back();
			// 순서대로
			else numbers.pop_front();
		}
	}

	// 출력
	if (error) {
		cout << "error\n";
		return;
	}
	cout << '[';
	while (!numbers.empty()) {
		int out;
		if (flag) {
			out = numbers.back();
			numbers.pop_back();
			cout << out;
		}
		else {
			out = numbers.front();
			numbers.pop_front();
			cout << out;
		}
		if(!numbers.empty()){
			cout << ",";
		}
	}
	cout << "]\n";
	return;
}

int main()
{
	int T, n;
	cin >> T;
	string p, arr;
	for (int t = 0; t < T; t++) {
		cin >> p >> n >> arr;

		// 숫자만 뽑아서 stack에 넣기
		string numString;
		flag = 0;
		error = 0;
		numbers.clear();

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == '[') continue;
			else if ('0' <= arr[i] && arr[i] <= '9') {
				numString += arr[i];
			}
			else if (arr[i] == ',' || arr[i] == ']') {
				if (numString.size() > 0) numbers.push_back(stoi(numString));
				numString = "";
			}
		}
		// 새로운 언어 AC
		AC(p);
	}
	return 0;
}