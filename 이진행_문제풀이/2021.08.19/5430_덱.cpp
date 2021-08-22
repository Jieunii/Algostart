#include <iostream>
#include <string>
#include <deque>

using namespace std;

// [x_1, ... , x_n] 형태의 str을
// dq(n) 덱에 숫자만 분류해서 저장한다
void parseArr(deque<string>* dq, string str) {
	if (dq->size() == 0) return; // n이 0이라 못넣음
	
	string tmp = str.substr(1, str.length() - 2); 
	tmp += ",";

	// 1,2,3,4,

	int a = 0;
	int b = 0;
	int idx = 0;

	while (1) {
		a = tmp.find(",", a);
		if (a == -1) break;

		if (idx == 0) { // 첫번째 원소 넣기
			dq->at(idx) = tmp.substr(0,a); 
			idx++;
			continue;
		}

		b = tmp.find(",", a+1);
		if (b == -1) break;

		dq->at(idx) = tmp.substr(a+1, b-a-1);
		idx++;

		a = b;
	}
}


void PrintDq(deque<string> dq, bool flag) {
	int dq_size = dq.size();

	if (dq_size == 0) {	// 배열이 빈 경우
		cout << "[]" << '\n';
		return;
	}

	string res = "[";

	if (flag == false) { // 정방향 출력
		for (int i = 0; i < dq_size; i++) {
			res += dq[i] + ",";
		}
		
	}
	else { // 역방향 출력
		for (int i = dq_size - 1; i >= 0; i--) {
			res += dq[i] + ",";
		}
	}

	res.erase(res.length() - 1); // 마지막 , 제거
	res += "]";

	cout << res << '\n';
	return;

}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	int t, n;
	string p;
	string tmp;

	cin >> t;

	while (t--) {
		cin >> p >> n;
		cin >> tmp;

		deque<string> dq(n);
		bool reverse_toggle = false; // 정방향 출력
		bool print_flag = true;
		parseArr(&dq, tmp);

		for (int i = 0; i < p.size(); i++) {

			if (p[i] == 'R') { reverse_toggle = !reverse_toggle; }

			else if (p[i] == 'D') { 
				if (dq.size() == 0) { 
					cout << "error" << '\n'; 
					print_flag = false;
					break; 
				}
				else {
					if (reverse_toggle == false) {
						dq.pop_front(); 
					}
					else {
						dq.pop_back();
					}
				}
			}
		}
		if (print_flag == true) {
			PrintDq(dq, reverse_toggle);
		}
	}

	return 0;
}