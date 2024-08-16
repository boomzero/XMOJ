#include <bits/stdc++.h>

using namespace std;

int lbit(int x) {
    return x & (-x);
}

int t, n, a[50005] = {0}, c[50005] = {0};

int main() {
    scanf("%d", &t);
    for (int ys = 1; ys <= t; ++ys) {
        printf("Case %d:\n", ys);
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[j]);
        }
        for (int j = 1; j <= n; ++j) {
            for (int k = j - lbit(j) + 1; k <= j; ++k) {
                c[j] += a[k];
            }
        }
        while (true) {
            char cmd[10];
            scanf("%s", cmd);
            if (strcmp(cmd, "End") == 0) break;
            if (strcmp(cmd, "Add") == 0) {
                int x, j;
                scanf("%d%d", &x, &j);
                for (int i = x; i <= n; i += lbit(i)) {
                    c[i] += j;
                }
            } else if (strcmp(cmd, "Sub") == 0) {
                int x, j;
                scanf("%d%d", &x, &j);
                for (int i = x; i <= n; i += lbit(i)) {
                    c[i] -= j;
                }
            } else {
                int x, j, a1 = 0, a2 = 0;
                scanf("%d%d", &x, &j);
                x--;
                for (int i = x; i; i -= lbit(i)) {
                    a1 += c[i];
                }
                for (int i = j; i; i -= lbit(i)) {
                    a2 += c[i];
                }
                printf("%d\n", a2 - a1);
            }
        }
    }
    return 0;
}
