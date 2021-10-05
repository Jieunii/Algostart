/*
풀이 :
해시 체이닝 필요? 구현 어떻게??? 

=> [key : string, value : vector 배열]을 가지는 unorderd map을 사용!
                                ↑ 이런식으로도 쓸 수 있는지 처음 알았음!
genre_play_list 
    KEY :           VALUE :
    "classic"       [(800,3), (500,0), (150,2)]         
    "pop"           [(2500,4), (600,1)]

genre_play_cnt
    KEY :           VALUE :
    "classic"       1450
    "pop"           3100
  ↓
genre_play_cnt_vect
    [("pop", 3100) ,("classic",1450)]
*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// play 회수 기준 내림차순 정렬(플레이회수, 고유번호) 
bool compare(pair<int, int> front, pair<int, int> back) {
    return front.first > back.first;
}

// (genre, play)중 play 기준 내림차순 정렬
bool compare_map_value(pair<string, int> front, pair<string, int> back) {
    return front.second > back.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector< pair<int, int> > > genre_playlist; // 장르, 벡터(플레이 회수, 고유번호) 를 가지는 unorderd map
    unordered_map<string, int> genre_play_cnt; // 장르별 전체 플레이 회수를 저장하기 위한 map
    
    // 추가
    for (int i = 0; i < genres.size(); i++) {
        genre_playlist[genres[i]].push_back(make_pair(plays[i], i));  
        genre_play_cnt[genres[i]] += plays[i];  // 일단 map에 회수별로 저장한다
    }

    // 각 원소의 value 벡터를 정렬
    for (auto& k : genre_playlist) {
        sort(k.second.begin(), k.second.end(), compare);
    }

    vector< pair<string, int> > genre_play_cnt_vect; // 전체 플레이 회수로 정렬하기 위해 벡터에 저장

    genre_play_cnt_vect.assign(genre_play_cnt.begin(), genre_play_cnt.end()); // unordered_map을 vector로 저장
    sort(genre_play_cnt_vect.begin(), genre_play_cnt_vect.end(), compare_map_value);

    for (int i = 0; i < genre_play_cnt_vect.size(); i++) {
        string genre_name = genre_play_cnt_vect[i].first;
        for (int j = 0; (j < genre_playlist[genre_name].size()) && (j < 2); j++) {
            answer.push_back(genre_playlist[genre_name][j].second);
        }
    }

    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    solution(genres, plays);

	return 0;
}