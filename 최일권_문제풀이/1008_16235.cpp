//������ ����� �԰� ���̰� ���� (����� ���̸�ŭ) �� ������ ���
//�������� ���� ������ ������� ��ȭ(����/2) ��ŭ �� ĭ�� �߰�
//�������� ����(8�������� ���̰� 1�� ���� ����)
//�ܿ￡�� ���� ��� �߰� A[r][c]��ŭ ����
//map�� ���� �ִ� ��� (�ʱ� 5)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };
int a[11][11] = {};//�߰��� ���
int map[11][11] = {}; //���� ���
int isInside(int y, int x) {
	if (y < 0 || y>N || x < 0 || x>N)
		return 0;
	return 1;
}
//���� ������ ���� �ʿ�
vector<int> tree[11][11];
int main() {

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
			map[i][j] = 5;
		}
	}

	for (int i = 1; i <= M; i++) {
		int y, x, age;
		cin >> y >> x >> age;
		tree[y][x].push_back(age);
	}
	
	//�� ���� ���� �ܿ� ������ ����
	int trees = 0;
	while (K--) {
		//��  + ����-> ��� ��� �� ���� ���� 

		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				vector<int> temp;
				if (tree[i][j].empty()) continue;

				sort(tree[i][j].begin(), tree[i][j].end());
				int poo = 0;
				for (int k = 0; k < tree[i][j].size(); k++) {
					
					if (map[i][j] >= tree[i][j][k]) {
						map[i][j] -= tree[i][j][k];
						temp.push_back(tree[i][j][k]+1);
					}
					else {
						poo += tree[i][j][k] / 2;
					}
				}
				tree[i][j].clear();

				for (int y = 0; y < temp.size(); y++) {
					tree[i][j].push_back(temp[y]);
				}

				map[i][j] += poo;
			}
		}

		//����

		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				if (tree[i][j].empty()) continue;

				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] % 5 == 0) {
						for (int t = 0; t < 8; t++) {
							int ny = i + dir[t][0];
							int nx = j + dir[t][1];

							if (!isInside(ny, nx)) continue;

							tree[ny][nx].push_back(1);
						}
					}
				}
			}
		}

		//�ܿ�

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] += a[i][j];
			}
		}


		//cout << "���" << endl;
		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= N; j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << endl;
		//}


	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			trees += tree[i][j].size();
		}
	}

	cout << trees << endl;

	return 0;
}