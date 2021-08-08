#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int N, K, num;
	scanf("%d %d", &N, &K);
	int *arr = new int[N];


	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+N);
	printf("%d", arr[K - 1]);
}