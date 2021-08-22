// vector에 p를 넣고,
// reverse호출시 알고리즘 라이브러리의 reverse함수 사용-> 시간초과!!
// 덱 이용

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [x_1, ... , x_n] 형태의 str을
// arr(n) 벡터에 숫자만 분류해서 저장한다
void parseArr(vector<string>* arr, string str) {
	if (arr->size() == 0) return; // 원소가 없는경우
	
	string tmp = str.substr(1, str.length() - 2); 
	tmp += ",";

	// 1,2,3,4,

	int a = 0;
	int b = 0;
	int idx = 0;

	while (1) {
		a = tmp.find(",", a);
		if (a == -1) break;

		if (idx == 0) { // 첫번째 원소 넣기
			arr->at(idx) = tmp.substr(0,a); 
			idx++;
			continue;
		}

		b = tmp.find(",", a+1);
		if (b == -1) break;

		arr->at(idx) = tmp.substr(a+1, b-a-1);
		idx++;

		a = b;
	}
}

void Reverse(vector<string>* arr) {

	reverse(arr->begin(), arr->end());

	return;
}

void DropFirst(vector<string>* arr) {

	if (arr->size() <= 0) {
		cout << "error" << '\n';
		return;
	}
	arr->erase(arr->begin());

	return;
}

void PrintArr(vector<string>* arr) {
	int arr_size = arr->size();
	if (arr_size == 0) return;

	string res = "[";
	for (int i = 0; i < arr_size; i++) {
		res += arr->at(i) + ",";
		
	}
	res.erase(res.length() - 1);
	res += "]";

	cout << res << '\n';

	return;
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	string p;
	string tmp;

	cin >> T;

	while (T--) {
		cin >> p >> n;
		cin >> tmp;

		vector<string> arr(n);
		parseArr(&arr, tmp);

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') { Reverse(&arr); }
			else if (p[i] == 'D') { DropFirst(&arr); }
		}

		PrintArr(&arr);
	}

	
	return 0;
}