#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<string> phone_book = { "119", "97674223", "1195524421" };
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size(); i++)
	{
		cout << phone_book[i] << " ";
	}
	cout << endl;

	return 0;
}