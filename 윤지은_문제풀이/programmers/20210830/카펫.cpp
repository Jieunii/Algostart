#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int carpet = brown + yellow;
    
    for(int garo=1;garo<=carpet;garo++){
        if(carpet % garo == 0){
            int sero = carpet / garo;
            if((sero-2)*(garo-2) == yellow && garo >= sero){
                answer.push_back(garo);
                answer.push_back(sero);
            }
        }
    }

    return answer;
}