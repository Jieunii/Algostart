#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

int parking[101];
int parking_fee[101];
int car_weight[2001];
int income = 0;


queue<int> q;
queue<int> wait_queue;
int main()
{
	//freopen_s(new FILE *, "Text.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> parking_fee[i];
	for (int i = 0; i < M; i++) cin >> car_weight[i];
	for (int i = 0; i < 2 * M; i++) {
		int order;
		cin >> order;
		q.push(order);
	}

	int space = N; // 주차공간
	while (!q.empty()) {
		int car = q.front();
		q.pop();

		// 주차장으로 들어옴
		if (car > 0) { 
			// 주차장 빈자리 체크
			if (space == 0) wait_queue.push(car);
			for (int i = 0; i < N; i++) {
				if (parking[i] == 0) {
					parking[i] = car;
					space--;
					break;
				}
			}
		}
		// 주차장에서 나감
		else { 
			car = abs(car);
			for (int i = 0; i < N; i++) {
				if (parking[i] == car) {
					parking[i] = 0;
					space++;
					// 빈자리 생기면 바로 주차시킨다
					if (!wait_queue.empty()) {
						int wait_car = wait_queue.front();
						wait_queue.pop();
						for (int i = 0; i < N; i++) {
							if (parking[i] == 0) {
								parking[i] = wait_car;
								space--;
								break;
							}
						}
					}
					// 주차료 계산
					income += parking_fee[i] * car_weight[car - 1];
					break;
				}
			}
		}
	}
	cout << income;
	return 0;
}