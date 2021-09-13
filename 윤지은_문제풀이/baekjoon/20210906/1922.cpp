#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int v1, v2, cost;
};
vector<edge> network;
int parent[1001];

bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}

int Find(int idx) {
	if (parent[idx] == idx) return idx;
	return parent[idx] = Find(parent[idx]);
}

void Union(int v1, int v2) {
	int p1 = Find(v1);
	int p2 = Find(v2);
	parent[p1] = p2;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
    // 자기자신으로 가는건 제외
		if (v1 != v2) network.push_back({ v1, v2, cost });
	}
  // 비용이 적은 순으로 sort
	sort(network.begin(), network.end(), cmp);

  // 크루스칼 알고리즘
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	int result = 0;
	for (int i = 0; i < network.size(); i++) {
		if (Find(network[i].v1) != Find(network[i].v2)) {
			Union(network[i].v1, Find(network[i].v2));
			result += network[i].cost;
		}
	}
	cout << result;
	return 0;
}