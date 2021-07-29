#include <iostream>
using namespace std;

int main() {
	int pos[11] = { 0 }; 
	int n;
	int rank;
	
	cin >> n;

	// n번 반복
	for (int i = 1; i <= n; i++) {
		cin >> rank;	// 앞에 키큰사람이 몇명있었는지 확인
		
		for (int j = 1; j <= n; j++) { // 배열 끝까지 돌면서 자신이 들어갈 자리를 확인한다.
			if (rank == 0 && pos[j] == 0) {	// 자신이 들어갈 자리라면
				pos[j] = i;
				break;
			}
			else if (pos[j] == 0) {
				rank--;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << pos[i] << " ";
	}

	return 0;
}