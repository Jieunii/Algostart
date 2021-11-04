#include <queue>
#include <iostream>
using namespace std;
#define max_ 202

int n, k;
int a[max_] = {};
queue<int> robot;
int locate[max_] = {};

int start_locate;
int end_locate;

int count_0() {
	int cnt = 0;

	for (int i = 1; i <= 2 * n; i++)
		if (a[i] == 0) cnt++;

	return cnt;
}

void input() {
	cin >> n >> k;

	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}
	start_locate = 1;
	end_locate = n;
}

void move_belt() {
	//값을 모두 변경해 줘야 할까?
	//1 -> 2 , 2->3 .... 2n -> 1
	//시작 위치와 내릴 위치만 변경
	start_locate--;
	end_locate--;
	
	if (start_locate == 0) start_locate = 2 * n;
	if (end_locate == 0) end_locate = 2 * n;
}

void move_robot() {

	int before_size = robot.size();

	for(int i=0;i<before_size;i++){

		int cur = robot.front();
		robot.pop();

		if (cur == end_locate) {
			locate[cur] = 0;
			continue;
		}
		int next = cur + 1;
		if (next > 2 * n) next = 1;

		if (locate[next] == 0 && a[next] > 0) {
			a[next]--;
			locate[cur] = 0;
			if (next == end_locate) continue;
			locate[next] = 1;
			robot.push(next);
		}
		else robot.push(cur);
	}

}

void put_robot() {
	if (locate[start_locate] == 0 && a[start_locate] > 0) {
		locate[start_locate] = 1;
		a[start_locate]--;
		robot.push(start_locate);
	}
}

int main() {
	int ans = 0;

	input();

	while (1) {
		//처음에 컨테이너 회전
		//로봇 이동
		//올리는 위치가 내구도가 0이 아니면 로봇 올림
		ans++;

		move_belt();
		move_robot();
		put_robot();

		int cnt = count_0();

		if (cnt >= k) break;
	}

	cout << ans << endl;
	return 0;
}