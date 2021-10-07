#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int tc;

struct axios {
	long long y, x;
};

bool comp(axios a, axios b) {
	if (a.x > b.x) return true;
	if (a.x < b.x)return false;

	return false;
}
int main() {

	cin >> tc;
	//12 13, 21 24, 34
	while (tc--) {
		vector<axios> vec;
		for (int i = 0; i < 4; i++) {
			long long y, x;
			cin >> y >> x;
			vec.push_back({ y,x });
		}
		
		sort(vec.begin(), vec.end(), comp);

		long long first_y = vec.back().y;
		long long first_x = vec.back().x;
		vec.pop_back();

		long long second_y = vec.back().y;
		long long second_x = vec.back().x;
		vec.pop_back();

		long long third_y = vec.back().y;
		long long third_x = vec.back().x;
		vec.pop_back();

		long long fourth_y = vec.back().y;
		long long fourth_x = vec.back().x;
		vec.pop_back();

		long long dist1 = pow((first_y - second_y), 2) + pow((first_x - second_x), 2);
		long long dist2 = pow((first_y - third_y), 2) + pow((first_x - third_x), 2);
		long long dist3 = pow((fourth_y - third_y), 2) + pow((fourth_x - third_x), 2);
		long long dist4 = pow((second_y - fourth_y), 2) + pow((second_x - fourth_x), 2);//네변

		long long dist5 = pow((first_y - fourth_y), 2) + pow((first_x - fourth_x), 2);
		long long dist6 = pow((second_y - third_y), 2) + pow((second_x - third_x), 2);//대각선

		if (dist1 == dist2 && dist3 == dist4 && dist5==dist6) cout << 1 << endl;
		else cout << 0 << endl;
	}

	return 0;
}