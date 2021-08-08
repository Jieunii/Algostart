#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct fileNode {
	string head;
	string number;
	string tail;
};

// fileNode간의 순서 정렬
/* https://hsdevelopment.tistory.com/362 구조체의 벡터 정렬*/
bool cmp(const fileNode& a, const fileNode& b) {
	// 1. Head는 사전순으로 정렬 (대소문자 구분 없음)
	string aHead, bHead;
	// 싹다 대문자로 변환 후 비교?
	
	if (a.head < b.head) return true;

	else { // 2. number는 int 변환 후 오름차순 정렬
		int aNum = stoi(a.number);
		int bNum = stoi(b.number);

		if (aNum < bNum) return true;

		else { // 3. 그래도 같으면 입력순으로 정렬
			// ?? 
		}
	}
}

// 문자열에서 첫 숫자의 위치를 반환하는 함수
int findNum(string str, int index) {
	int strSize = str.size();

	for (int i = index; i < strSize; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			return i;
		}
	}

	return -1;
}

void splitAndPush(vector<fileNode>* fn, string str) {

	int a = findNum(str, 1); // 숫자 앞까지 자르기
	int b = str.find('.'); // .확장자 앞까지 자르기

	string tmpHead;
	string tmpNumber;
	string tmpTail;

	// tail 존재
	if (b != -1) {
		tmpHead = str.substr(0, a);
		tmpNumber = str.substr(a, b - a);
		tmpTail = str.substr(b);
	}
	// tail 없음
	else {
		tmpHead = str.substr(0, a);
		tmpNumber = str.substr(a);
		tmpTail = "";
	}
	
	fileNode tmp = { tmpHead, tmpNumber, tmpTail };

	fn->push_back(tmp);

	return;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;

	// 1. files[i]를 head, number, tail로 쪼갠후, fildNode로 만들어 fileNode벡터에 넣음
	vector<fileNode> fn;
	int fileSize = files.size();
	for (int i = 0; i < files.size(); i++) {
		splitAndPush(&fn, files[i]);
	}

	// 2. 이 fn를 정렬 후, string으로 만들어 answer에 전달
	sort(fn.begin(), fn.end(), cmp);

	int fnSize = fn.size();

	for (int i = 0; i < fnSize; i++) {
		cout << fn[i].head << " " << fn[i].number << " " << fn[i].tail << endl;
	}


	return answer;
}

int main() {

	vector<string> files = {
		"F-5 Freedom Fighter", 
		"B-50 Superfortress", 
		"A-10 Thunderbolt II", 
		"F-14 Tomcat",

	};

	vector<string> res;

	res = solution(files);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	

	return 0;
}