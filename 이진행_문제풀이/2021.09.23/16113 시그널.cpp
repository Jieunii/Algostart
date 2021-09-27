/*
문자수n 와 #과 .으로 이루어진 문자열 입력
이를 5줄로 쪼개서 배치하면 문자가 보임 
이 문자를 해독

풀이 : 
1. 문자열을 5등분해서 배열에 넣는다.

2. 모든 문자들은 왼쪽 위에서부터 시작하므로, 이를 원점으로 세로 5칸, 가로 3칸을 저장된 숫자 배열들과 비교하는 방법 사용
- 1은 세로 5칸, 가로 1칸만 차지하므로 예외처리

3. 맨 윗줄부터 탐색하면서, 검은색으로 칠해져있다면, 왼쪽이 흰색칸인지 확인한다.
-> 왼쪽이 흰색칸이고 현재가 검은색으로 칠해져있다면, => IsLeftWhite 함수
	어떤 숫자와 일치하는지 검사한다. => CheckNum 함수
- 첫번째 문자는 왼쪽이 없으므로 무조건 검사
- 1이 처음에 올때, 마지막에 올때, 중간에 올때 각각 따로 처리한다
*/



#include <iostream>
#include <string>

// #define DEBUG

using namespace std;

char matrix[5][20001];

char number[10][5][3] = {
	// 0
	{
		'#','#','#',
		'#','.','#',
		'#','.','#',
		'#','.','#',
		'#','#','#',
	},
	// 1 *** 
	{
		'.','#','.',
		'.','#','.',
		'.','#','.',
		'.','#','.',
		'.','#','.',
	},
	{
		'#','#','#',
		'.','.','#',
		'#','#','#',
		'#','.','.',
		'#','#','#',
	},
	{
		'#','#','#',
		'.','.','#',
		'#','#','#',
		'.','.','#',
		'#','#','#',
	},
	{
		'#','.','#',
		'#','.','#',
		'#','#','#',
		'.','.','#',
		'.','.','#',
	},
	{
		'#','#','#',
		'#','.','.',
		'#','#','#',
		'.','.','#',
		'#','#','#',
	},
	{
		'#','#','#',
		'#','.','.',
		'#','#','#',
		'#','.','#',
		'#','#','#',
	},
	{
		'#','#','#',
		'.','.','#',
		'.','.','#',
		'.','.','#',
		'.','.','#',
	},
	{
		'#','#','#',
		'#','.','#',
		'#','#','#',
		'#','.','#',
		'#','#','#',
	},
	{
		'#','#','#',
		'#','.','#',
		'#','#','#',
		'.','.','#',
		'#','#','#',
	}
};

bool IsLeftWhite(int x) {
	if (x == 0) return true; // 첫째칸은 무조건 참

	if (matrix[0][x-1] == '.') return true; // 두번째칸부터는 왼쪽이 .일때만 참
	else return false;
}

// 숫자 검사 함수
int CheckNum(int xx, int colnum) {
	int res = -1;

	// 1 인지 검사
	// 첫번째수인 경우
	bool flag_one = true;
	if (xx == 0) {
		for (int y = 0; y < 5; y++) {
			if (matrix[y][xx] != number[1][y][1]) {
				flag_one = false;
				break;
			}
		}
	}
	// 마지막수인 경우 <- 4랑 구분하기 위해 0, 1행 비교
	else if (xx == colnum - 1) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 2; x++) {
				if (matrix[y][x + xx - 1] != number[1][y][x]) {
					flag_one = false;
					break;
				}
			}
		}
	}
	// 중간에 껴있는 경우
	else {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 3; x++) {
				if (matrix[y][x + xx - 1] != number[1][y][x]) {
					flag_one = false;
					break;
				}
			}

		}
	}
	if (flag_one == true) {
		res = 1;
	}

	// 1 제외 다른수 검사
	for (int i = 0; i < 10; i++) {
		bool flag = true;
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 3; x++) {
				if (flag == false) break;
				if (matrix[y][x + xx] != number[i][y][x]) {
					flag = false;
					break;
				}

			}
		}
		if (flag == true) {
			res = i;
		}
	}

	return res;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	int n;
	string str; 

	cin >> n >> str;

	int colnum = str.length() / 5; // 가로 칸 개수
	
	// 1. matrix 배열에 5줄씩 끊어 저장
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < colnum; x++) {
			matrix[y][x] = str[y* colnum + x];
		}
	}

#ifdef DEBUG
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < colnum; x++) {
			cout << matrix[y][x];
		}
		cout << endl;
	}
#endif


	// 제일 윗줄로 확인
	string res;
	for (int x = 0; x < colnum; x++) {
		//현재칸이 #이고, 왼쪽칸이 .이면 현재칸부터 숫자 검사
		if ((matrix[0][x] == '#' && IsLeftWhite(x)) == true) {
			int tmp = CheckNum(x, colnum);
			if (tmp != -1) {
				res += to_string(tmp);
			}
		}
	}
	cout << res;

	return 0;
}

