#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> userIdName; // key : Id, value : Name
	vector<pair<string, string>> message; // InOutChange, Id 형식

	for (int i = 0; i < record.size(); i++) {
		int space1 = record[i].find(" ");
		int space2 = record[i].find(" ", space1 + 1);
		string InOutChange = record[i].substr(0, space1);
		string Id = record[i].substr(space1 + 1, space2 - space1 - 1);
		string Name = record[i].substr(space2+1);

		if (record[i][0] == 'E') {
			userIdName[Id] = Name;
			message.push_back({ InOutChange, Id });
		}
		else if (record[i][0] == 'C') {
			userIdName[Id] = Name;
		}
		else {
			message.push_back({ InOutChange, Id });
		}
		
	}
	for (int i = 0; i < message.size(); i++) {
		if (message[i].first == "Enter") {
			string result = userIdName[message[i].second] + "님이 들어왔습니다.";
			answer.push_back(result);
		}
		else {
			string result = userIdName[message[i].second] + "님이 나갔습니다.";
			answer.push_back(result);
		}
	}

	return answer;
}