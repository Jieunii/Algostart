//과제

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dat[1001] = { 0, };
struct info {
	int grade;
	int day;
};
vector<info> v;

bool cmp(info front, info back) {
	return front.grade > back.grade;
}

int main() {
	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d = 0, w = 0;
		cin >> d >> w;
		v.push_back({ w, d });
	}

	//점수로 내림차순 sort
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		int idx = v[i].day;
		if (dat[idx] == 0) {
			dat[idx] = v[i].grade;
		}
		else {
			while (1) {
				if (idx == 0) break;
				if (dat[idx] == 0) {
					dat[idx] = v[i].grade;
					break;
				}
				idx--;
			}
		}
	}

	//output
	int res = 0;
	for (int i = 1; i <= 1000; i++) {
		res += dat[i];
	}
	cout << res << "\n";
	return 0;
}