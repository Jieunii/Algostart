#include <iostream>
#include <string>
#include <deque>
using namespace std;

int t;
string p;
int n;
string arr;

int main() {

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> p;
		cin >> n;
		cin >> arr;
		deque<int> dq;

		int start = 1;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] == ',' || arr[j] == ']') {
				if (j - start > 0) {
					int num = stoi(arr.substr(start, j - start));
					start = j + 1;
					dq.push_back(num);
				}
			}
		}

		int flag = 0;
		int pointer = 0; //0¾Õ, 1µÚ
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R') {
				if (pointer == 0) pointer = 1;
				else pointer = 0;
			}
			else { //'D'
				if (!dq.empty()) {
					if (pointer == 0) dq.pop_front();
					else dq.pop_back();
				}
				else {
					cout << "error" << "\n";
					flag = 1;
					break;
				}
			}
		}

		//output
		if (!flag) {
			string res = "[";
			if (pointer == 0) {
				while (!dq.empty()) {
					res += to_string(dq.front());
					res += ",";
					dq.pop_front();
				}
			}
			else {
				while (!dq.empty()) {
					res += to_string(dq.back());
					res += ",";
					dq.pop_back();
				}
			}
			if (res[res.size() - 1] == ',') res[res.size() - 1] = ']';
			else res += "]";

			cout << res << "\n";
		}
	}

	return 0;
}