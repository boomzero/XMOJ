#include <bits/stdc++.h>

using namespace std;
int f[1500][1500] = {{0}};

int main() {
    int l1, l2;
    string a, b;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    l1 = a.length(), l2 = b.length();
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (a[i - 1] == b[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }
    }
    cout << l1 - f[l1][l2] << endl;
    return 0;
}

