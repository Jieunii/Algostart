#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, B;
int map[501][501];
int Min = 999999;
int Max = -999999;
int tc;

int main() {

	cin >> N >> M >> B;
	//�� �ı� = 2��, �� �ø��� = 1��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (Max < map[i][j])
				Max = map[i][j];
			if (Min > map[i][j])
				Min = map[i][j];
		}
	}
	int dig = 0;
	int build = 0;
	int comp = 0;
	int ans_h = 0;
	int ans = 9999999999;
	for (int i = Min; i <= Max; i++) {
		dig = 0;
		build = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				comp = map[y][x] - i;

				if (comp > 0) { // ��ƾ� �Ǵ°�
					dig += comp;
				}
				else { //�׾ƾ� �Ǵ°�
					build += abs(comp);
				}
			}
		}
		if (dig + B >= build) { // ������ �ִ� ����� ������ ��ƾ� �� ����� ������ 
								//�׾ƾ� �� ����� �������� ���ų� ���� ���� ��
			tc = dig * 2 + build;
			if (ans >= tc) {
				ans = tc;
				ans_h = i;
			}
		}
	}
	cout << ans << " " << ans_h << endl;

	return 0;
}