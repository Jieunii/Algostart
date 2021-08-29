#include <iostream>

using namespace std;

int signal[100001];
int main()
{
	int N, K, B;
	cin >> N >> K >> B;

	// 고장난 신호등 체크
	for (int i = 0; i < B; i++) {
		int s;
		cin >> s;
		signal[s] = 1;
	}

	// 처음
	int check = 0;
	for (int i = 1; i <= K; i++) {
		check += signal[i];
	}

	// sliding window
	int mini = check;
	for (int i = K + 1; i <= N; i++) {
		check += signal[i];
		check -= signal[i - K];
		if (check < mini) mini = check;
	}
	cout << mini;
	return 0;
}