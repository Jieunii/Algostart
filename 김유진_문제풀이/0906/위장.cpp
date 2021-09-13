//¿ß¿Â

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    for (int i = 0; i < clothes.size(); i++) {
        um[clothes[i][1]]++;
    }
    for (auto it = um.begin(); it != um.end(); it++) {
        int val = it->second;
        answer *= val + 1;
    }
    answer -= 1;
    return answer;
}
