#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int md = 1000000007;

int find(char firstChar, char secondChar, char thirdChar) {
    int a = 0, ab = 0, abc = 0;
    for (char c: s) {
        if (c == thirdChar) {
            abc += ab;
        }
        if (c == secondChar) {
            ab += a;
        }
        if (c == firstChar) {
            a++;
        }
        a %= md;
        ab %= md;
        abc %= md;
    }
    return abc;
}

int qpow(int a, int pow, int mod) {
    if (pow == 0) return 1;
    int res = qpow(a, pow / 2, mod) % mod;
    if (pow % 2 == 0) {
        return res * res % mod;
    }
    return res * res * a % mod;
}

signed main() {
    freopen("e.in", "r",stdin);
    freopen("e.out", "w",stdout);
    cin >> s;
    int ans = 0;
    int q = 0;
    for (char i: s) {
        if (i == '?') q++;
    }
    ans += find('A', 'B', 'C') * qpow(3, q, md) % md;
    ans += find('A', 'B', '?') * qpow(3, q - 1, md) % md;
    ans += find('A', '?', '?') * qpow(3, q - 2, md) % md;
    ans += find('?', '?', '?') * qpow(3, q - 3, md) % md;
    ans += find('A', '?', 'C') * qpow(3, q - 1, md) % md;
    ans += find('?', 'B', 'C') * qpow(3, q - 1, md) % md;
    ans += find('?', '?', 'C') * qpow(3, q - 2, md) % md;
    ans += find('?', 'B', '?') * qpow(3, q - 2, md) % md;
    cout << ans % md << endl;
    return 0;
}

