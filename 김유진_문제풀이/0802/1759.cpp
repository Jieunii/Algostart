#include <iostream>
using namespace std;

int L, C;
int ch[26];
char res[16];

// Á¶ÇÕ±¸ÇÏ±â
// int aeiou : ¸ðÀ½ °³¼ö cnt 
void go(int depth, int index, int aeiou) {
	if (depth == L) {
		if (aeiou >= 1 && aeiou <= L - 2) {
			for (int i = 0; i < L; i++) {
				cout << res[i];
			}
			cout << "\n";
		}
		return;
	}

	for (int i = index; i < 26; i++) {
		if (ch[i] == 0) continue;
		if (i == 'a' - 97 || i == 'e' - 97 || i == 'i' - 97 || i == 'o' - 97 || i == 'u' - 97) {
			res[depth] = 'a' + i;
			go(depth + 1, i + 1, aeiou + 1);
		}
		else {
			res[depth] = 'a' + i;
			go(depth + 1, i + 1, aeiou);
		}
	}
}

int main() {
	char input;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> input;
		ch[input-97] = 1;
	}

	go(0, 0, 0);
	return 0;
}
