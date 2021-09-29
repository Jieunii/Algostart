#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int N;
vector<char> path;
queue<string> num[11];
string ans = "";
int k = 9;
void count_num(int start) {

	if (start > 1) {
		string temp = "";
		for (int i = 0; i < start; i++) {
			temp += path[i];
		}
		num[start].push(temp);
	}

	for (char i = '0'; i <= '9'; i++) {
		if (path.size()>=1 && path.back() <= i) continue;
		path.push_back(i);
		count_num(start + 1);
		path.pop_back();
	}
}

int main() {

	//���� �ƴ� ���� X�� �ڸ����� ���� ū �ڸ������� ���� �ڸ������� �����Ѵٸ�, �� ���� �����ϴ� ����� �Ѵ�. ���� ���, 
	//321�� 950�� �����ϴ� ������, 322�� 958�� �ƴϴ�. N��° �����ϴ� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
	//0�� 0��° �����ϴ� ���̰�, 1�� 1��° �����ϴ� ���̴�. ���� N��° �����ϴ� ���� ���ٸ� -1�� ����Ѵ�.

	//0 1 2 3 4 5 6 7 8 9
	//10 20 21 30 31 32 40 41 42 43 

	cin >> N;
	if (N < 10)
	{
		printf("%d\n", N);
		return 0;
	}
	if (N > 1022) {
		cout << -1 << endl;
		return 0;
	}
	count_num(0);

	for (int i = 2; i <= 10; i++) {
		if (ans != "") break;

		while (!num[i].empty()) {
			k++;
			if (k == N) {
				
				ans = num[i].front();
				break;
			}
			num[i].pop();
		}
	}
	cout << ans << endl;
	return 0;
}