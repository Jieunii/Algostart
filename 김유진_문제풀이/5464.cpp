#include <iostream>
#include <queue>
using namespace std;

int park_empty[101]; //0:비어있음, 1~N: 차있음
int park_fee[101];
int car_weight[2001];
int n, m;
int profit;
queue<int> q;
queue<int> wait;

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> park_fee[i];
	for (int i = 1; i <= m; i++) cin >> car_weight[i];
	for (int i = 1; i <= 2 * m; i++) {
		int line;
		cin >> line;
		q.push(line);
	}

	while (!q.empty()) {
		int car = 0;

		int check = 0;
		//주차장 빈자리 check
		for (int i = 1; i <= n; i++) {
			if (park_empty[i] == 0) {
				check = 1;
			}
		}

		//wait에 차가있고, 빈자리가 생기면
		if (check == 1 && !wait.empty()) {
			car = wait.front();
			wait.pop();
		}

		//그 외
		else {
			car = q.front();
			q.pop();
		}

		int flag = 0;

		if (car > 0) { //주차장으로 들어옴
			for (int i = 1; i <= n; i++) {
				if (park_empty[i] == 0) {
					park_empty[i] = car;
					profit += (park_fee[i] * car_weight[car]);
					flag = 1;
					break;
				}
			}
			if(flag == 0) wait.push(car);
		}
		else { //주차장에서 나감
			car = abs(car);
			for (int i = 1; i <= n; i++) {
				if (park_empty[i] == car) {
					park_empty[i] = 0;
					flag = 1;
					break;
				}
			}
			if (flag == 0) wait.push(-car);
		}
	}

	cout << profit;

	return 0;
}
