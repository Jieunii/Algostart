#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
	int cnt;
	int ans = 0;
	int arr[101] = {};
	int dat[101] = {};
	int N;
	
	queue<int> index[101];
	vector<int> temp;
	cin >> cnt >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		dat[n]++;
		temp.push_back(n);
		index[n].push(i-1);
	}
	

	int k = 0;
	int start = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (k == cnt) {
			start = i;
			break;
		}
		int flag = 0;
		if (k == 0) {
			arr[k++] = temp[i];
			dat[temp[i]]--;
			index[temp[i]].pop();
		}
		else {
			for (int j = 0; j < k; j++) {
				if (arr[j] == temp[i]) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				arr[k++] = temp[i];
				dat[temp[i]]--;
				index[temp[i]].pop();
			}
			else {
				dat[temp[i]]--;
				index[temp[i]].pop();
			}
		}
	}

	for (int i = start; i < temp.size(); i++) {
		int flag = 0;
		int chk = 0;
		for (int j = 0; j < cnt; j++) {
			if (arr[j] == temp[i]) {
				chk = 1;
				dat[arr[j]]--;
				index[arr[j]].pop();
				break;
			}
		}

		if (chk) continue;
		for (int j = 0; j < cnt; j++) {

			if (dat[arr[j]] == 0) {
				arr[j] = temp[i];
				flag = 1;
				dat[temp[i]]--;
				index[temp[i]].pop();
				ans++;
				break;
			}
		}
		if (!flag) {

			int Max = -99999999;
			int M_idx = 0;
			for (int j = 0; j < cnt; j++) {
				if (Max < index[arr[j]].front()) {
					Max = index[arr[j]].front();
					M_idx = j;
				}
			}
			arr[M_idx] = temp[i];
			index[temp[i]].pop();
			dat[temp[i]]--;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}