#include <iostream>
#include <vector>
using namespace std;

int main() {

	int brown, yellow;
	cin >> brown >> yellow;

	//갈색이랑 노란색 가지고 어떻게 찾을까
	//일단 두 수를 더하면 총 칸 수가 나옴
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