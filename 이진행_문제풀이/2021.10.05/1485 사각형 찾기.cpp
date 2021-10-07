#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int y;
	int x;
};

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	int T;
	cin >> T;
	while (T--) {
		vector<Point> point;
		vector<int> edge;

		int y, x;
		for (int i = 0; i < 4; i++) {
			cin >> y >> x;
			point.push_back({ y, x });
		}
		
		// 각 점의 거리 구하기
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				int line = abs(point[i].y - point[j].y) + abs(point[i].x - point[j].x);
				edge.push_back(line);
			}
		}

		// 거리가 가장 긴 앞 두개가 대각선의 길이
		sort(edge.begin(), edge.end(), greater<int>());

		// 두 대각선의 길이와, 네 변의 길이가 모두 같다면 정사각형
		if ((edge[0] == edge[1]) && (edge[2] == edge[3] && edge[3] == edge[4] && edge[4] == edge[5])) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}


	return 0;
}