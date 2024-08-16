#include <bits/stdc++.h>

using namespace std;
int n, k, expv;
int grid[1005][1005], curr[1005][1005];
char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)

int read() {
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

int main() {
    freopen("corndolly.in", "r", stdin);
    freopen("corndolly.out", "w", stdout);
    n = read(), k = read();
    for (int i = 1; i <= k; i++) {
        int r = read(), c = read();
        grid[r][c] = true;
        if (grid[r][c]) {
            int nr = r, nc;
            curr[r][c]++;
            while (nr > 1) { //pb
                nr--;
                curr[nr][c]++;
            }
            nr = r;
            while (nr < n) { //pb
                nr++;
                curr[nr][c]++;
            }
            nc = c;
            while (nc > 1) { //pb
                nc--;
                curr[r][nc]++;
            }
            nc = c;
            while (nc < n) { //pb
                nc++;
                curr[r][nc]++;
            }
            nr = r, nc = c;
            while (nr > 1 && nc > 1) {
                nc--;
                nr--;
                curr[nr][nc]++;
            }
            nr = r, nc = c;
            while (nr < n && nc < n) {
                nc++;
                nr++;
                curr[nr][nc]++;
            }
            nr = r, nc = c;
            while (nr > 1 && nc < n) {
                nc++;
                nr--;
                curr[nr][nc]++;
            }
            nr = r, nc = c;
            while (nr < n && nc > 1) {
                nc--;
                nr++;
                curr[nr][nc]++;
            }
            expv++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; j++) {
            if (curr[i][j] >= expv) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
