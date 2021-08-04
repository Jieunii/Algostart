// find, substr 이용했으나,
// 시간초과

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, bomb;
    
    cin >> str >> bomb;

    // 계속 돌면서 문자열 내 폭탄이 있는지 확인
    while (1) {

        int str_sz = str.size();
        bool flag = 0;

        for (int i = 0; i < str_sz; i++) {

            // 폭탄을 찾은경우(1. 문자열 가운데 있는경우)
            if (str.find(bomb) != string::npos) {
                //폭탄 만큼 드러냄
                string front, end;
                front = str.substr(0,str.find(bomb));
                end = str.substr(str.find(bomb) + bomb.size(), str.size()); // 끝까지
                str = front + end;    
                break; // 문자열이 수정됬으므로 다시 처음부터 검색해야함
            }

            // 1. 더이상 문자열에 bomb이 없는경우
            else {
                flag = 1;
            }
        }

        // 탈출조건, 플래그가 1이면 탈출 
        if (flag == 1) {
            break;
        }
    }

    if (str.size() == 0) {
        cout << "FRULA" << endl;
    }
    else {
        cout << str << endl;
    }

    return 0;
}