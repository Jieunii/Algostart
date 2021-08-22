#include <iostream>
#include <string>

using namespace std;

int n;
string res;
bool result_found = false;

// 나쁜 수열 판별 함수
// 배열의 마지막과 그 앞칸 (1칸비교)
// 마지막 두칸과 그 앞 두칸 비교 (2칸비교)
// ... 이런식으로 반복하면 마지막은
// 배열의 절반을 나누어 앞과 뒤 배열 비교 (n/2칸 비교)
bool CheckBadSequence(string str) {
	bool check_res = false;
	int str_len = str.length();

	for (int i = 1; i <= (str_len / 2); i++) {
		if (str.substr(str_len - i, i) == str.substr(str_len - (2 * i), i) == true) {
			check_res = true;
			break;
		}
	}

	return check_res;
}

void Backtrack(int lvl) {

	// 가지치기 1. 이미 정답 찾은경우 더이상 찾지 않음
	if (result_found == true) return;

	// 가지치기 2. 나쁜 수열인 경우
	if (CheckBadSequence(res) == true) return;

	if (lvl == n) { // 바닥조건
		cout << res << endl;
		result_found = true;
		return;
	}

	for (char x = '1'; x <= '3'; x++) {
		res += x; // path[lv] = x;
		Backtrack(lvl + 1);
		res.erase(res.length() - 1); // path[lv] = 0;
	}

}

int main() {
	cin >> n;

	Backtrack(0);

	return 0;
}