#include <iostream>
using namespace std;

int main()
{
	int N;
	int height[11] = {};
	int ans[11] = {};

	cin >> N;

	//2 1 1 0
	//일단 0은 제일 큰 사람이거나 제일 왼쪽에 위치
	//모든 사람의 키는 다 다름(1~~N까지)
	//왼쪽 기준으로 자기보다 큰 사람만 셈

	for (int i = 1; i <= N; i++)
	{
		cin >> height[i];
	}
	//2 1 1 0
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ans[j] == 0 && height[i] == 0)//자리가 비어있으면서 자신보다 큰 사람이 없을 경우
			{
				ans[j] = i; // 위치 저장
				break;
			}
			else if (ans[j] == 0) //자리만 비어있을 경우
				height[i]--; //자신보다 큰 사람을 한 명 줄임
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;


	return 0;
}