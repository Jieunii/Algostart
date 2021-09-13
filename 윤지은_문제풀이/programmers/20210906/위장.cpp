#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 1;
  unordered_map<string, int> cloth;
  
  for (int i = 0; i < clothes.size(); i++) {
    cloth[clothes[i][1]]++;
  }
  for (auto x = cloth.begin(); x != cloth.end(); x++) {
    answer *= x->second + 1;
  }
  return answer - 1;
}