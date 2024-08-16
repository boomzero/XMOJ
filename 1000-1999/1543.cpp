#include <bits/stdc++.h>

using namespace std;
int l1, l2, f[1500][1500] = {{0}};
int a[1500], b[1500];

int main() {
    cin >> l1 >> l2;
    for (int i = 1; i <= l1; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= l2; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (a[i] == b[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[l1][l2] << endl;
    return 0;
}
