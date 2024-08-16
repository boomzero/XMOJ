#include <bits/stdc++.h>

using namespace std;

char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)

int read() {
    __int128 x = 0, f = 1;
    char ch = nc();
    while (ch < 48 || ch > 57) {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= 48 && ch <= 57)
        x = x * 10 + ch - 48, ch = nc();
    return x * f;
}

void write(__int128 x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}


int main() {
    __int128 total, n;
    total = read();
    n = read();
    __int128 a[400] = {0}, dp[1005] = {1};
    for (__int128 i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for (__int128 i = 1; i <= n; ++i) {
        for (__int128 j = a[i]; j <= total; ++j) {
            dp[j] += dp[j - a[i]];
        }
    }
    write(dp[total]);
    return 0;
}

