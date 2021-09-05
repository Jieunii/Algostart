/*
ATM에서 돈을 뽑기 위해 n명이 줄을 선다
각각 인출하는데 걸리는 시간이 다를 때, 각 사람이 돈을 인출하는데 걸리는 시간의 최소 값을 구해라
*/

/*
각자 인출하는 시간이 다르다 
-> 가장 오래 걸리는 사람이 제일 나중에 인출하는게 앞사람들한테 시간절약
-> 걸리는 시간이 짧은 사람 먼저 인출
=> 오름차순으로 정렬 후 시간 계산 후 출력
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> line;

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		line.push_back(tmp);
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	sort(line.begin(), line.end(), less<int>()); // 오름차순 정렬

	int time = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			time += line[j];
		}
	}

	cout << time;
	return 0;
}