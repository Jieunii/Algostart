#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0;
	int cnt = 1;
	int prim[10000001];

	for (int i = 2; i <= 10000000; i++) {
		prim[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (prim[i] == 0)
			continue;
		for (int j = i + i; j <= n; j += i) {
			prim[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (prim[i] != 0)
			answer++;
	}

	return answer;
}