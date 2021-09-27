/*
m, n 맵 현재 상태가 저장된 문자열이 주어짐          
가로세로가 2인 정사각형이 모두 같은 숫자일 떄 터짐 
터진다음 빈 공간은 중력으로 위에 칸이 내려옴.
터질 애들이 없일때 까지 이를 반복하면 몇개가 터지는지 세는 문제

풀이 :
완전탐색으로 직접 돌림
0. 초기화
1. 지울 블럭을 찾는다
2. check배열에 지울 위치들을 표시해놓음
3. 블럭을 지운다 
    -> 만약 지울 블럭이 없다면 종료
4. 중력적용하고 board를 갱신한다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    int check[31][31];

    while (1) {
        // 0. 초기화
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                check[y][x] = 0;
            }
        }
        bool flag = true;

        // 1. 지울 블럭 찾기
        for (int y = 0; y < m-1; y++) {
            for (int x = 0; x < n-1; x++) {

                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        if (board[y][x] == '0') continue; // 빈공간 패스
                        if (board[y][x] == board[y + 1][x] &&  
                            board[y][x] == board[y][x + 1] && 
                            board[y][x] == board[y + 1][x + 1]) { // 네칸이 같으면 표시해놓음
                            
                            check[y][x] = 1;
                            check[y + 1][x] = 1;
                            check[y][x + 1] = 1;
                            check[y + 1][x + 1] = 1;

                            flag = false;
                        }
                    }
                }

            }
        }
        // 2. 블럭 지우기
        if (flag == true) { // 지울 블럭이 존재하지 않다면
            break;
        }
        // map에 1로 표시된 부분 다 0으로 지우기 
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (check[y][x] == 1) {
                    board[y][x] = '0';
                    answer++; // 지운 개수 증가
                }
            }
        }

        // 3. 중력
        for (int x = 0; x < n; x++) {
            for (int y = m - 1; y >= 0; y--) {
                if (board[y][x] == '0') {
                    int dy = y;
                    while (dy > 0 && board[dy][x] == '0') {
                        dy--;
                    }
                    board[y][x] = board[dy][x];
                    board[dy][x] = '0';
                }
            }
        }

    }

    return answer;
}

int main() {
    freopen_s(new FILE*, "test.txt", "r", stdin);
    int m, n;
    vector<string> board;

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }

    solution(m, n, board);
}