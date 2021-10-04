#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct info {
	int idx;
	int num;
};

unordered_map<string, int> cnt;
unordered_map<string, vector<info>> played;
unordered_map<string, int> sum;

bool compare(info a, info b) {
	if (a.num < b.num) return false;
	if (a.num > b.num) return true;
	return false;
}

bool comp(string a, string b) {
	if (sum[a] < sum[b]) return false;
	if (sum[a] > sum[b]) return true;
	return false;
}

int main() {

	vector<string> sorted;
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };
	vector<int> ans;

	for (int i = 0; i < genres.size(); i++) {
		cnt[genres[i]]++;
		sum[genres[i]] += plays[i];
		played[genres[i]].push_back({ i,plays[i] });
	}

	for (auto x = played.begin(); x != played.end(); x++) {
		
		sorted.push_back(x->first);
		sort(x->second.begin(), x->second.end(),compare);
	}
	sort(sorted.begin(), sorted.end(), comp);
	
	for (int i = 0; i < sorted.size(); i++) {
		if (played[sorted[i]].size() >= 2) {
			ans.push_back(played[sorted[i]][0].idx);
			ans.push_back(played[sorted[i]][1].idx);
		}
		else {
			ans.push_back(played[sorted[i]][0].idx);
		}
	}

	return 0;
}
