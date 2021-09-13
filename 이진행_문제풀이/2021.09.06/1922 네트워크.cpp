/* n개의 컴퓨터, m개의 연결할 수 있는 선의 수
* m개의 start, end, cost 가 주어짐
* 이때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력
*/

/* 크루스칼 알고리즘 문제
* 1. cost순으로 정렬.
* 2. 선택한 노드는 union-find를 통해 그룹화
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[1001];
struct node {
	int start;
	int end;
	int cost;
};

vector<node> network;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		network.push_back({ start, end, cost });
	}
}

bool Compare(node front, node back) {
	// 1. cost순 오름차순
	if (front.cost < back.cost) return true;
	if (front.cost > back.cost) return false;
	// 2. start순 오름차순
	if (front.start < back.start) return true;
	if (front.start > back.start) return false;
	// 3. end순 오름차순
	return front.end < back.end;
}

int FindBoss(int target) {
	if (arr[target] == 0) { return target; }
	int boss = FindBoss(arr[target]);
	arr[target] = boss;
	return boss;
}

void SetUnion(int a, int b) {
	int aboss = FindBoss(a);
	int bboss = FindBoss(b);
	if (aboss == bboss) return; // 이미 같은그룹이라면 종료
	arr[bboss] = aboss;
}


int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	// 1. 정렬
	sort(network.begin(), network.end(), Compare);

	// 2. 네트워크에 속하지 않은 경우에만 넣는다
	int total = 0;
	for (int x = 0; x < network.size(); x++) {
		if (FindBoss(network[x].start) != FindBoss(network[x].end)) {
			SetUnion(network[x].start, network[x].end); //연결
			total += network[x].cost;
		}
	}

	cout << total;

	return 0;
}