#include <iostream>
#include <cstring> //memset
using namespace std;

int n, cnt;
int student[100001];
bool used[100001];
bool done[100001]; //방문이 끝났는지 체크


void dfs(int start){

    used[start] = true;

    int next = student[start];

    if (!used[next]) {
        dfs(next);
    }

    //이미 방문했지만 방문이 끝난 노드가 아니라면 사이클
    else if (!done[next]){
        //팀원 cnt
        cnt++;
        for (int i = next; i != start; i = student[i]) {
            cnt++;
        }
    }

    //다음 사이클부터 확인할 필요 없게 표시
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

        //초기화
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