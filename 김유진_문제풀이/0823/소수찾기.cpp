#include <string>
#include <vector>
#include <math.h> //sqrt: ������
#include <unordered_map>
using namespace std;
int used[10];
int len;
int cnt;
unordered_map<int, int> um;

//�����佺�׶��� ü
bool prime_check(int num) {
    if (num == 0 || num == 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int level, int depth, string res, string numbers) {
    if (level == depth) {
        int num = stoi(res);

        //�Ҽ�üũ�ߴ� ���ڸ� return
        if (um[num] > 0) return;
        um[num] = 1;
        if (prime_check(num)) {
            cnt++;
        }
        return;
    }
    for (int i = 0; i < len; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            dfs(level + 1, depth, res + numbers[i], numbers);
            used[i] = 0;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    len = numbers.size();

    //���� � ��������
    for (int i = 1; i <= len; i++) {
        dfs(0, i, "", numbers);
    }
    answer = cnt;
    return answer;
}