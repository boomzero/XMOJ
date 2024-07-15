#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
const int md = 1000000007;
long long x = 1, y = 1, n, m;

long long ksm(long long b, long long a) {
    long long ans = 1;
    while (a) {
        if (a & 1) ans = (ans * b) % md;
        a /= 2;
        b = (b * b) % md;
    }
    return ans;
}

int main() {
    freopen("spp.in", "r", stdin);
    freopen("spp.out", "w", stdout);
    //scanf("%lld%lld", &n, &m);
    cin >> n >> m;
    long long t = 0;
    if (n < m) {
        t = n;
        n = m;
        m = t;
    }
    for (long long i = n + 2; i <= n + m + 1; i++) {
        x = (x * i) % md;
    }
    for (long long i = 1; i <= m; i++) {
        y = (y * i) % md;
    }
    cout << (x * ksm(y, md - 2) % md + n) % md << endl;
    return 0;
}
