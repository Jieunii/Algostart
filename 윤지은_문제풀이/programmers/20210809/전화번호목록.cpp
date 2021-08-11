#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
        int a = phone_book[i+1].find(phone_book[i]);
        if(a == 0){
            answer = false;
            return answer;
        }
    }
    return answer;
}