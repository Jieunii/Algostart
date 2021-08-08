#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// (string)HH:MM => (int)HHMM 함수
int timeStrToInt(string time) {

	string tmp;

	// HH:MM 에서 HHMM만 저장
	tmp += time[0];
	tmp += time[1];
	tmp += time[3];
	tmp += time[4];

	int res = stoi(tmp);

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen_s(new FILE*, "test.txt", "r", stdin);

	// 시간 입력
	string startStr, endStr, endStreamStr;

	cin >> startStr >> endStr >> endStreamStr;

	int start = timeStrToInt(startStr);
	int end = timeStrToInt(endStr);
	int endStream = timeStrToInt(endStreamStr);
	
	// unordered map 사용
	unordered_map<string, int> list;

	string tmpTime, tmpId;
	while (!cin.eof()) {
		cin >> tmpTime >> tmpId;
		int tmpIntTime = timeStrToInt(tmpTime);

		// 시작 이전에 채팅기록이 있으면 맵에 아이디 저장
		if (tmpIntTime <= start) {
			list[tmpId] = 1;
		}

		// 종료~방종 시간에 채팅기록이 있고 && 시작이전에 채팅기록이 있으면 2로 저장
		else if (end <= tmpIntTime && tmpIntTime <= endStream) {
			if (list[tmpId] == 1) {
				list[tmpId] = 2;
			}
		}
	}

	int cnt = 0;
	for (auto it = list.begin(); it != list.end(); it++) { 
		if (it->second == 2) {
			cnt++;
		}
	}

	/*
	auto type ?? 초기화 한 값에 따라 알아서 자료형을 결정해줌
	vector<int>::iterator itr = v.begin() 과 같은 객체 선언을
	auto itr = v.begin()으로 쉽게 처리가능.
	*/

	cout << cnt;

	return 0;
}