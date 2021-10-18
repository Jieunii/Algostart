#include <string>
#include <vector>

using namespace std;

// 상하좌우, 2칸씩 상하좌우, 대각선
int dy[12] = {-1, 1, 0, 0, -2, 2, 0, 0, -1, -1, 1, 1};
int dx[12] = {0, 0, -1, 1, 0, 0, -2, 2, -1, 1, -1, 1};

bool distance(vector<string> place){
    int loc[5][5] = {0};
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            if(place[y][x] == 'P'){
                for(int i=0; i<12; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
                    if(i < 4){
                        if(place[ny][nx] == 'P') return false;
                        else if(place[ny][nx] == 'X') loc[ny][nx] = 1;    
                    }else if(i < 8){
                        if(place[ny][nx] == 'P' && !loc[y + dy[i - 4]][x + dx[i - 4]]) return false;
                    }else{
                        if(place[ny][nx] == 'P'){
                            if(!loc[ny][x] || !loc[y][nx]) return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0; i < places.size(); i++){
        bool check = true;
        for(int j=0; j<places[i].size(); j++){
            if(!distance(places[i])){
                answer.push_back(0);
                check = false;
                break;
            }
        }
        if(check) answer.push_back(1);
    }
    return answer;
}