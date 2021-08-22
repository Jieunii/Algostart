#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string permu;
int cnt = 0;
void good_permu(int level) {
	int half = N / 2;
	for (int i = 1; i <= level/2; i++) {
		if (equal(permu.end() - i, permu.end(), permu.end() - i * 2)) //end-i번째 부터 end까지의 숫자와 end-i*2번째 위치에서 end-1~end까지의 숫자 비교
			return;
	}
	
	if (level == N) {
		//길이가 2, ~~ half 까지 검사
		cout << permu << endl;
		exit(0);
		return;
	}
	//바로 뒤에만 검사하자...
	for (int i = 1; i <= 3; i++) {
		permu.push_back(i+'0');
		good_permu(level + 1);
		permu.pop_back();

	}
}

int main() {

	cin >> N;

	good_permu(0);

	return 0;
}