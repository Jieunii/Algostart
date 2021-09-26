/*

������4���

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<pair<int, int> > bomb;

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	while (1) {
		//��Ʈ���� ã�Ƽ� ���
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j] == ' ') continue;
				if (board[i][j] == board[i + 1][j] && board[i][j + 1] == board[i + 1][j + 1] && board[i][j] == board[i + 1][j + 1]) {
					bomb.push_back({ i, j });
					bomb.push_back({ i + 1, j });
					bomb.push_back({ i, j + 1 });
					bomb.push_back({ i + 1, j + 1 });
				}
			}
		}

		//��Ʈ���� ������ ������
		if (bomb.empty()) break;

		//��Ʈ����
		for (int i = 0; i < bomb.size(); i++) {
			if (board[bomb[i].first][bomb[i].second] != ' ') {
				board[bomb[i].first][bomb[i].second] = ' ';
				answer++;
			}
		}

		//����� ä���
		for (int i = 0; i < n; i++) {
			for (int j = m - 2; j >= 0; j--) {
				for (int k = j + 1; k < m; k++) {
					if (board[k][i] == ' ') {
						board[k][i] = board[k - 1][i];
						board[k - 1][i] = ' ';
					}
					else {
						break;
					}
				}
			}
		}

		//bomb�ʱ�ȭ
		while (!bomb.empty()) {
			bomb.pop_back();
		}
	}

	return answer;
}

*/