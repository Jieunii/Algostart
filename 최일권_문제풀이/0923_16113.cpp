#include <iostream>
#include <string>
using namespace std;

char signal[100000];
int n;

string digit[100000] = {};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf_s("%d", &n);
	scanf_s("%s", signal);
	int k = 0;
	int div = n / 5;
	// signal = ###..#..#.#..#..###..#..#.#..#..###..#..
	// ###.....###.#..####.#.......#.#....####.....###.#....##.#.......#.#....####.....###.#....#
	// 8 => ####.#####.####
	// 1 => #####
	//숫자가 붙어있을 수도 있다...
	// 4 => #.##.####..#..#
	// 5 => ####..###..####
	// 6 => ####..####.####
	//9 => ####.####..####
	for (int i = 0; i < div;i++) {
		if ((signal[i] == '#') || (signal[i] == '.' && signal[i + 2*div] != '.')) {
			string temp = "";
			temp += signal[i];
			temp += signal[i + div];
			temp += signal[i + 2 * div];
			temp += signal[i + 3 * div];
			temp += signal[i + 4 * div];
			digit[k++] = temp;
		}
	}
	
	
	for (int i = 0; i < k;) {
		if (digit[i] == "#####") {
		 if (digit[i + 1] == "#...#") {
				printf("%d", 0);
				i += 3;
				continue;
			}
			else if (digit[i + 1] == "#.#.#") {
			 if (digit[i + 2] == "#####") {
				 printf("%d", 8);
				 i += 3;
				 continue;
			 }
			 else if (digit[i + 2] == "#.###") {
				 printf("%d", 6);
				 i += 3;
				 continue;
			 }
			 else {
				 printf("%d", 1);
				 i++;
				 continue;
			 }
			}
			else {
			 printf("%d", 1);
			 i++;
			 continue;
		 }
		}
		else if (digit[i] == "#.#.#") {
			printf("%d", 3);
			i += 3;
			continue;
		}
		else if (digit[i] == "###..") {
			printf("%d", 4);
			i += 3;
			continue;
		}
		else if (digit[i] == "###.#") {
			if (digit[i + 2] == "#.###") {
				printf("%d", 5);
				i += 3;
				continue;
			}
			else {
				printf("%d", 9);
				i += 3;
				continue;
			}
		}
		else if (digit[i] == "#.###") {
			printf("%d", 2);
			i += 3;
			continue;
		}
		else if (digit[i] == "#....") {
			printf("%d", 7);
			i += 3;
			continue;
		}
	}
	printf("\n");
	return 0;
}