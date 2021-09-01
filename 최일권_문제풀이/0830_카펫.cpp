#include <iostream>
#include <vector>
using namespace std;

int main() {

	int brown, yellow;
	cin >> brown >> yellow;

	//�����̶� ����� ������ ��� ã����
	//�ϴ� �� ���� ���ϸ� �� ĭ ���� ����
	int arr_size = brown + yellow;
	int hori = 0, ver = 0;
	for (int i = 1; i <= arr_size; i++) {
		if (arr_size%i == 0) {
			int temp = arr_size / i;
			if (temp > i) continue;
			if ((temp - 2)*(i - 2) == yellow)
			{
				hori = i;
				ver = temp;
			}
		}
	}
	cout << hori << " " << ver << endl;

	return 0;
}