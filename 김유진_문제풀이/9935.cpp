#include <iostream>
#include <string>
using namespace std;

string res;
string temp;

int main() {

	string str = "", bomb = "";
	cin >> str >> bomb;

	int bomb_size = bomb.size();
	for (int i = 0; i < str.size(); i++) {//�Է¹��ڿ��� �ѹ� ��ȸ
		res += str[i];
		int res_size = res.size(); 

		//���� �ֱٿ� �� ���ڿ� ��ź�� ������ ���ڶ� ������
		if (res[res_size - 1] == bomb[bomb_size - 1]) {

			if (res_size >= bomb_size) {
				//res�� �����ϴ� ���ڿ����� bombũ�⸸ŭ �ڿ��� �̾Ƽ� temp����
				temp = res.substr(res_size - bomb_size, bomb_size);

				//temp�� bomb�̶� ���ڿ��� ������ �����
				if (temp == bomb) {
					res.erase(res_size - bomb_size, bomb_size);
				}
			}
		}
	}

	if (res == "") cout << "FRULA";
	else cout << res;

	return 0;
} 