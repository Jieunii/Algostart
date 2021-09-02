
/*
    1. yellow의 개수를 받아 이를 통해 만들수 있는 가운데 노란 무늬의 직사각형들 만들기
    2. 이 노란색 직사각형에 테두리를 덧대본다
    3. 덧댄 테두리의 칸 수가 brown과 같은지 확인
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // yellow의 약수들을 저장
    vector<int> yellowVect;
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) yellowVect.push_back(i);
    }

    // 이 약수들을 이용해 직사각형 생성
    for (int i = 0; i < yellowVect.size(); i++) {
        int yellow_y = yellowVect[i];
        int yellow_x = yellow / yellow_y; 

        if (yellow_x > yellow_y) continue; // 가로 길이가 더 작으면 스킵

        int border = 2 * yellow_y + 2 * yellow_x + 4; 

        if (border == brown) {
            answer.push_back(yellow_y + 2);
            answer.push_back(yellow_x + 2);
        }
    }

    return answer;
}

int main() {
    int brown = 24;
    int yellow = 24;

    solution(24, 24);

}