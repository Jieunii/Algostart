#include <iostream>
#include <map>
#include <string>
using namespace std;

string s;
string e;
string q;
string t, name;
int res;
map<string, int> part; //state 2: ������ �Ϸ�, 1:���常�Ϸ� (1/0���� �ϸ� Ʋ�Ƚ��ϴ� ����..)

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

		//���۽ð����� �۰ų� ������ ����
		if (0 <= hhmm && hhmm <= shm) {
			part.insert(make_pair(name, 1));
		}

		//e�ð��� q�ð� ���̸� ����
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