#include <bits/stdc++.h>

using namespace std;
typedef __int128 ii;
__int128 n, m, x, dp[15][15] = {{0}};

inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

ii min(__int128 a, __int128 b) {
    if (a > b) return b;
    else return a;
}

ii max(ii a, ii b) {
    if (a > b) return a;
    else return b;
}

inline void write(__int128 num) {
    if (num < 0) {
        putchar('-');
        num = -num;
    }
    if (num > 9)
        write(num / 10);
    putchar(num % 10 + '0');
}

string tsans;

string to_string(__int128 in) {
    bool neg = false;
    if (in < 0) {
        neg = true;
        in *= -1;
    }
    while (in > 9) {
        tsans.insert(tsans.begin(), in % 10 + '0');
        in /= 10;
    }
    tsans.insert(tsans.begin(), in % 10 + '0');
    if (neg) tsans.insert(tsans.begin(), '-');
    return tsans;
}

__int128 stoi128(string in) {
    __int128 ans = 0, fx = 1;
    if (in[0] == '-') {
        fx = -1;
        in.erase(in.begin());
    }
    for (char i: in) {
        ans *= 10;
        ans += i - '0';
    }
    return ans * fx;
}

ii trim(ii s, ii e) {
    string proc = to_string(x);
    proc.erase(e, proc.length() - e);
    proc.erase(0, s - 1);
    return stoi128(proc);
}

int main() {
    n = read();
    m = read();
    x = read();
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = trim(1, i);
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= min(i - 1, m); ++j) {
            for (int k = j; k < i; ++k) {
                dp[i][j] = max(dp[i][j], dp[k][j - 1] * trim(k + 1, i));
            }
        }
    }
    write(dp[n][m]);
    return 0;
}
