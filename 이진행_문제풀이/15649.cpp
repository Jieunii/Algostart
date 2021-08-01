// 1부터 N까지 자연수중에 중복 없이 M개를 고른 수열 => 순열
// branch : n, Level : m인 재귀함수
// path로 경로 출력, used로 사용한 숫자 저장


#include <iostream>

using namespace std;

int path[10] = { 0 };
int used[10] = { 0 };

void recursion(int Lv, int n, int m) {

	if(Lv == m) {

		for (int i = 0; i < Lv; i++) {
			cout << path[i] << " ";
		}cout << '\n';	// endl은 시간초과, \n은 세이프??
		
		return;
	}

	for (int x = 1; x <= n; x++) {
		// 이미 한번 쓴 수인지 확인
		if (used[x] == true) { continue; }

		used[x] = 1;
		path[Lv] = x;

		recursion(Lv + 1, n, m);

		path[Lv] = 0; 
		used[x] = 0;
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	recursion(0, n, m);

	return 0;
}