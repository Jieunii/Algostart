#include <iostream>
#include <vector>
using namespace std;

int m, l;
vector<int> arr;

// ??
bool can_cut(int cut, int size) {
    int now = 0;
    int cnt = 0;
    for (int i = 0; i <= m; ++i) {
        now += arr[i];
        if (now >= size) {
            cnt++;
            now = 0;
        }
    }
    return cnt >= cut + 1;
}

int main() {
    freopen_s(new FILE*, "test.txt", "r", stdin);
    // input
    int n;
    cin >> n >> m >> l;

    arr.resize(m + 1);
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }
    arr[m] = l;

    // 각 구간의 차이를 arr에 저장함
    for (int i = m; i > 0; --i) {
        arr[i] -= arr[i - 1];
    }

    int t;
    while (n--) {
        cin >> t;

        // 이분 탐색
        int low = 1, high = l; 
        while (high - low > 1) {
            int mid = (low + high) / 2; // 중간 선택
            if (can_cut(t, mid)) { // t번만에 mid만큼 자를 수 있는가?
                low = mid;
            }
            else high = mid;
        }
        cout << low << '\n';
    }
}