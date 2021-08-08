#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct form {
	string head;
	string number;
	string tail;
	int idx;
};
bool cmp(form& a, form& b)
{
	if (stricmp(a.head.c_str(),b.head.c_str())<0)return true;
	else if (!stricmp(a.head.c_str(),b.head.c_str()))
	{
		if (stoi(a.number) <stoi( b.number)) return true;
	}
	return false;
}
int main()
{
	vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	vector<form> f_form;
	int n_idx = 0;
	int t_idx = 0;
	
	//sort(files.begin(), files.end());

	for (int i = 0; i < files.size(); i++)
	{
		for (int j = 0; j < files[i].length(); j++)
		{
			if (files[i][j] >= '0'&&files[i][j] <= '9')
			{
				n_idx = j;
				break;
			}
		}

		for (int j = n_idx; j < files[i].length(); j++)
		{
			if ((files[i][j] >= 65 && files[i][j] <= 90) || (files[i][j] >= 97 && files[i][j] <= 122) || (files[i][j] == '-' || files[i][j] == '.'||files[i][j]==' ')) {
				t_idx = j;
				break;
			}
		}

		form temp;
		temp.head = files[i].substr(0, n_idx);
		if (t_idx == 0) {
			temp.number = files[i].substr(n_idx, files[i].length() - n_idx);
			temp.idx = i;
			f_form.push_back(temp);
			continue;
		}
		else {
			temp.number = files[i].substr(n_idx, t_idx - n_idx);
			temp.tail = files[i].substr(t_idx, files[i].length() - t_idx);
			temp.idx = i;
			f_form.push_back(temp);
		}
		t_idx = 0;
		n_idx = 0;
	}
	/*stable_*/sort(f_form.begin(), f_form.end(),cmp);
	for (int i = 0; i < f_form.size()-1; i++)
	{
		for (int j = i + 1; j < f_form.size(); j++)
		{
			if (!stricmp(f_form[i].head.c_str(),f_form[j].head.c_str()))
			{
				int num = stoi(f_form[i].number);
				int num2 = stoi(f_form[j].number);

				if ((num == num2)&&f_form[i].idx>f_form[j].idx) {
					form temp = f_form[i];
					f_form[i] = f_form[j];
					f_form[j] = temp;
				}
					
			}
		}
	}
	vector<string> ans;
	for (int i = 0; i < f_form.size(); i++)
	{
		string temp = "";
		temp.append(f_form[i].head);
		temp.append(f_form[i].number);
		temp.append(f_form[i].tail);

		ans.push_back(temp);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " " ;
	cout << endl;



	return 0;
}