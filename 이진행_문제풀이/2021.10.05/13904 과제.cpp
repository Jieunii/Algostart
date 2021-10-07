/*
N개의 {d, w}가 주어짐
점수의 최대값 구하기

풀이)
DFS? 저번에 풀었던 퇴사전까지 최대 금액 버는 문제? X
모든 과제는 하루에 해결가능 -> DFS 아님!
최대 값 구하기 -> 그리디?

급한거부터 먼저 처리한다?
점수가 높은거부터 처리한다 V

1. 점수가 높은순으로 정렬
2. 마감일이 늦는건 가장 늦게 처리

=> 마감일부터 시작일까지 앞으로 가면서
그 날 해결할 점수가 가장 높은과제 선택
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int lastday = 0;
vector< pair<int, int> > task;
int visited[1001];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		if (lastday < d) {
			lastday = d;
		}
		task.push_back({ d, w });
	}
}

bool compare(pair<int, int> front, pair<int, int> back) {
	// 1. 점수 기준 내림차순
	if (front.second > back.second) return true;
	if (front.second < back.second) return false;
	 
	// 2. 일자 기준 오름차순
	return front.first < back.first;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();
	
	sort(task.begin(), task.end(), compare);

	// 마지막날부터 0일차까지 감소하면서 하나씩 선택
	int sum = 0;

	for (int day = lastday; day >= 1; day--) {
		for (int i = 0; i < task.size(); i++) {
			if (visited[i] == 1) continue; // 당일에 해결할 과제가 이미 정해진 경우
			if (task[i].first < day) continue;  // 이미 기한이 지나서 선택할 수 없는 경우

			visited[i] = 1;
			sum += task[i].second;
			break;
		}
	}
	cout << sum;
	return 0;
}