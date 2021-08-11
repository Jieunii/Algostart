#include <iostream>
using namespace std;

int n, m;
int visited[10];
int res[10];

void go(int cnt) {
	//m자리 수 모두 선택되었으면
	if (cnt == m) {
		//출력
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";

		return;
	}

	//m자리수 선택되지 않았으면
	for (int i = 1; i <= n; i++) { //1~n의 수
		
		//이전에 선택된 적이 없다면
		if (!visited[i]) {
			
			//지금 선택할꺼니까 선택되었다고 표시
			visited[i] = 1;
			
			//cnt 자리에 선택한 값 넣기
			res[cnt] = i;

			//cnt 다음 자리 선택하러가기
			go(cnt + 1);

			//return 되면서 cnt자리값 빠져나갔으니까 선택하지않았다고 다시 표시
			visited[i] = 0;
		}
	}
}

int main() {

	cin >> n >> m;
	go(0);
	return 0;
}
