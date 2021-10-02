//신규아이디추천

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
	string answer = "";
	for (int i = 0; i < new_id.size(); i++) { // 1
		if ('A' <= new_id[i] && new_id[i] <= 'Z') {
			new_id[i] += 32;
		}
	}
	for (int i = 0; i < new_id.size(); i++) { // 2
		if ('a' <= new_id[i] && new_id[i] <= 'z') answer += new_id[i];
		if ('0' <= new_id[i] && new_id[i] <= '9') answer += new_id[i];
		if (new_id[i] == '_' || new_id[i] == '-' || new_id[i] == '.') answer += new_id[i];
	}
	new_id = answer;
	answer = "";
	int dot = 0;
	for (int i = 0; i < new_id.size(); i++) {//3
		if (new_id[i] == '.') {
			dot++;
			if (dot == 1) answer += new_id[i];
			else if (dot >= 2) {
				dot--;
			}
		}
		else {
			answer += new_id[i];
			dot = 0;
		}
	}
	new_id = answer;
	answer = "";
	for (int i = 0; i < new_id.size(); i++) {//4
		if (i == 0 && new_id[i] == '.') continue;
		if (i == new_id.size() - 1 && new_id[i] == '.') continue;
		answer += new_id[i];
	}
	new_id = answer;
	answer = "";
	if (new_id.size() == 0) new_id += 'a'; // 5
	if (new_id.size() >= 16) { //6
		for (int i = 0; i < 15; i++) {
			if (i == 14 && new_id[i] == '.') break;
			answer += new_id[i];
		}
		new_id = answer;
		answer = "";
	}
	if (new_id.size() <= 2) { //7
		while (new_id.size() != 3) {
			new_id += new_id[new_id.size() - 1];
		}
	}
	answer = new_id;
	return answer;
}