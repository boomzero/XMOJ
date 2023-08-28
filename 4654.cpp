#include <bits/stdc++.h>

using namespace std;
#define int long long

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}


void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

#undef int
long long n, a[100005] = {0};
long long sum = 0;
long long ans = 0;
bool c[100005] = {false};

int main() {
    freopen("product.in", "r", stdin);
    freopen("product.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        c[i] = read();
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i]) {
            sum -= a[i];
            ans += a[i] * (sum);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (!c[i] && !c[i + 1]) {
            ans += a[i] * a[i + 1];
        }
    }
    if (!c[1] && !c[n]) {
        ans += a[1] * a[n];
    }
    write(ans);
    return 0;
}

