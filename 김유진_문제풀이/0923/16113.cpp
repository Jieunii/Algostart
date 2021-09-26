/*

//시그널

#include <iostream>
#include <string>
using namespace std;

char map[5][20001];
int n;
string res = "";

char num[10][5][4] = {
	{"###","#.#","#.#","#.#","###"}, 
	{"#..","#..","#..","#..","#.."},
	{"###","..#","###","#..","###"},
	{"###","..#","###","..#","###"},
	{"#.#","#.#","###","..#","..#"},
	{"###","#..","###","..#","###"},
	{"###","#..","###","#.#","###"},
	{"###","..#","..#","..#","..#"},
	{"###","#.#","###","#.#","###"},
	{"###","#.#","###","..#","###"},
};

int find_num(int start) {

	//1은 따로 체크
	if (start == n / 5 - 1) {
		int isone = 1;
		for (int y = 0; y < 5; y++) {
			if (map[y][start] != '#') isone = 0;
		}
		if (isone == 1) return 1;
	}

	int isone = 1;
	for (int y = 0; y < 5; y++) {
		if (map[y][start] != '#') isone = 0;
		if (map[y][start+1] != '.') isone = 0;
	}
	if (isone == 1) return 1;

	char tmp[5][3] = { ' ', };
	for (int i = 0; i < 5; i++) {
		for (int j = start; j < start + 3; j++) {
			tmp[i][j-start] = map[i][j];
		}
	}

	for (int i = 0; i < 10; i++) {
		int find = 1;
		for (int j = 0; j < 5; j++) {
			int flag = 0;
			for (int k = 0; k < 3; k++) {
				if (tmp[j][k] != num[i][j][k]) {
					flag = 1;
					find = 0;
					
				}
			}
			if (flag == 1) break;
		}
		if (find == 1) {
			return i;
		}
	}

	return -1;
}

int main() {

	//input
	cin >> n;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n / 5; j++) {
			cin >> map[i][j];
		}
	}

	
	for (int i = 0; i < n / 5; i++) {
		if (map[0][i] == '#') {
			int val = find_num(i);
			if (val == 1) {
				res += to_string(val);
			}
			else if (val != -1) {
				res += to_string(val);
				i += 3;
			}
		}
	}
	cout << res;

	return 0;
}

*/