#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	//( �� ������ )�� ã�´�
	//) �տ� (�� ������ ������
	//�踷���� �ڽź��� �� ����� �������� ����

	//()������  ( ( ( () () ) ( () ) () ) )  ( () )
	//stack�� ( ���� ������ ( �߰� )������ stack size ��ŭ �߰�

	string razor;
	int ans = 0;
	stack<char> bracket;
	cin >> razor;

	for (int i = 0; i < razor.length(); i++) {
		if (razor[i] == '(') {
			bracket.push(razor[i]);
		}
		else if (razor[i] == ')') {
			if (razor[i - 1] == '(') {
				//�������� �ڸ���
				//�����... �ڸ� ���� ��� ����...
				bracket.pop();
				ans += bracket.size();

			}
			else if (razor[i - 1] == ')') {
				bracket.pop();
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}