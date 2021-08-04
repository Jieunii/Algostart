// 스택을 이용해서 푼 방법
// 방법은 참고했음

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    string str, bomb;
    stack<char> st;

    cin >> str >> bomb;

    for (int i = 0; i < str.size(); i++) {
        // str의 문자를 하나씩 stack에 쌓는다
        st.push(str[i]);

        // 만약 마지막으로 넣은 문자가, bomb의 끝문자라면?
        /*
        마지막 문자를 비교하는게 시간효율이 좋다고함
        첫번째 문자부터 비교하면 뒤 문자들을 확인해야하므로
        */
        if (st.top() == bomb[bomb.size() - 1]) {
            string tmp = "";

            // 다시 앞으로 bomb.size()만큼 하나씩 꺼내본다.
            for (int i = 0; i < bomb.size(); i++) {
                if (!st.empty()) {
                    tmp += st.top();
                    st.pop();
                }
                // 이미 스택이 비어있는경우는 결백함
                else {
                    break;
                }
            }

            // 문자열 뒤집기
            reverse(tmp.begin(), tmp.end()); // <algorithm.h>의 reverse함수 사용

            // 이 문자들이 bomb이라면 버림
            // 아니라면 다시 뒤집어 넣고 진행
            if (tmp != bomb) { 
                for (int i = 0; i < tmp.size(); i++) {
                    st.push(tmp[i]);
                }
            }
        }
    }
    // 끝까지 다 넣었으면 출력
    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());

    if (res.size() == 0) {
        cout << "FRULA" << endl;
    }
    else {
        cout << res << endl;
    }

    return 0;
}