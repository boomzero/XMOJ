#include <iostream>

using namespace std;

int main() {
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    long long l[120] = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> l[i];
    }
    int currDis = 0;
    for (int i = 2; i <= n + 1; ++i) {
        currDis += l[i-1];
        if (currDis > x) {
            cout << i - 1 << endl;
            return 0;
        } else if (currDis == x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n+1 << endl;
    return 0;
}

