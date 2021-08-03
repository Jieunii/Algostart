#include <iostream>
#include <vector>
using namespace std;

int n;
int capa[21][21];
int team[21]; //1: start team, 0:link team
vector<int> s;
vector<int> l;
int res = 21e8;

//��ŸƮ���� ��ũ���� �ɷ�ġ ����
void diff() {
	int start = 0;
	int link = 0;

	for (int i = 0; i < l.size(); i++) {
		for (int j = 0; j < l.size(); j++) {
			link += capa[l[i]][l[j]];
		}
	}
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			start += capa[s[i]][s[j]];
		}
	}
	if (res > abs(start - link)) res = abs(start - link);

}

//�� �����ϴ� �Լ� - ����
void select_team(int depth, int index) {
	if (depth == n / 2) {

		s.clear();
		l.clear();

		//���� ���Ϳ� ����
		for (int i = 1; i <= n; i++) {
			if (team[i] == 1) s.push_back(i);
			else l.push_back(i);
		}

		diff();
		return;
	}

	for (int i = index; i <= n; i++) {
		team[i] = 1;
		select_team(depth + 1, i + 1);
		team[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> capa[i][j];
		}
	}

	//�����ϱ�
	select_team(0, 1);

	cout << res;

	return 0;
}
