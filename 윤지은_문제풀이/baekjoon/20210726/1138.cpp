#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int p;
	int result[11] = {0};

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p;
		for (int j = 1; j <= N; j++) {
			if (p == 0 && result[j] == 0) { // Ű ū ��� �������� �ڸ� o
				result[j] = i;
				break;
			}
			else if (result[j] == 0) { // Ű ū ��� ��������
				p--;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << result[i] << " ";
	}
}