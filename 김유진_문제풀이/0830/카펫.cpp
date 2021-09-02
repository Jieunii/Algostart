#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool check(int a, int b, int brown) {
    if ((a + 2) * 2 + b * 2 == brown) {
        return true;
    }
    return false;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i <= sqrt(yellow); i++) {
        if (yellow % i == 0) {
            if (check(i, yellow / i, brown)) {
                answer.push_back((yellow / i) + 2);
                answer.push_back(i + 2);
            }
        }
    }
    return answer;
}