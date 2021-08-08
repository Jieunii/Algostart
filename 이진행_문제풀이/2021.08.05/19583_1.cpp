/*
동작은 하는데 시간초과
설계를 다시해야할듯
=> 다 db에 넣지말고, start에 걸리는 애들만 저장하고, end~endstream 참인 애들만 확인
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 사용자 구조체
// id와 채팅 시간을 벡터로 저장
struct user {
	string id;
	vector<int> time;
};

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

// 중복체크 함수
// db에 이미 존재하는 아이디라면 true를 반환
bool checkDuplicate(vector<user> db, string id) {
	bool flag = 0;
	int dbSize = db.size();
	for (int i = 0; i < dbSize; i++) {
		if (id == db[i].id) {
			return true;
		}
	}
	return false;
}


// start이전과, (end,endStream) 사이에 채팅 기록이 있다면 true를 반환한다
bool checkAttendance(vector<int> time, int start, int end, int endStream) {

	int timeSize = time.size();

	bool inFlag = 0;	// 입장 체크
	for (int i = 0; i < timeSize; i++) {
		if (time[i] <= start) {
			inFlag = 1;
			break;
		}
	}

	bool outFlag = 0;	// 퇴장 체크
	for (int i = 0; i < timeSize; i++) {
		if (end <= time[i] && time[i] <= endStream) {
			outFlag = 1;
			break;
		}
	}
	if (inFlag == 1 && outFlag == 1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	// 시간 입력
	string startStr, endStr, endStreamStr;

	cin >> startStr >> endStr >> endStreamStr;

	int start = timeStrToInt(startStr);
	int end = timeStrToInt(endStr);
	int endStream = timeStrToInt(endStreamStr);
	
	// 채팅로그 확인
	/*
	입력 개수를 모를 때 어떻게??
	다 입력하고 ctrl+c?

	cin.eof() : 알고리즘에서 입력값의 범위가 주어지지 않을때 사용.
				파일이 종료될 때 까지 입력을 받는 함수.
				- bool 타입을 가짐
				- 파일의 끝을 의미하는 EOF를 읽게 되면, true 값으로 바뀜
				- 콘솔창에서는 EOF를 수동으로 넣어주어야함, 윈도우 기준 ctrl+z 가 EOF임.
				https://lollolzkk.tistory.com/15

	*/
	
	// 1. 유저의 기록 저장
	vector<user> db;

	string tmpTime, tmpId;
	while (!cin.eof()) {
		cin >> tmpTime >> tmpId;

		// 처음보는 아이디라면 id, time을 db에 추가함
		if (checkDuplicate(db, tmpId) == false) {
			int tmpIntTime = timeStrToInt(tmpTime);
			user tmpUser;

			tmpUser.id = tmpId;
			tmpUser.time.push_back(tmpIntTime);

			db.push_back(tmpUser);
		}
		// 이미 중복아이디면, 시간만 추가함
		else{
			for (int i = 0; i < db.size(); i++) {
				if (tmpId == db[i].id) {
					int tmpIntTime = timeStrToInt(tmpTime);
					db[i].time.push_back(tmpIntTime);
				}
			}
		}
		
	}

	// 2. 출석체크
	// db를 돌며 출석했는지 확인
	int dbSize = db.size();
	int cnt = 0;
	for (int i = 0; i < dbSize; i++) {
		if (checkAttendance(db[i].time, start, end, endStream) == true) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}