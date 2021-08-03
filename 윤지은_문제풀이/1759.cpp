#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[16];
char PW[16]; // 암호 저장 배열

void findPassword(int lev, int start, int mo, int ja) {
	if (lev == L) {
		if (mo < 1 || ja < 2) return; // 최소 모음 1개, 최소 자음 2개여야함
		cout << PW << endl;
		return;
	}
	for (int i = start; i < C; i++) {
		PW[lev] = arr[i];

    // 모음일 때
		if (PW[lev] == 'a' || PW[lev] == 'e' || PW[lev] == 'i' || PW[lev] == 'o' || PW[lev] == 'u') { 
			findPassword(lev + 1, i + 1, mo+1, ja);
		}
    
    // 자음일 때
		else { 
			findPassword(lev + 1, i + 1, mo, ja+1);
		}
	}
	
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	
	// 알파벳 정렬
	sort(arr, arr + C);

	// 암호 만들기
	findPassword(0, 0, 0, 0);
	
	return 0;
}