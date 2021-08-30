#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>

#define MAX 10000000 // 최대 7자리

using namespace std;

bool prime[MAX];

int card[10]; // 숫자 카드
int path[8];


void Init(string str) {
    // 1. 1~9,999,999 까지 소수를 미리 찾아놓음
    memset(prime, true, sizeof(prime));

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i < sqrt(MAX); i++) {
        if (prime[i] == true) {
            for (int j = i * 2; j < MAX; j = j + i) {
                prime[j] = false;
            }
        }
    }

    // 2. dat를 이용해 카드 개수 세놓기
    for (int i = 0; i < str.length(); i++) {
        card[str[i] - '0']++;
    }
}

// 소수 판별 함수
bool IsPrime(int n) {
    if (prime[n] == true) {
        return true;
    }
    else {
        return false;
    }
}

void dfs(int Lv, int max,int* answer) {

    if (Lv == 1 && path[0] == 0) { return; }
    if (Lv == max) {
        string res;
        
        for (int i = 0; i < Lv; i++) {
            res += to_string(path[i]);
        } 

        if ( IsPrime(stoi(res)) == true ) {
            *answer = *answer + 1;
        }

        return;
    }

    // 0~9에서 남은 카드 한장 뽑아서 dfs
    for (int x = 0; x <= 9; x++) {
        if (card[x] <= 0) { continue; } 

        path[Lv] = x;
        card[x]--;

        dfs(Lv + 1, max, answer);

        card[x]++;
        path[Lv] = 0;
    }
}

/*
1. 먼저 최대 7자리 숫자가 들어오니 1~9,999,999까지 소수를 먼저 찾아놓는다 -> 에라토스테네스 체 사용
2. 이후 숫자를 입력받고 이를 DAT를 이용해 각 숫자가 몇개 들어왔는지 카운트한다
3. 한자리수 숫자 만들기, 두자리 수 숫자 만들기, ... , 입력받은 숫자와 길이가 같은 숫자 만들기
 -> 이를 DFS를 통해 만들어본다
4. 만들어진 숫자가 소수인지 확인하고 소수라면 answer 증가
*/

int solution(string numbers) {
    
    Init(numbers);

    int answer = 0;

    for (int i = 1; i <= numbers.length(); i++) {
       dfs(0, i, &answer);
    }
   
    return answer;
}


int main() {
    string str;

    cin >> str;

    cout << solution(str);

	return 0;
}