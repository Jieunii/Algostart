#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> user_db; // uid, nickname을 저장하는 db
vector< pair<string, string> > log_db; // uid, cmd를 저장하는 db

vector<string> solution(vector<string> record) {
	vector<string> answer;

	for (int i = 0; i < record.size(); i++) {

		// 1. 문자열 파싱 부분
		int a = record[i].find(" ");
		int b = record[i].find(" ", a + 1);
		
		string cmd = record[i].substr(0, a);
		string id = record[i].substr(a + 1, b - a - 1);
		string name; 
		if (b != -1) { // Leave는 cmd와 id만 받음
			name = record[i].substr(b + 1, record[i].length()-1);
		}

		// 2. 명령어 처리 부분
		if (cmd == "Leave") {
			// user_db.erase(id); // 실제로 지우면 안되고, 로그만 추가해둠
			log_db.push_back(make_pair(id, cmd));
		}
		else if (cmd == "Enter") {
			// Leave에서 실제로 지우지 않았기 때문에 
			// user_db맵에 기존값이 있어 삽입이 안됨!
			if (user_db.find(id) != user_db.end()) { // 이를 위해 삭제 후 삽입 시도
				user_db.erase(id);
			}
			user_db.insert(make_pair(id, name));
			log_db.push_back(make_pair(id, cmd)); 
		}
		else if (cmd == "Change") {
			// user_db의 name을 수정해줌. 마지막에 이를 참조해서 출력
			if (user_db.find(id) != user_db.end()) {
				user_db.erase(id);
				user_db.insert(make_pair(id, name));
			}
			// 아이디 변경은 별도로 로그에 추가하지 않음
		}
		
	}

	// 최종 로그를 answer에 저장
	for (int i = 0; i < log_db.size(); i++) {
		string res;
		if (log_db[i].second == "Enter") {
			res += user_db[log_db[i].first] + "님이 들어왔습니다." ;
		}
		else if (log_db[i].second == "Leave") {
			res += user_db[log_db[i].first] + "님이 나갔습니다.";
		}
		answer.push_back(res);
	}

	return answer;
}


int main() {
	vector<string> record = {
		"Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan",
		"Enter uid1234 Prodo",
		"Enter uid0000 SUDO",
		"Leave uid0000",
	};

	/*
	1. 무지님이 들어왔습니다
	2. 무지님이 들어왔습니다
		프로도님이 들어왔습니다
	3. 무지님이 들어왔습니다
		프로도님이 들어왔습니다
		무지님이 나갔습니다
	4. 프로도(2)님이 들어왔습니다
		프로도(1)님이 들어왔습니다
		프로도(2)님이 나갔습니다
		프로도(2)님이 들어왔습니다
	5. 프로도(2)님이 들어왔습니다
		라이언님이 들어왔습니다
		프로도(2)님이 나갔습니다
		프로도(2)님이 들어왔습니다
	*/

	vector<string> res = solution(record);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}