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
		if (equal(permu.end() - i, permu.end(), permu.end() - i * 2)) //end-i��° ���� end������ ���ڿ� end-i*2��° ��ġ���� end-1~end������ ���� ��
			return;
	}
	
	if (level == N) {
		//���̰� 2, ~~ half ���� �˻�
		cout << permu << endl;
		exit(0);
		return;
	}
	//�ٷ� �ڿ��� �˻�����...
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