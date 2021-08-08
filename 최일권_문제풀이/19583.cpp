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
	//���� �ð�, ����ð�, ��Ʈ���� ����ð�
	//���� �ð� ��~ ���� �ð����� �⼮ ��Ʈ���� ����ð����� ä�� ����� ���� �ִ� �ֵ鸸 count
	//�ߺ��� ��� X

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
	} // 0�� -> start, 1�� ->end ,2�� ->streaming end

	while (1) {

		string t, n;

		cin >> t >> n;

		if (cin.eof() == true) break;

		int ret = t.find(':');

		int h = stoi(t.substr(0, ret));
		int m = stoi(t.substr(ret + 1, t.length() - ret));

		if ((h == time_h[0] && m <= time_m[0]) || h < time_h[0])//���۽ð� üũ
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
				//�ߺ�üũ�� for���� �� ���� ��� ó���ұ�...?

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