#include <iostream>
#include <vector>
using namespace std;

int M, N;
int Select[9] = {};
vector<int> arr;
void print()
{
	for (int i = 0; i < arr.size(); i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void dfs(int num)
{
	if (num == M)
	{
		print();
		return;
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (Select[i] == 1) continue;

		Select[i] = 1;
		arr.push_back(i);
		dfs(num + 1);
		arr.pop_back();
		Select[i] = 0;
	}

}


int main()
{

	scanf("%d %d", &N, &M);

	//N까지 M의 길이의 수열 구하기

	dfs(0);

	return 0;
}