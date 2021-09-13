#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_multimap<string, string> um; // 키로 옷의 타입, value로 옷의 이름
    vector<string> types;

    for (int i = 0; i < clothes.size(); i++) {
        um.insert({ clothes[i][1], clothes[i][0] });
        
        // types에 옷의 종류를 저장. 이미 저장되어있다면 저장하지 않음.
        bool flag = false;
        for (int j = 0; j < types.size(); j++) {
            if (types[j] == clothes[i][1]) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            types.push_back(clothes[i][1]);
        }
    }
  
    
    // 저장된 타입이 map에 몇개 저장되어있는지 확인
    for (int i = 0; i < types.size(); i++) {
        int cnt = um.count(types[i]);
        answer = answer * (cnt + 1);
    }
    answer = answer - 1;

    return answer;
}

int main() {
    vector< vector<string> > clothes = {
        {"yellowhat", "headgear"},
        {"bluesunglasses", "eyewear"},
        {"green_turban", "headgear"}
    };

    solution(clothes);
    
    return 0;
}
