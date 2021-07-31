#include <iostream>
using namespace std;

int n, m;
int visited[10];
int res[10];

void go(int cnt) {
	//m�ڸ� �� ��� ���õǾ�����
	if (cnt == m) {
		//���
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";

		return;
	}

	//m�ڸ��� ���õ��� �ʾ�����
	for (int i = 1; i <= n; i++) { //1~n�� ��
		
		//������ ���õ� ���� ���ٸ�
		if (!visited[i]) {
			
			//���� �����Ҳ��ϱ� ���õǾ��ٰ� ǥ��
			visited[i] = 1;
			
			//cnt �ڸ��� ������ �� �ֱ�
			res[cnt] = i;

			//cnt ���� �ڸ� �����Ϸ�����
			go(cnt + 1);

			//return �Ǹ鼭 cnt�ڸ��� �����������ϱ� ���������ʾҴٰ� �ٽ� ǥ��
			visited[i] = 0;
		}
	}
}

int main() {

	cin >> n >> m;
	go(0);
	return 0;
}