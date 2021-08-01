#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<char> st;
    char str[51];
    int n;
    bool flag;

    cin >> n;

    // n번 반복
    for (int i = 0; i < n; i++) {
        // 스택 초기화
        while (!st.empty()) {
            st.pop();
        }
        flag = 1;

        cin >> str;

        for (int j = 0; str[j] != '\0'; j++) {
            // '('를 만나면 스택에 push
            if (str[j] == '(') {
                st.push(str[j]);
            }
            // ')'를 만나면 스택에서 pop
            else if(str[j] == ')') {
                if (st.empty()) { // 더이상 꺼낼게 없는 경우
                    flag = 0;
                    break;
                }
                else {
                    st.pop();
                }
            }
        }
        // 끝까지 돌았는데 스택이 깨끗한 경우
        if (!st.empty()) {
            flag = 0;
        }

        if (flag == 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}