#include <iostream>
#include<vector>
#include <string>
#include <queue>
#include<algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	vector<string> answer;

	unordered_map<string, string> enter;
	unordered_map<string, string>leave;
	unordered_map<string, string> nick;
	for (int i = 0; i < record.size(); i++)
	{
		int id_idx = record[i].find(" ");
		int nick_idx = record[i].find(" ", id_idx + 1);
		string oper = record[i].substr(0, id_idx);

		if (oper == "Enter") {
			string id = record[i].substr(id_idx + 1, nick_idx - id_idx - 1);
			int nick_idx = record[i].find(" ", id_idx + 1);
			string nickname = record[i].substr(nick_idx + 1, record[i].length() - nick_idx);
			nick[id] = nickname;
			enter[id] = nick[id] + "님이 들어왔습니다.";
			if (leave.size() != 0) {
				leave[id] = nick[id] + "님이 나갔습니다.";
			}
		}
		if (oper == "Leave") {
			string id = record[i].substr(id_idx + 1, record[i].length() - id_idx);
			leave[id] = nick[id] + "님이 나갔습니다.";
		}
		if (oper == "Change") {
			string id = record[i].substr(id_idx + 1, nick_idx - id_idx - 1);
			int nick_idx = record[i].find(" ", id_idx + 1);
			string nickname = record[i].substr(nick_idx + 1, record[i].length() - nick_idx);
			nick[id] = nickname;
			enter[id] = nickname + "님이 들어왔습니다.";
			leave[id] = nickname + "님이 나갔습니다.";
		}
	}

	for (int i = 0; i < record.size(); i++)
	{
		int id_idx = record[i].find(" ");
		int nick_idx = record[i].find(" ", id_idx + 1);
		string oper = record[i].substr(0, id_idx);
		string id = record[i].substr(id_idx + 1, nick_idx - id_idx - 1);

		if (oper == "Enter") {
			answer.push_back(enter[id]);
		}
		if (oper == "Leave") {
			answer.push_back(leave[id]);
		}
	}


	
	return 0;

}
