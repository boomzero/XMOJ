#include <bits/stdc++.h>

using namespace std;
int n, a[1000] = {0};

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, [](int a, int b) {
        string i = to_string(a), j = to_string(b);
        return i + j > j + i;
    });
    for (int i = 1; i <= n; ++i) {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
