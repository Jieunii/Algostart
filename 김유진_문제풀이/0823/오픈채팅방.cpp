#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> db;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<int, string> > ord; // first = 0:enter, 1=leave , second = uid

    for (int i = 0; i < record.size(); i++) {
        int idx1 = record[i].find(" ");
        int idx2 = record[i].find(" ", idx1 + 1);
        string uid = record[i].substr(idx1 + 1, idx2 - idx1 - 1);
        string nick = record[i].substr(idx2 + 1);

        if (record[i][0] == 'E') {
            db[uid] = nick;
            ord.push_back({ 0,uid });
        }
        else if (record[i][0] == 'L') {
            ord.push_back({ 1,uid });
        }
        else {
            db[uid] = nick;
        }
    }

    for (int i = 0; i < ord.size(); i++) {
        if (ord[i].first == 0) { //enter
            string alarm = db[ord[i].second] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            answer.push_back(alarm);
        }
        else {//leave
            string alarm = db[ord[i].second] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            answer.push_back(alarm);
        }
    }

    return answer;
}