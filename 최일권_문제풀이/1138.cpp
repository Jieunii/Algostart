#include <iostream>
using namespace std;

int main()
{
	int N;
	int height[11] = {};
	int ans[11] = {};

	cin >> N;

	//2 1 1 0
	//�ϴ� 0�� ���� ū ����̰ų� ���� ���ʿ� ��ġ
	//��� ����� Ű�� �� �ٸ�(1~~N����)
	//���� �������� �ڱ⺸�� ū ����� ��

	for (int i = 1; i <= N; i++)
	{
		cin >> height[i];
	}
	//2 1 1 0
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ans[j] == 0 && height[i] == 0)//�ڸ��� ��������鼭 �ڽź��� ū ����� ���� ���
			{
				ans[j] = i; // ��ġ ����
				break;
			}
			else if (ans[j] == 0) //�ڸ��� ������� ���
				height[i]--; //�ڽź��� ū ����� �� �� ����
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;


	return 0;
}