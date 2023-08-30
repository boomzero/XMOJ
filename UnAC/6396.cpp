#include <bits/stdc++.h>
using namespace std;
char mfi(char in) {
    in--;
    if (in < 'A') in = 'Z';
    return in;
}
char mf(char in, int i) {
    for (int j = 0; j < i; ++j) {
        in = mfi(in);
    }
    return in;
}
int main() {
    freopen("cipher.in", "r", stdin);
    freopen("cipher.out", "w", stdout);
    string in;
    cin >> in;
    string ans;
    for (int i = 0; i < in.length(); ++i) {
        ans.push_back(mf(in[i], i + 1));
    }
    cout << ans << endl;
    return 0;
}
