#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
deque<int> num_arr;
vector<char>ans;
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	string P;
	int n;
	string arr;

	cin >> tc;
	//R ������, D ������ 
	//�迭�� ����ִµ� D�� ����� ��� ���� �߻�

	for (int i = 0; i < tc; i++) {
		num_arr.clear();
		int flag = 0;
		int isReverse = 0;
		cin >> P >> n >> arr;
		ans.push_back('[');

		string temp = "";
		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] >= '0' && arr[i] <= '9') {
				temp += arr[i];
			}
			if (arr[i] == ',' || arr[i] == ']' && temp!="") {
				num_arr.push_back(atoi(temp.c_str()));
				temp = "";
			}
			
		}


		for (int i = 0; i < P.length(); i++) {
			if (P[i] == 'R') {
				isReverse = !isReverse;
			}
			if (P[i] == 'D') {
				if (num_arr.empty()) {
					cout << "error" << endl;
					flag = 1;
					break;
				}
				else {
					if (isReverse)
						num_arr.pop_back();
					else
						num_arr.pop_front();
				}
			}
		}

		if (flag) continue;

		if (num_arr.empty()) {
			cout << "[]" << endl;
		}
		else {
			if (isReverse) {
				cout << "[";
				while (num_arr.size() > 1) {
					cout << num_arr.back() << ",";
					num_arr.pop_back();
				}
				cout << num_arr.back() << "]" << endl;
			}
			else {
				cout << "[";
				while (num_arr.size() > 1) {
					cout << num_arr.front() << ",";
					num_arr.pop_front();
				}
				cout << num_arr.front() << "]" << endl;
			}
		}
	}


	return 0;
}