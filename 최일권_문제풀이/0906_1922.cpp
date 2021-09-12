#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr{10001};

int findboss(int member) {
	if (arr{member} == 0) {
		return member; //자기가 보스일 때
	}
	int boss = findboss(arr{member});
	return boss;
}

void setunion(int a, int b) {

	int aboss = findboss(a);
	int bboss = findboss(b);

	if (aboss == bboss) return;
	arr{bboss} = aboss;

}
struct node {
	int a;
	int b;
	int c;
};
bool compare(node a, node b) {
	if (a.c > b.c) return false;
	if (a.c < b.c)return true;
	return false;
}
int main()
{
	int sz;

	cin >> sz;

	int n;

	cin >> n;

	int cnt = 0;
	int sum = 0;

	vector<node> vec;

	for (int i = 0; i < n; i++) {
		node temp;
		cin >> temp.a >> temp.b >> temp.c;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < n; i++) {
		if (cnt == sz )
			break;
		if (findboss(vec{i}.a) == findboss(vec{i}.b)) {
			continue;
		}
		setunion(vec{i}.a, vec{i}.b);
		sum += vec{i}.c;
		cnt++;
	}

	cout << sum << endl;

	return 0;

}