// c개의 문자를받아                     
// l개의 단어를 선택하는 문제             => Lv = l, br =2(O,X) 
// 알파벳이 오름차순으로 정렬되어있어야함  -> 가지치기 조건
// 실패!!! 예제는 출력되는데 어디서 걸리는지를 모르겠음!!!!!!!!!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int l, c;
vector<char> alphabet;
char path[20];
bool used[20];

bool isValid() {
	int ja = 0, mo = 0;
	for (int i = 0; i < l; i++) {
		if (path[i] == 'a' || path[i] == 'e' || path[i] == 'i' || path[i] == 'o' || path[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}
	}

	if (mo >= 1 && ja >= 2) {
		return true;
	}
	else false;

}

void make_password(int Lv) {

	// 백트래킹 조건 1. 알파벳이 오름차순
	if (Lv > 1 && path[Lv - 1] < path[Lv - 2]) return;

	// 바닥조건
	if (Lv == l) {
		
		// 자음 모음 개수 확인
		if (isValid() == true) {
			for (int i = 0; i < Lv; i++) {
				cout << path[i];
			}
			cout << endl;
		}
		
		return;
	}

	for (int x = 0; x < c; x++) {
		
		if (used[x] == 1) continue;

		used[x] = 1;
		path[Lv] = alphabet[x];

		make_password(Lv + 1);

		used[x] = 0;
		path[Lv] = 0;
	}
	
}


int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		char tmp;
		cin >> tmp;
		alphabet.push_back(tmp);
	}

	sort(alphabet.begin(), alphabet.end());

	make_password(0);

}