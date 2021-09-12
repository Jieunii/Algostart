#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	unordered_map<string, int> chk;

	for (int i = 0; i < clothes.size(); i++) {
		for (int j = 0; j < clothes[i].size() - 1; j++) {
			chk[clothes[i][clothes[i].size() - 1]]++;
		}
	}
	for (auto x = chk.begin(); x != chk.end(); x++) {
		if (answer == 0) {
			answer = x->second + 1;
		}
		else {
			answer *= (x->second + 1);
		}
	}

	answer--;

	return answer;
}