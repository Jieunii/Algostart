/*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
	 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/

#include <iostream>
#include <string>

using namespace std;

string solution(string str) {
	string res = str;

	// 1단계 : 모두 소문자로 치환
	for (int i = 0; res[i] != '\0'; i++) {
		if ('A' <= res[i] && str[i] <= 'Z') {
			res[i] = res[i] - 'A' + 'a';
		}
	}

	// 2단계 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거

	string temp;
	for (int i = 0; res[i] != '\0'; i++) {
		if (('a' <= res[i] && res[i] <= 'z') ||
			('0' <= res[i] && res[i] <= '9') ||
			(res[i] == '-') || (res[i] == '_') || (res[i] == '.')) {
			temp += res[i];
		}
	}
	res = temp;

	// 3단계 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
	temp.clear();
	int pos = 0;
	if (res.length() != 0) {
		temp += res[pos++];
		while (pos != res.length()) {
			if (temp[temp.length() - 1] == '.' && res[pos] == '.') { pos++; } // temp에 마지막 문자가 .이고, 현재 옮길 문자가 .이면 패스
			else {
				temp += res[pos++];
			}
		}
	}
	res = temp;

	// 4단계 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
	if (res.length() != 0 && res[0] == '.') { res.erase(0, 1); }
	if (res.length() != 0 && res[res.length() - 1] == '.') { res.erase(res.length() - 1, 1); }
	

	// 5단계 : 만약 빈 문자열인경우, "a"를 대입
	if (res.length() == 0) {
		res += "a";
	}

	// 6단계 : 16자 이상이면 16자에서 자름
	if (res.length() >= 16) {
		res = res.substr(0, 15);
		if (res[res.length() - 1] == '.') { res.erase(res.length() - 1, 1); }
	}


	// 7단계 : 길이가 2자 이하라면, 길이가 3이 될때까지 마지막 문자를 붙인다
	else if (res.length() <= 2) {
		char ch = res[res.length() - 1];
		while (res.length() < 3) {
			res += ch;
		}
	}

	string answer = res;
	return answer;
}

int main() {
	string str[6]{ 
		"",
		"...!@BaT#*..y.abcdefghijklm.",
		"z-+.^.",
		"=.=",
		"123_.def",
		"abcdefghijklmn.p"
	};


	for (int i = 0; i < 6; i++) {
		cout << solution(str[i]) << endl;
	}
	
	// cout << solution(str[1]) << endl;

	return 0;
}