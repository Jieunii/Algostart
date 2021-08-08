#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> check;

int main() {
	string S, E, Q, time, name;
	int cnt = 0;
	cin >> S >> E >> Q;

  //ex) 22:00 -> 2200
	int stime = stoi(S.substr(0, 2) + S.substr(3, 2));
	int etime = stoi(E.substr(0, 2) + E.substr(3, 2));
	int qtime = stoi(Q.substr(0, 2) + Q.substr(3, 2));

	while (cin >> time >> name) {
		int t = stoi(time.substr(0, 2) + time.substr(3, 2));
		if (t <= stime) check[name] = 1; // 출석한 사람
		else if (t >= etime && t <= qtime) {
			if (check[name] == 1) check[name] = 2; // 출석 & 퇴실한 사람 
		}
	}

	for (pair<string, int> result : check) {
		if (result.second == 2) cnt++;
	}
	cout << cnt;
}