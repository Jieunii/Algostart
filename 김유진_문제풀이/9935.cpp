#include <iostream>
#include <string>
using namespace std;

string res;
string temp;

int main() {

	string str = "", bomb = "";
	cin >> str >> bomb;

	int bomb_size = bomb.size();
	for (int i = 0; i < str.size(); i++) {//입력문자열을 한번 순회
		res += str[i];
		int res_size = res.size(); 

		//가장 최근에 들어간 문자와 폭탄의 마지막 문자랑 같으면
		if (res[res_size - 1] == bomb[bomb_size - 1]) {

			if (res_size >= bomb_size) {
				//res에 저장하던 문자열에서 bomb크기만큼 뒤에서 뽑아서 temp저장
				temp = res.substr(res_size - bomb_size, bomb_size);

				//temp랑 bomb이랑 문자열이 같으면 지우기
				if (temp == bomb) {
					res.erase(res_size - bomb_size, bomb_size);
				}
			}
		}
	}

	if (res == "") cout << "FRULA";
	else cout << res;

	return 0;
} 