//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//int visited[51] = {};
//string zip = "";
//int unzip(int index){
//	int cnt = 0;
//
//	for (int i = index; i < zip.length(); i++) {
//		if (zip[i] == '(' && !visited[i]) {
//			visited[i] = 1;
//			int mul = zip[i - 1] - '0';
//			cnt--;//�����ִ� �� ���ֱ�
//			cnt += mul * unzip(i + 1); //��� ȣ��� ��ȣ ���� �� ����
//		}
//		else if (zip[i] == ')' && !visited[i]) {
//			visited[i] = 1;
//			return cnt;//���� ��ȣ�� ���� �� ���
//		}
//		else if ((zip[i] >= '0' && zip[i] <= '9' )&& !visited[i]) {
//			visited[i] = 1;
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int main() {
//	
//	int ans = 0;
//	int temp = 0;
//	cin >> zip;
//
//	int ret = unzip(0);
//	
//	cout << ret << endl;
//
//	return 0;
//}