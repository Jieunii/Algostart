#include <iostream>
#include <string>
#include <vector>

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
	
	string tmpTime, userId;
	vector<string> inList;
	vector<string> outList;

	while (!cin.eof()) {
		cin >> tmpTime >> userId;
		int userTime = timeStrToInt(tmpTime);
		// 시간 시간전까지 아이디를 기록
		if (userTime <= start) {
			bool flag = 0;
			for (int i = 0; i < inList.size(); i++) {
				if (inList[i] == userId) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				inList.push_back(userId);
			}
		}

		// 출석 인정시간 사이에 채팅기록이 있는 아이디를 기록
		if (end <= userTime && userTime <= endStream) {
			bool flag = 0;
			for (int i = 0; i < outList.size(); i++) {
				if (outList[i] == userId) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				outList.push_back(userId);
			}
		}
	}

	// 두 리스트에 있는 사람만 인정
	int inListSize = inList.size();
	int outListSize = outList.size();
	int cnt = 0;

	for (int i = 0; i < inListSize; i++) {
		for (int j = 0; j < outListSize; j++) {
			if (inList[i] == outList[j]) {
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}