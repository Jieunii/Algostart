#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//int isValid(char n)
//{
//	if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122) || n == '.' || n == '_' || n == '-'||(n>='0'&&n<='9'))
//		return 1;
//	return 0;
//}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S, E, Q;
	int valid = 1;
	int ans = 0;

	cin >> S >> E >> Q;
	//시작 시간, 종료시간, 스트리밍 종료시간
	//시작 시간 전~ 시작 시간까지 출석 스트리밍 종료시간까지 채팅 기록이 남아 있는 애들만 count
	//중복은 허용 X

	vector<string> time = { S,E,Q };
	unordered_set<string> hs;
	int time_h[3];
	int time_m[3];

	for (int i = 0; i < 3; i++)
	{
		int ret = time[i].find(':');
		if (ret == -1)continue;
		time_h[i] = stoi(time[i].substr(0, ret));
		time_m[i] = stoi(time[i].substr(ret+1, time[i].length()-ret));
	} // 0번 -> start, 1번 ->end ,2번 ->streaming end

	while (1) {

		string t, n;

		cin >> t >> n;

		if (cin.eof() == true) break;

		int ret = t.find(':');

		int h = stoi(t.substr(0, ret));
		int m = stoi(t.substr(ret + 1, t.length() - ret));

		if ((h == time_h[0] && m <= time_m[0]) || h < time_h[0])//시작시간 체크
		{
			/*int flag = 1;*/
		/*	for(int i=0;i<n.length();i++)
				if (!isValid(n[i]))
				{
					flag = 0;
					break;
				}*/

				/*if (flag) {*/
			//if (attend.size() == 0)
			//attend.push_back(n);
			hs.insert(n);
			//else
			//{
				/*int in = 0;
				for (int i = 0; i < attend.size(); i++) {
					if (n == attend[i]) {
						in = 1;
						break;
					}
				}
				if (!in) {
					in = 0;
					attend.push_back(n);
				}*/
				//중복체크를 for문을 안 쓰고 어떻게 처리할까...?

			//}
		}
		//}
		//attend.erase(unique(attend.begin(), attend.end()), attend.end());

		if (time_h[1] == time_h[2])
		{
			if ((h == time_h[1]) && (m >= time_m[1] && m <= time_m[2]))
			{
				/*for (int i = 0; i < attend.size(); i++)
				{
					if (n == attend[i])
					{
						attend[i] = "ssafy";
						ans++;
						break;
					}
				}*/
				auto itr = hs.find(n);
				if (itr != hs.end()) {
					ans++;
					hs.erase(hs.find(n));
				}
			}

		}
		else if (time_h[1] < time_h[2])
		{
			if (h == time_h[1] && m >= time_m[1])
			{
				/*for (int i = 0; i < attend.size(); i++)
				{
					if (n == attend[i])
					{
						attend[i] = "ssafy";
						ans++;
						break;
					}
				}*/
				auto itr = hs.find(n);
				if (itr != hs.end()) {
					ans++;
					hs.erase(hs.find(n));
				}
			}
			else if ((h > time_h[1] && h < time_h[2]))
			{
				/*for (int i = 0; i < attend.size(); i++)
				{
					if (n == attend[i])
					{
						attend[i] = "ssafy";
						ans++;
						break;
					}
				}*/
				auto itr = hs.find(n);
				if (itr != hs.end()) {
					ans++;
					hs.erase(hs.find(n));
				}
			}
			else if (h == time_h[2])
			{
				if (m <= time_m[2])
				{
					/*for (int i = 0; i < attend.size(); i++)
					{
						if (n == attend[i])
						{
							attend[i] = "ssafy";
							ans++;
							break;
						}
					}*/
					auto itr = hs.find(n);
					if (itr != hs.end()) {
						ans++;
						hs.erase(hs.find(n));
					}
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}