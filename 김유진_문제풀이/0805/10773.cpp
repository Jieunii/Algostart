#include <iostream>
#include <stack>
using namespace std;

int k,a;
stack<int> s;
long long res;

int main() {

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a;
		if (a != 0) {
			s.push(a);
		}
		else {
			if(!s.empty()) s.pop();
		}
	}

	while (!s.empty()) {
		res += s.top();
		s.pop();
	}

	cout << res;

	return 0;
}
