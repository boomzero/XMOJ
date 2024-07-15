#include <bits/stdc++.h>

#define int unsigned long long
using namespace std;
string s1, s2;
unsigned long long base = 1e9 + 7;
unsigned long long b[1000009], h[1000009];

int hashs(string str) {
    int ans = 0;
    int p = 0;
    for (unsigned long long i: str) {
        ans = ans * base + i - 'A' + 1;
        p++;
    }
    return ans;
}

signed main() {
    b[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        b[i] = b[i - 1] * base;
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        int ans = 0;
        int s1h = hashs(s1);
        for (int i = 0; i < s2.length(); ++i) {
            h[i + 1] = h[i] * base + (unsigned long long) (s2[i] - 'A' + 1);
        }
        for (int i = 0; i <= s2.length() - s1.length(); ++i) {
            if (h[i + s1.length()] - h[i] * b[s1.length()] == s1h) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
