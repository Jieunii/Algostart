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
//			cnt--;//°öÇØÁÖ´Â ¼ö »©ÁÖ±â
//			cnt += mul * unzip(i + 1); //Àç±Í È£Ãâ·Î °ıÈ£ ¾ÈÀÇ ¼ö ¼¼±â
//		}
//		else if (zip[i] == ')' && !visited[i]) {
//			visited[i] = 1;
//			return cnt;//´İÈù °ıÈ£·Î À§ÀÇ ½Ä °è»ê
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