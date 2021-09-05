/*
T개의 테스트 케이스가 주어짐
n명의 지원자들에 대해, 서류 심사 등수와 면접 시험 등수가 주어짐
다른 모든 지원자들과 비교했을 때, 
서류 심사 성적과 면접 시험 등수 중 
적어도 하나가 다른 지원자들 보다 떨어지지 않으면 선발한다.
이 조건을 만족하는 채용되는 인원은 총 몇명인지 확인

*/

/*
2초 -> 2억개
T: 1~20 
N: 1~100,000

1번째 방법. 2중 for문으로 전체 확인 : O(n^2) -> 10억*20T 시간초과!!
2번째 방법. STL sort(O(nlogn)) 이후, 2중 for문을 이용해 자기보다 높은 랭크만 확인 -> 시간초과
3번째 방법. 면접랭크로 정렬 이후, 최대 높은 등수를 저장후, 그 등수에 대해서만 비교 -> O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct applicant {
	int resumeRank;
	int interviewRank;
};

vector<applicant> applicants;

bool compare(applicant front, applicant back) {
	if (front.resumeRank < back.resumeRank) return true;
	if (front.resumeRank > back.resumeRank) return false;

	return front.interviewRank < back.interviewRank;
}

void Input() {
	cin >> n;
	applicants.clear();
	for (int i = 0; i < n; i++) {
		int doc, itv;
		cin >> doc >> itv;
		applicants.push_back({ doc, itv });
	}
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	int T;
	cin >> T;
	while (T--) {
		Input();

		// 서류 랭크순으로 정렬
		sort(applicants.begin(), applicants.end(), compare);

		// 현재까지 확인한 사원들 중 
		// 가장 높은 면접 등수를 가진 사원 단 한 명에 대한 면접 등수만 저장하며 비교해나가는 방식 
		int cnt = 0;
		int highest_interview_rank = 21e8;
		for (int i = 0; i < n; i++) {
			if (applicants[i].interviewRank < highest_interview_rank) {
				highest_interview_rank = applicants[i].interviewRank;
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}