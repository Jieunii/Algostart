#include <iostream>
#include <cstring> //memset
using namespace std;

int n, cnt;
int student[100001];
bool used[100001];
bool done[100001]; //�湮�� �������� üũ


void dfs(int start){

    used[start] = true;

    int next = student[start];

    if (!used[next]) {
        dfs(next);
    }

    //�̹� �湮������ �湮�� ���� ��尡 �ƴ϶�� ����Ŭ
    else if (!done[next]){
        //���� cnt
        cnt++;
        for (int i = next; i != start; i = student[i]) {
            cnt++;
        }
    }

    //���� ����Ŭ���� Ȯ���� �ʿ� ���� ǥ��
    done[start] = true;

}



int main(void)

{

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++){

        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> student[j];
        }

        //�ʱ�ȭ
        memset(used, false, sizeof(used));
        memset(done, false, sizeof(done));
        cnt = 0;

        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                dfs(j);
            }
        }

        cout << n - cnt << "\n";

    }

    return 0;

}