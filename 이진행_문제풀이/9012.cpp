#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, point =0;
    bool flag;

    string str;

    cin >> n;

    // n번 반복
    for (int i = 0; i < n; i++) {
        // 초기화
        flag = 1;
        point = 0;

        cin >> str;

        // 판별
        for (int j = 0; j < str.size(); j++) {

            // (는 1점, )는 -1점
            if (str[j] == '(') {
                point++;
            }
            else if (str[j] == ')') {
                point--;
            }

            // ex.1) (())) 와 같이 )가 먼저 많이 나와버린경우 
            if (point < 0) {
                flag = 0;
            }
            // ex.2) 문자열이 끝났는데, (가 남아있는 경우
            else if (j == str.size() - 1 && point > 0) {
                flag = 0;
            }

            if (flag == 0) {
                cout << "NO" << endl;
                break;
            }
        }

        // 문자열을 끝까지 돌았는데 flag가 1이면 YES
        if (flag == 1) {
            cout << "YES" << endl;
        }

    }
    return 0;
}