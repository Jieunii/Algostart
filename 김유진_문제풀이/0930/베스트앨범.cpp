#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct g {
	int total_play;
	string genre;
};

struct r {
	int plays;
	int song_num;
};

bool cmp(g front, g back) {
	return front.total_play > back.total_play;
}

bool cmp2(r front, r back) {
	return front.plays > back.plays;
}

vector<g> v; //total_play, genre
unordered_map<string, vector<r> > um; //plays, song num

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	for (int i = 0; i < genres.size(); i++) {
		int flag = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[j].genre == genres[i]) {
				v[j].total_play += plays[i];
				flag = 1;
			}
		}
		if (flag == 0) { //v에 장르 안들어가있으면
			v.push_back({ plays[i], genres[i] });
		}
		um[genres[i]].push_back({ plays[i], i });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i = um.begin(); i != um.end(); i++) {
		sort(i->second.begin(), i->second.end(), cmp2);
		for (int j = 0; j < i->second.size(); j++) {
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (um[v[i].genre].size() < 2) {
			for (int j = 0; j < um[v[i].genre].size(); j++) {
				answer.push_back(um[v[i].genre][j].song_num);
			}
		}
		else {
			answer.push_back(um[v[i].genre][0].song_num);
			answer.push_back(um[v[i].genre][1].song_num);
		}
	}


	return answer;
}
