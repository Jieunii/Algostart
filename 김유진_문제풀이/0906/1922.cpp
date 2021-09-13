//��Ʈ��ũ ���� : ũ�罺Į �˰���

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct info {
	int a;
	int b;
	int weight;
};
int n, m, res;
int boss[100001];
vector<info> v;


int Find(int x)
{
	if (boss[x] == x) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y) boss[y] = x;
}

bool findBoss(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

bool compare(info front, info back) {
	return front.weight < back.weight;
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({a, b, c});
	}

	//����ġ�� ����
	sort(v.begin(), v.end(), compare);

	for (int i = 1; i <= n; i++)
	{
		//�ڱ� �ڽ��� �θ�� ����
		boss[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		if (findBoss(v[i].a, v[i].b) == false)
		{
			Union(v[i].a, v[i].b);
			res += v[i].weight;
		}
	}

	cout << res << "\n";
	return 0;
}