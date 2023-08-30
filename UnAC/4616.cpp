#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main() {
    cin >> n;
    int i = 0, c = 2;
    if (n > 8) {
        cout << (n - 3) * 10 << endl;
        return 0;
    }
    while (i < n) {
        c++;
        int rst = 5 * c;
        if (rst % 10 > 0 && rst >= 55) continue;
        else i++;
    }
    cout << 5 * c << endl;
    return 0;
}
