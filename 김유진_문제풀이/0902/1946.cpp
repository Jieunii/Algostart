//신입사원

#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct node {
	int doc;
	int interview;
};

bool compare(node front, node back) {
	if (front.doc < back.doc) return true;
	if (front.doc >= back.doc)return false;
}

int main() {

	int test_case = 0;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {

		//init
		node arr[100001];
		int cnt = 0;

		//input
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].doc >> arr[i].interview;
		}

		// 서류를 기준으로 오름차순 정렬
		sort(arr, arr + n, compare);


		//1등의 interview등수보다 높은사람은 뽑힌다.
		//뽑힌사람의 interview등수를 기준으로 그 등수보다 높은사람을 또 뽑는다.
		int now = arr[0].interview;
		for (int i = 1; i < n; i++) {
			if (now > arr[i].interview) {
				now = arr[i].interview;
			}
			else {
				cnt++;
			}
		}
		cout << n -cnt << "\n";
	}

	return 0;
}
