/*
멀티탭 구멍 개수 n개, 전기용품의 사용 순서 k개가 주어진다
하나씩 플러그를 빼는 최수한의 횟수 출력
*/

/*
1. 비어있지 않고, 멀티탭에도 꽂혀있지 않은 경우, 
 남은 작업들을 확인하며 '최소 작업회수를 가진' 전자제품의 콘센트를 뽑는 방법 사용 
 반례) 2 15 // 3 2 1 2 1 2 1 2 1 3 3 3 3 3 3 -> 1번 방법으로 하면 idx = 2일때, 3이 아니라 2를 뽑아 엄청 비효율적임

2. 추후 사용이 가장 늦는, 또는 앞으로 사용하지 않을 전자제품의 콘센트를 뽑는 방법 사용
 -> 꽂혀있는 기기들 중, 다시 사용되지 않는 기기를 먼저 제거한다
 -> 모두 사용될 경우, 그 중에서 가장 늦게 사용되는 기기를 제거한다
*/

#include <iostream>
#include <vector>

using namespace std;

int n;	// 멀티탭 구멍 개수
int k;	// 총 사용 회수
vector<int> job;	// 전기용품 이름

vector<int> multitab; // 멀티탭
int top = 0;

void Input() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int input;
		cin >> input;
		job.push_back(input);
	}

	multitab.assign(n, 0);
}

bool IsMultitabFull() {
	if (top == n) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	int idx = 0;
	int result = 0;
	while (idx < k) {
		int now = job[idx];

		// 1. 꽂으려는 전자제품이 이미 꽂혀있는 경우
		bool flag = false;
		for (int i = 0; i < multitab.size(); i++) {
			if (now == multitab[i]) {
				flag = true;
				break;
			}
		}

		if (flag == true) {
			idx++;
			continue;
		}

		// 2. 멀티탭이 비어있는 경우
		if (IsMultitabFull() == false) { // 자리가 있다면 꼽고 다음으로
			multitab[top] = now;
			top++;

			idx++;
			continue;
		}

		// 3. 추후 사용이 가장 늦는, 또는 앞으로 사용하지 않을 전자제품의 콘센트를 뽑는 방법 사용
		int pull_idx = -1;
		int max_cnt = 0;
		for (int i = 0; i < multitab.size(); i++) {

			int after_cnt = 0; // 몇번째 뒤에 나옴
			for (int j = idx; j < job.size(); j++) { // 현재 작업 이후만 확인
				// 현재 작업이 이후 언제 다시 나오는지 확인
				if (multitab[i] == job[j]) {
					break;
				}
				after_cnt++;
			}
			// multitab[i]를 다시 사용하는 경우가 없을 경우, 얘를 뽑고 이자리에 삽입
			if (after_cnt == 0) {
				pull_idx = i;
				break;
			}

			// 꽂혀있는 애들이 모두 한번 이상씩 쓸 경우, 그중 가장 '늦게' 사용되는 전자제품을 뽑고 now를 꽂음
			if (max_cnt < after_cnt) {
				max_cnt = after_cnt;
				pull_idx = i; // 빼야할 인덱스를 저장
			}
		}
		multitab[pull_idx] = now;
		result++;
		idx++;
	}

	cout << result;

	return 0;
}
