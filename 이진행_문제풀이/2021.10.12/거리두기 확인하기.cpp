#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int direct[4][2] = { 0,-1, -1,0, 0,1, 1,0 };

struct node {
    int y;
    int x;
    int level;
};

// 각 방별로 방역수칙 확인하기
bool CheckRoom(vector<string> room) {
    bool res = true;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {

            // 현재 좌표에 사람이라면 BFS로 최단거리에 있는 사람 구하기
            if (room[y][x] == 'P') {
                int visited[5][5] = { 0 };
                queue<node> qu;

                visited[y][x] = 1;
                qu.push({ y,x,0 });

                while (!qu.empty()) {
                    node now = qu.front();
                    qu.pop();

                    // 거리 2 내에 다른사람 발견
                    if (room[now.y][now.x] == 'P' && now.level != 0 && now.level <= 2) { res = false; break; }
                    if (now.level > 2) continue; // 2이상은 안봐도 됨

                    for (int t = 0; t < 4; t++) {
                        int dy = now.y + direct[t][0];
                        int dx = now.x + direct[t][1];
                        
                        if (dy < 0 || dx < 0 || dy >= 5 || dx >= 5) continue; // 경계처리
                        if (room[dy][dx] == 'X') continue; // 파티션 이동 불가
                        if (visited[dy][dx] == 1) continue; // 이미 방문

                        visited[dy][dx] = 1;
                        qu.push({ dy,dx,now.level + 1 });
                    }
                }

            }
        }
    }

    return res;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    // 각 방별로 확인
    for (int i = 0; i < places.size(); i++) {
        bool res = CheckRoom(places[i]);
        if (res == true) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }

    return answer;
}

int main() {
    // P : 사람, O : 빈 테이블, X : 파티션
    vector < vector<string> > places = 
    {   
        {
            "POOPX", 
            "OXPXP", 
            "PXXXO", 
            "OXXXO", 
            "OOOPP"
        },
        {
            "POOOP", 
            "OXXOX", 
            "OPXPX", 
            "OOXOX", 
            "POXXP"
        }, 
        {
            "PXOPX", 
            "OXOXP", 
            "OXPOX", 
            "OXXOP", 
            "PXPOX"
        }, 
        {"OOOXX", 
        "XOOOX", 
        "OOOXX", 
        "OXOOX", 
        "OOOOO"}, 
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };
    vector<int> res = solution(places);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    
}