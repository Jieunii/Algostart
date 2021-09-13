/*
* n개의 회의. 시작시간과 종료시간이 주어짐
* 회의실을 사용할 수 있는 회의의 최대 개수 구하기
* 회의 시간은 겹치면 안된다!
*/

/* 
* 대표적인 그리디 문제
* 1. 가장 짧은 회의들만 고르면? -> 반례 존재. 
* 2. 가장 빨리 끝나는 회의들을 고르는게 항상 최선? -> 증명: https://source-sc.tistory.com/59
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector< pair<int, int> > meeting;

bool compare(pair<int, int> front, pair<int, int> back) {
	// 1. 끝나는 시간 오름차순
	// 2. 시작 시간 오름차순 
	if (front.second < back.second) return true;
	if (front.second > back.second) return false;
	return front.first < back.first;
}

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		meeting.push_back(make_pair(start, end));
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	// 끝나는 시간 순으로 정렬
	sort(meeting.begin(), meeting.end(), compare);

	// 그리디 
	int cnt = 0;
	int time = 0; // 이전회의의 끝나는 시간을 저장

	for (int i = 0; i < meeting.size(); i++) {
		// 이전 회의의 끝나는 시간
		if (meeting[i].first >= time) {
			time = meeting[i].second;
			cnt++;
		}
	}

	cout << cnt++;

	return 0;
}