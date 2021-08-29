#include <iostream>

using namespace std;

int check[1001];
int main()
{
	int N, K;
	cin >> N >> K;
	int cnt = 0, result;

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (check[j] == 0) {
				check[j] = 1;
				cnt++;
			}
			if (cnt == K) {
				result = j;
				break;
			}
		}
		if (cnt == K) {
			cout << result;
			return 0;
		}
	}
	return 0;
}