#include <iostream>
#include <map>
#include <string>
using namespace std;

string s;
string e;
string q;
string t, name;
int res;
map<string, int> part; //state 2: 입퇴장 완료, 1:입장만완료 (1/0으로 하면 틀렸습니다 나옴..)

int main() {

	cin >> s >> e >> q;
	int sh = stoi(s.substr(0, 2));
	int sm = stoi(s.substr(3, 2));
	int shm = sh * 60 + sm;
	int eh = stoi(e.substr(0, 2));
	int em = stoi(e.substr(3, 2));
	int ehm = eh * 60 + em;
	int qh = stoi(q.substr(0, 2));
	int qm = stoi(q.substr(3, 2));
	int qhm = qh * 60 + qm;

	
	while (!cin.eof()) {

		cin >> t >> name;

		int hh = stoi(t.substr(0, 2));
		int mm = stoi(t.substr(3, 2));
		int hhmm = hh * 60 + mm;

		//시작시간보다 작거나 같으면 입장
		if (0 <= hhmm && hhmm <= shm) {
			part.insert(make_pair(name, 1));
		}

		//e시간과 q시간 사이면 퇴장
		else if (ehm <= hhmm && hhmm <= qhm) {
			if (part[name] == 1) {
				part[name] = 2;
				res++;
			}
		}
	}

	cout << res;

	return 0;
}
