#include <iostream>

using namespace std;

char st[100000];
int top = 0;

void pop() {
    if (top > -1) {
        top--;
    }
}

void push(char ch) {
    st[top] = ch;
    top++;
}

int main(void) {

    int k, n;

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> n;

        if (n == 0) {
            pop();
        }
        else {
            push(n);
        }
    }

    int result = 0;

    for (int i = 0; i<top; i++) {
        result += st[i];
    }

    cout << result;

    return 0;
}