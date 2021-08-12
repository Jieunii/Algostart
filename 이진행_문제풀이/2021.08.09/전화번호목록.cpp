#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end()); 

    int booksz = phone_book.size();

    for (int i = 0; i < booksz; i++) {
        for (int j = 0; j < booksz; j++) {
            if (phone_book[i] == phone_book[j]) continue; // 자기자신과 비교

            if (phone_book[i].length() < phone_book[j].length()) { 
                if (phone_book[i] == phone_book[j].substr(0, phone_book[i].length())) {
                    answer = false;
                    break;
                }
            }
        }
        if (answer == false) {
            break;
        }
    }

    return answer;
}

int main() {
    vector<string> phone_book = {
    "12","123","1235","567","88"
    };

    cout << solution(phone_book);

}