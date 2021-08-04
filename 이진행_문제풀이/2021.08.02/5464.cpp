#include <iostream>
#include <queue>
#include <vector>

using namespace std;


// 자리가 있으면 빈자리의 인덱스를
// 자리가 없으면 0를 반환 하는 함수
bool isSlotEmpty(vector<int> parkingLot) {

	for (int i = 0; i < parkingLot.size(); i++) {
		if (parkingLot[i] == 0) {
			return true;
		}
	}
	
	return false;
}

int main() {
	//freopen_s(new FILE*, "test.txt", "rt", stdin);

	int n, m;
	
	cin >> n >> m;
	
	vector<int> parkingLot(n,0);	// 주차장
	vector<int> Rs(n);				// 주차장 요금 배율
	vector<int> Wk(m);				// 차량 무게
	queue<int> order;				// 들어오는 순서
	int res=0;						// 일일수입

	// 입력 처리
	for (int i = 0; i < Rs.size(); i++) {
		cin >> Rs[i];
	}

	for (int i = 0; i < Wk.size(); i++) {
		cin >> Wk[i];
	}

	// 2*M개의 출입 처리할때까지 반복
	int car_num;

	for (int i = 0; i < 2*m; i++) {
		cin >> car_num;

		// 들어오는 경우
		if (car_num > 0) {
			// 먼저 큐에 집어넣고 주차장에 빈자리 있나 확인
			order.push(car_num);

			// 빈자리가 없으면? 대기
			if (isSlotEmpty(parkingLot) == 0) { continue; }

			// 빈자리가 있는경우
			int cur_car = order.front();	// 주차장으로 들어옴
			order.pop();				// 기다리는 줄에선 제거

			for (int i = 0; i < parkingLot.size(); i++) {	// 빈자리를 찾아 주차
				if (parkingLot[i] == 0) {
					parkingLot[i] = cur_car;
					//요금 누적
					res += Rs[i] * Wk[cur_car-1];
					break;
				}
			}
		}

		// 나가는 경우
		else {

			// car_num이 저장된 위치를 찾아 parkingLot을 0으로 설정해주면 끝
			for (int i = 0; i < parkingLot.size(); i++) {	// 빈자리를 찾아 주차
				if (parkingLot[i] == abs(car_num)) {
					parkingLot[i] = 0;
					break;
				}
			}

            /////////////////////////////////////////////////
			// 자리가 났는데 큐에 대기중인 차가 있는경우 
            /// 빈자리가 있는 경우와 같은 코드임. 더 깔끔하게 짤 수 있지 않을까???
			if (!order.empty()) {
				int cur_car = order.front();	// 주차장으로 들어옴
				order.pop();				// 기다리는 줄에선 제거

				for (int i = 0; i < parkingLot.size(); i++) {	// 빈자리를 찾아 주차
					if (parkingLot[i] == 0) {
						parkingLot[i] = cur_car;
						//요금 누적
						res += Rs[i] * Wk[cur_car - 1];
						break;
					}
				}
			}
            /////////////////////////////////////////////////
			
		}
		
		
	}
	cout << res;

	return 0;
}