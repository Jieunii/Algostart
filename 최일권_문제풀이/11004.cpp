#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, k;

	int*arr;

	scanf("%d %d", &N, &k);

	arr = new int[N];


	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	printf("%d\n", arr[k - 1]);

	delete[] arr;
	return 0;
}