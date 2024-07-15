#include <bits/stdc++.h>

using namespace std;
int n, m;
bitset<100002> cd;
char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)

inline int read() {
    int x = 0, f = 1;
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

inline void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    n = read();
    m = read();
    for (int i = 1; i <= m; ++i) {
        int cmd = read();
        if (!cmd) {
            int x = read(), y = read();
            for (int j = x; j <= y; ++j) {
                cd.flip(j);
            }
        } else {
            int x = read(), y = read();
            int a = 0;
            for (int j = x; j <= y; ++j) {
                if (cd[j]) a++;
            }
            write(a);
            putchar('\n');
        }
    }
    return 0;
}
