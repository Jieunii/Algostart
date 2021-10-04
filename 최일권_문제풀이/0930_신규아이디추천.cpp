#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string erase_blank(string ans)
{
	string temp;
	char temp_char[1000];
	int k = 0;
	for (int i = 0; i < ans.length(); i++)
	{
		if (ans[i] != ' ')
		{
			temp_char[k] = ans[i];
			k++;
		}
	}
	temp_char[k] = 0;
	temp = temp_char;
	return temp;
}
int check_num(char temp)
{
	if (temp >= 48 && temp <= 57)
		return 1;
	else
		return 0;
}

int check_alpha(char temp) {
	if (temp >= 97 && temp <= 122)
		return 1;
	else
		return 0;
}
string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] >= 65 && new_id[i] <= 90)
			new_id[i] += 32;  //1단계
	}

	for (int i = 0; i < new_id.size(); i++) {
		bool check = false;
		switch (new_id[i]) {
		case '-':
		case '.':
		case '_':
			check = true;
			break;
		default:
			break;
		}

		if (!check && !check_num(new_id[i]) && !check_alpha(new_id[i]))
			new_id[i] = ' ';
	}
	// new_id.erase(remove(new_id.begin(),new_id.end(),' '),new_id.end());

	new_id = erase_blank(new_id);
	//특수문자 지우고 공백 제거 2단계

	for (int i = 0; i < new_id.size(); i++)
	{
		if (new_id[i] == '.')
		{
			for (int j = i + 1; j < new_id.size(); j++)
			{
				if (new_id[j] == '.') {
					new_id[j] = ' ';
					continue;
				}
				if (new_id[j] != '.')
					break;
			}
		}
	}
	//new_id.erase(remove(new_id.begin(),new_id.end(),' '),new_id.end());
	new_id = erase_blank(new_id);
	//3단계
	for (int i = 0; i < new_id.length(); i++) {
		if (i == 0)
		{
			if (new_id[i] == '.') {
				new_id[i] = ' ';
			}
		}
		else if (i == new_id.length() - 1)
		{
			if (new_id[i] == '.')
				new_id[i] = ' ';
		}
	}
	//new_id.erase(remove(new_id.begin(),new_id.end(),' '),new_id.end());
	new_id = erase_blank(new_id);
	//4단계

	if (new_id == "")
		new_id = "a";
	//5단계

	char save[16] = {};
	if (new_id.length() >= 16)
	{
		for (int i = 0; i < 16; i++)
		{
			save[i] = new_id[i];
		}
		save[15] = 0;
		new_id = save;
	}
	if (new_id[new_id.length() - 1] == '.') {
		new_id[new_id.length() - 1] = ' ';
		new_id = erase_blank(new_id);
	}

	//6단계

	if (new_id.length() <= 2)
	{
		while (new_id.length() < 3)
		{
			new_id.append(1, new_id[new_id.length() - 1]);
		}
	}
	answer = new_id;
	return answer;
}