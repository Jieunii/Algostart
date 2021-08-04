#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	int tmp;	

	scanf("%d %d", &n, &k);

	// 입력 받기
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	// 오름차순 정렬
	sort(arr, arr + n); //(O(NlogN)

	// k번째 수 출력
	printf("%d", arr[k - 1]);

	return 0;
}