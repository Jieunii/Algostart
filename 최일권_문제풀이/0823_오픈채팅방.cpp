#include <iostream>
#include<vector>
#include <string>
#include <queue>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

	vector<string> answer;

	vector<string> id;
	vector<string> nickname;
	vector<pair<string,int>>chk;
	for (int i = 0; i < record.size(); i++) {
		int id_idx = record[i].find(" ");
	
		string oper = record[i].substr(0, id_idx);
		
		if (oper == "Enter") {
			int nick_idx = record[i].find(" ", id_idx + 1);
			string nick = record[i].substr(nick_idx + 1, record[i].length() - nick_idx + 1);
			string id_ = record[i].substr(id_idx + 1, 7);
			if (id.size() == 0) {
				id.push_back(id_);
				nickname.push_back(nick);
			}
			else {
				int flag = 0;
				for (int j = 0; j < id.size(); j++) {
					if (id[j] == id_) {
						nickname[j] = nick;
						flag = 1;
						break;
					}
				}
				if (!flag) {
					id.push_back(id_);
					nickname.push_back(nick);
				}
			}
			chk.push_back({ id_,1 });
		}
		if (oper == "Leave") {
			string id_ = record[i].substr(id_idx + 1, 7);
			string nick;
			for (int j = 0; j < id.size(); j++) {
				if (id[j] == id_) {
					nick = nickname[j];
				}
			}
			chk.push_back({ id_,2 });
		}

		if (oper == "Change") {
			int nick_idx = record[i].find(" ", id_idx + 1);
			string nick = record[i].substr(nick_idx + 1, record[i].length() - nick_idx + 1);
			string id_ = record[i].substr(id_idx + 1, 7);
			for (int j = 0; j < id.size(); j++) {
				if (id[j] == id_) {
					nickname[j] = nick;
				}
			}
		}
	}

	for (int i = 0; i < chk.size(); i++) {
		for (int j = 0; j < id.size(); j++) {
			if (chk[i].first == id[j]) {
				if (chk[i].second == 1) {
					answer.push_back(nickname[j] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
				}
				else if (chk[i].second == 2) {
					answer.push_back(nickname[j] + "´ÔÀÌ ³ª°¡¼Ì½À´Ï´Ù.");
				}
			}
		}
	}


	return 0;

}